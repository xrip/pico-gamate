#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cstring>
#include <pico.h>
#include <pico/stdlib.h>
#include <pico/multicore.h>
#include <hardware/clocks.h>
#include <hardware/vreg.h>
#include <hardware/flash.h>
#include <hardware/watchdog.h>

#include <graphics.h>
#include "audio.h"

#include "nespad.h"
#include "ff.h"
#include "ps2kbd_mrmltr.h"

#include "m6502/m6502.h"
#include "gamate/vdp.h"
#include "gamate/bios.h"
#include "emu2149/emu2149.h"
#include "hway/AY_PIO_595.h"

#define HOME_DIR "\\GAMATE"
extern char __flash_binary_end;
#define FLASH_TARGET_OFFSET (((((uintptr_t)&__flash_binary_end - XIP_BASE) / FLASH_SECTOR_SIZE) + 4) * FLASH_SECTOR_SIZE)
static const uintptr_t rom = XIP_BASE + FLASH_TARGET_OFFSET;


uint8_t * ROM = (uint8_t *) rom;

alignas(4) uint8_t RAM[1024] = { 0xFF };
extern uint8_t VRAM[16384];

static M6502 cpu;
static PSG psg;

static int bank0_offset = 0;
static int bank1_offset = 0x4000;
static uint8_t protection = 0;

char __uninitialized_ram(filename[256]);
static uint32_t __uninitialized_ram(rom_size) = 0;

static FATFS fs;
bool reboot = false;
bool limit_fps = true;
semaphore vga_start_semaphore;

uint8_t SCREEN[150][160];

typedef struct __attribute__((__packed__)) {
    uint8_t version;
    bool swap_ab;
    bool aspect_ratio;
    uint8_t ghosting;
    uint8_t palette;
    uint8_t save_slot;
    uint32_t rgb0;
    uint32_t rgb1;
    uint32_t rgb2;
    uint32_t rgb3;
} SETTINGS;

SETTINGS settings = {
    .version = 1,
    .swap_ab = false,
    .aspect_ratio = false,
    .ghosting = 4,
    .palette = 0,
    .save_slot = 0,
    .rgb0 = 0x7bc77b,
    .rgb1 = 0x52a68c,
    .rgb2 = 0x2e6260,
    .rgb3 = 0x0d322e
};

struct input_bits_t {
    bool a: true;
    bool b: true;
    bool select: true;
    bool start: true;
    bool right: true;
    bool left: true;
    bool up: true;
    bool down: true;
};

static input_bits_t keyboard = { false, false, false, false, false, false, false, false };
static input_bits_t gamepad1_bits = { false, false, false, false, false, false, false, false };
static input_bits_t gamepad2_bits = { false, false, false, false, false, false, false, false };

bool swap_ab = false;

void nespad_tick() {
    nespad_read();
    if (((nespad_state & DPAD_LEFT) && (nespad_state & DPAD_RIGHT)) ||
        ((nespad_state & DPAD_DOWN) && (nespad_state & DPAD_UP))
    ) {
        gamepad1_bits = keyboard;
        return;
    }

    uint8_t controls_state = 0;

    if (settings.swap_ab) {
        gamepad1_bits.b = keyboard.a || (nespad_state & DPAD_A) != 0;
        gamepad1_bits.a = keyboard.b || (nespad_state & DPAD_B) != 0;
    } else {
        gamepad1_bits.a = keyboard.a || (nespad_state & DPAD_A) != 0;
        gamepad1_bits.b = keyboard.b || (nespad_state & DPAD_B) != 0;

    }

    gamepad1_bits.select = keyboard.select || (nespad_state & DPAD_SELECT) != 0;
    gamepad1_bits.start = keyboard.start || (nespad_state & DPAD_START) != 0;
    gamepad1_bits.up = keyboard.up || (nespad_state & DPAD_UP) != 0;
    gamepad1_bits.down = keyboard.down || (nespad_state & DPAD_DOWN) != 0;
    gamepad1_bits.left = keyboard.left || (nespad_state & DPAD_LEFT) != 0;
    gamepad1_bits.right = keyboard.right || (nespad_state & DPAD_RIGHT) != 0;


    if (gamepad1_bits.up) controls_state|=0x08;
    if (gamepad1_bits.down) controls_state|=0x04;
    if (gamepad1_bits.left) controls_state|=0x02;
    if (gamepad1_bits.right) controls_state|=0x01;
    if (gamepad1_bits.a) controls_state|=0x20;
    if (gamepad1_bits.b) controls_state|=0x10;
    if (gamepad1_bits.start) controls_state|=0x80;
    if (gamepad1_bits.select) controls_state|=0x40;
    // if (gamepad1_bits.down) smsSystem|=INPUT_SOFT_RESET;
    // if (gamepad1_bits.down) smsSystem|=INPUT_HARD_RESET;
}

static bool isInReport(hid_keyboard_report_t const* report, const unsigned char keycode) {
    for (unsigned char i: report->keycode) {
        if (i == keycode) {
            return true;
        }
    }
    return false;
}

static volatile bool altPressed = false;
static volatile bool ctrlPressed = false;
static volatile uint8_t fxPressedV = 0;

void
__not_in_flash_func(process_kbd_report)(hid_keyboard_report_t const* report, hid_keyboard_report_t const* prev_report) {
    /* printf("HID key report modifiers %2.2X report ", report->modifier);
    for (unsigned char i: report->keycode)
        printf("%2.2X", i);
    printf("\r\n");
     */
    keyboard.start = isInReport(report, HID_KEY_ENTER) || isInReport(report, HID_KEY_KEYPAD_ENTER);
    keyboard.select = isInReport(report, HID_KEY_BACKSPACE) || isInReport(report, HID_KEY_ESCAPE) || isInReport(report, HID_KEY_KEYPAD_ADD);

    keyboard.a = isInReport(report, HID_KEY_Z) || isInReport(report, HID_KEY_O) || isInReport(report, HID_KEY_KEYPAD_0);
    keyboard.b = isInReport(report, HID_KEY_X) || isInReport(report, HID_KEY_P) || isInReport(report, HID_KEY_KEYPAD_DECIMAL);

    bool b7 = isInReport(report, HID_KEY_KEYPAD_7);
    bool b9 = isInReport(report, HID_KEY_KEYPAD_9);
    bool b1 = isInReport(report, HID_KEY_KEYPAD_1);
    bool b3 = isInReport(report, HID_KEY_KEYPAD_3);

    keyboard.up = b7 || b9 || isInReport(report, HID_KEY_ARROW_UP) || isInReport(report, HID_KEY_W) || isInReport(report, HID_KEY_KEYPAD_8);
    keyboard.down = b1 || b3 || isInReport(report, HID_KEY_ARROW_DOWN) || isInReport(report, HID_KEY_S) || isInReport(report, HID_KEY_KEYPAD_2) || isInReport(report, HID_KEY_KEYPAD_5);
    keyboard.left = b7 || b1 || isInReport(report, HID_KEY_ARROW_LEFT) || isInReport(report, HID_KEY_A) || isInReport(report, HID_KEY_KEYPAD_4);
    keyboard.right = b9 || b3 || isInReport(report, HID_KEY_ARROW_RIGHT)  || isInReport(report, HID_KEY_D) || isInReport(report, HID_KEY_KEYPAD_6);

    altPressed = isInReport(report, HID_KEY_ALT_LEFT) || isInReport(report, HID_KEY_ALT_RIGHT);
    ctrlPressed = isInReport(report, HID_KEY_CONTROL_LEFT) || isInReport(report, HID_KEY_CONTROL_RIGHT);
    
    if (altPressed && ctrlPressed && isInReport(report, HID_KEY_DELETE)) {
        watchdog_enable(10, true);
        while(true) {
            tight_loop_contents();
        }
    }
    if (ctrlPressed || altPressed) {
        uint8_t fxPressed = 0;
        if (isInReport(report, HID_KEY_F1)) fxPressed = 1;
        else if (isInReport(report, HID_KEY_F2)) fxPressed = 2;
        else if (isInReport(report, HID_KEY_F3)) fxPressed = 3;
        else if (isInReport(report, HID_KEY_F4)) fxPressed = 4;
        else if (isInReport(report, HID_KEY_F5)) fxPressed = 5;
        else if (isInReport(report, HID_KEY_F6)) fxPressed = 6;
        else if (isInReport(report, HID_KEY_F7)) fxPressed = 7;
        else if (isInReport(report, HID_KEY_F8)) fxPressed = 8;
        fxPressedV = fxPressed;
    }
}

Ps2Kbd_Mrmltr ps2kbd(
    pio1,
    PS2KBD_GPIO_FIRST,
    process_kbd_report
);


uint_fast32_t frames = 0;
uint64_t start_time;


i2s_config_t i2s_config;
#define AUDIO_FREQ 44100


typedef struct __attribute__((__packed__)) {
    bool is_directory;
    bool is_executable;
    size_t size;
    char filename[79];
} file_item_t;

constexpr int max_files = 300;
file_item_t * fileItems = (file_item_t *)(&SCREEN[0][0] + TEXTMODE_COLS*TEXTMODE_ROWS*2);

int compareFileItems(const void* a, const void* b) {
    const auto* itemA = (file_item_t *)a;
    const auto* itemB = (file_item_t *)b;
    // Directories come first
    if (itemA->is_directory && !itemB->is_directory)
        return -1;
    if (!itemA->is_directory && itemB->is_directory)
        return 1;
    // Sort files alphabetically
    return strcmp(itemA->filename, itemB->filename);
}

bool isExecutable(const char pathname[255],const char *extensions) {
    char *pathCopy = strdup(pathname);
    const char* token = strrchr(pathCopy, '.');

    if (token == nullptr) {
        return false;
    }

    token++;

    while (token != NULL) {
        if (strstr(extensions, token) != NULL) {
            free(pathCopy);
            return true;
        }
        token = strtok(NULL, ",");
    }
    free(pathCopy);
    return false;
}

bool filebrowser_loadfile(const char pathname[256]) {
    UINT bytes_read = 0;
    FIL file;

    constexpr int window_y = (TEXTMODE_ROWS - 5) / 2;
    constexpr int window_x = (TEXTMODE_COLS - 43) / 2;

    draw_window("Loading ROM", window_x, window_y, 43, 5);

    FILINFO fileinfo;
    f_stat(pathname, &fileinfo);
    rom_size = fileinfo.fsize;
    if (16384 - 64 << 10 < fileinfo.fsize) {
        draw_text("ERROR: ROM too large! Canceled!!", window_x + 1, window_y + 2, 13, 1);
        sleep_ms(5000);
        return false;
    }

    draw_text("Loading...", window_x + 1, window_y + 2, 10, 1);
    sleep_ms(500);

    multicore_lockout_start_blocking();
    auto flash_target_offset = FLASH_TARGET_OFFSET;
    const uint32_t ints = save_and_disable_interrupts();
    flash_range_erase(flash_target_offset, fileinfo.fsize);
    restore_interrupts(ints);
    if (FR_OK == f_open(&file, pathname, FA_READ)) {
        uint8_t buffer[FLASH_PAGE_SIZE];
        do {
            f_read(&file, &buffer, FLASH_PAGE_SIZE, &bytes_read);
            if (bytes_read) {
                const uint32_t ints = save_and_disable_interrupts();
                flash_range_program(flash_target_offset, buffer, FLASH_PAGE_SIZE);
                restore_interrupts(ints);
                gpio_put(PICO_DEFAULT_LED_PIN, flash_target_offset >> 13 & 1);
                flash_target_offset += FLASH_PAGE_SIZE;
            }
        }
        while (bytes_read != 0);
        gpio_put(PICO_DEFAULT_LED_PIN, true);
    }
    f_close(&file);
    multicore_lockout_end_blocking();
    // restore_interrupts(ints);
    gpio_put(PICO_DEFAULT_LED_PIN, false);
    strcpy(filename, fileinfo.fname);
    return true;
}

void filebrowser(const char pathname[256], const char executables[11]) {
    bool debounce = true;
    char basepath[256];
    char tmp[TEXTMODE_COLS + 1];
    strcpy(basepath, pathname);
    constexpr int per_page = TEXTMODE_ROWS - 3;

    DIR dir;
    FILINFO fileInfo;

    if (FR_OK != f_mount(&fs, "SD", 1)) {
        draw_text("SD Card not inserted or SD Card error!", 0, 0, 12, 0);
        while (true);
    }

    while (true) {
        memset(fileItems, 0, sizeof(file_item_t) * max_files);
        int total_files = 0;

        snprintf(tmp, TEXTMODE_COLS, "SD:\\%s", basepath);
        draw_window(tmp, 0, 0, TEXTMODE_COLS, TEXTMODE_ROWS - 1);
        memset(tmp, ' ', TEXTMODE_COLS);


        draw_text(tmp, 0, 29, 0, 0);
        auto off = 0;
        draw_text("START", off, 29, 7, 0);
        off += 5;
        draw_text(" Run at cursor ", off, 29, 0, 3);
        off += 16;
        draw_text("SELECT", off, 29, 7, 0);
        off += 6;
        draw_text(" Run previous  ", off, 29, 0, 3);
#ifndef TFT
        off += 16;
        draw_text("ARROWS", off, 29, 7, 0);
        off += 6;
        draw_text(" Navigation    ", off, 29, 0, 3);
        off += 16;
        draw_text("A/F10", off, 29, 7, 0);
        off += 5;
        draw_text(" USB DRV ", off, 29, 0, 3);
#endif

        if (FR_OK != f_opendir(&dir, basepath)) {
            draw_text("Failed to open directory", 1, 1, 4, 0);
            while (true);
        }

        if (strlen(basepath) > 0) {
            strcpy(fileItems[total_files].filename, "..\0");
            fileItems[total_files].is_directory = true;
            fileItems[total_files].size = 0;
            total_files++;
        }

        while (f_readdir(&dir, &fileInfo) == FR_OK &&
               fileInfo.fname[0] != '\0' &&
               total_files < max_files
        ) {
            // Set the file item properties
            fileItems[total_files].is_directory = fileInfo.fattrib & AM_DIR;
            fileItems[total_files].size = fileInfo.fsize;
            fileItems[total_files].is_executable = isExecutable(fileInfo.fname, executables);
            strncpy(fileItems[total_files].filename, fileInfo.fname, 78);
            total_files++;
        }
        f_closedir(&dir);

        qsort(fileItems, total_files, sizeof(file_item_t), compareFileItems);

        if (total_files > max_files) {
            draw_text(" Too many files!! ", TEXTMODE_COLS - 17, 0, 12, 3);
        }

        int offset = 0;
        int current_item = 0;

        while (true) {
            sleep_ms(100);

            if (!debounce) {
                debounce = !(gamepad1_bits.start);
            }

            // ESCAPE
            if (gamepad1_bits.select) {
                return;
            }

            if (gamepad1_bits.down) {
                if (offset + (current_item + 1) < total_files) {
                    if (current_item + 1 < per_page) {
                        current_item++;
                    }
                    else {
                        offset++;
                    }
                }
            }

            if (gamepad1_bits.up) {
                if (current_item > 0) {
                    current_item--;
                }
                else if (offset > 0) {
                    offset--;
                }
            }

            if (gamepad1_bits.right) {
                offset += per_page;
                if (offset + (current_item + 1) > total_files) {
                    offset = total_files - (current_item + 1);
                }
            }

            if (gamepad1_bits.left) {
                if (offset > per_page) {
                    offset -= per_page;
                }
                else {
                    offset = 0;
                    current_item = 0;
                }
            }

            if (debounce && gamepad1_bits.start) {
                auto file_at_cursor = fileItems[offset + current_item];

                if (file_at_cursor.is_directory) {
                    if (strcmp(file_at_cursor.filename, "..") == 0) {
                        const char* lastBackslash = strrchr(basepath, '\\');
                        if (lastBackslash != nullptr) {
                            const size_t length = lastBackslash - basepath;
                            basepath[length] = '\0';
                        }
                    }
                    else {
                        sprintf(basepath, "%s\\%s", basepath, file_at_cursor.filename);
                    }
                    debounce = false;
                    break;
                }

                if (file_at_cursor.is_executable) {
                    sprintf(tmp, "%s\\%s", basepath, file_at_cursor.filename);

                    filebrowser_loadfile(tmp);
                    return;
                }
            }

            for (int i = 0; i < per_page; i++) {
                uint8_t color = 11;
                uint8_t bg_color = 1;

                if (offset + i < max_files) {
                    const auto item = fileItems[offset + i];


                    if (i == current_item) {
                        color = 0;
                        bg_color = 3;
                        memset(tmp, 0xCD, TEXTMODE_COLS - 2);
                        tmp[TEXTMODE_COLS - 2] = '\0';
                        draw_text(tmp, 1, per_page + 1, 11, 1);
                        snprintf(tmp, TEXTMODE_COLS - 2, " Size: %iKb, File %lu of %i ", item.size / 1024,
                                 offset + i + 1,
                                 total_files);
                        draw_text(tmp, 2, per_page + 1, 14, 3);
                    }

                    const auto len = strlen(item.filename);
                    color = item.is_directory ? 15 : color;
                    color = item.is_executable ? 10 : color;
                    //color = strstr((char *)rom_filename, item.filename) != nullptr ? 13 : color;

                    memset(tmp, ' ', TEXTMODE_COLS - 2);
                    tmp[TEXTMODE_COLS - 2] = '\0';
                    memcpy(&tmp, item.filename, len < TEXTMODE_COLS - 2 ? len : TEXTMODE_COLS - 2);
                }
                else {
                    memset(tmp, ' ', TEXTMODE_COLS - 2);
                }
                draw_text(tmp, 1, i + 1, color, bg_color);
            }
        }
    }
}

enum menu_type_e {
    NONE,
    HEX,
    INT,
    TEXT,
    ARRAY,

    SAVE,
    LOAD,
    ROM_SELECT,
    RETURN,
};

typedef bool (*menu_callback_t)();

typedef struct __attribute__((__packed__)) {
    const char* text;
    menu_type_e type;
    const void* value;
    menu_callback_t callback;
    uint32_t max_value;
    char value_list[45][20];
} MenuItem;

uint16_t frequencies[] = { 378, 396, 404, 408, 412, 416, 420, 424, 432 };
uint8_t frequency_index = 0;

bool overclock() {
#if !PICO_RP2040
    volatile uint32_t *qmi_m0_timing=(uint32_t *)0x400d000c;
    vreg_disable_voltage_limit();
    vreg_set_voltage(VREG_VOLTAGE_1_60);
    sleep_ms(33);
    *qmi_m0_timing = 0x60007204;
    bool res = set_sys_clock_khz(frequencies[frequency_index] * KHZ, 0);
    *qmi_m0_timing = 0x60007303;
    return res;
#else
    hw_set_bits(&vreg_and_chip_reset_hw->vreg, VREG_AND_CHIP_RESET_VREG_VSEL_BITS);
    sleep_ms(10);
    return set_sys_clock_khz(frequencies[frequency_index] * KHZ, true);
#endif
}

bool save() {
    int tmp_data[8];
    char pathname[255];
#if 1
    if (settings.save_slot > 0) {
        sprintf(pathname, "%s\\%s_%d.save",  HOME_DIR, filename, settings.save_slot);
    }
    else {
        sprintf(pathname, "%s\\%s.save",  HOME_DIR, filename);
    }

    FRESULT fr = f_mount(&fs, "", 1);
    FIL fd;
    fr = f_open(&fd, pathname, FA_CREATE_ALWAYS | FA_WRITE);
    UINT bytes_writen;

    f_write(&fd, RAM, sizeof(RAM), &bytes_writen);
    f_write(&fd, VRAM, sizeof(VRAM), &bytes_writen);

    f_write(&fd, &cpu, sizeof(cpu), &bytes_writen);

    vdp_savestate(tmp_data);
    f_write(&fd, tmp_data, sizeof(tmp_data), &bytes_writen);

    f_write(&fd, &bank0_offset, 4, &bytes_writen);
    f_write(&fd, &bank1_offset, 4, &bytes_writen);

    f_close(&fd);
#endif
    return true;
}

bool load() {
    int tmp_data[8];
    char pathname[255];
#if 1

    if (settings.save_slot > 0) {
        sprintf(pathname, "%s\\%s_%d.save",  HOME_DIR, filename, settings.save_slot);
    }
    else {
        sprintf(pathname, "%s\\%s.save",  HOME_DIR, filename);
    }

    FRESULT fr = f_mount(&fs, "", 1);
    FIL fd;
    fr = f_open(&fd, pathname, FA_READ);
    UINT bytes_read;

    f_read(&fd, RAM, sizeof(RAM), &bytes_read);
    f_read(&fd, VRAM, sizeof(VRAM), &bytes_read);

    f_read(&fd, &cpu, sizeof(cpu), &bytes_read);

    f_read(&fd, tmp_data, sizeof(tmp_data), &bytes_read);

    f_read(&fd, &bank0_offset, 4, &bytes_read);
    f_read(&fd, &bank1_offset, 4, &bytes_read);


    vdp_loadstate(tmp_data);

    f_close(&fd);

#endif
    return true;
}

void load_config() {
    FIL file;
    char pathname[256];
    sprintf(pathname, "%s\\emulator.cfg", HOME_DIR);

    if (FR_OK == f_mount(&fs, "", 1) && FR_OK == f_open(&file, pathname, FA_READ)) {
        UINT bytes_read;
        f_read(&file, &settings, sizeof(settings), &bytes_read);
        f_close(&file);
    }
}

void save_config() {
    FIL file;
    char pathname[256];
    sprintf(pathname, "%s\\emulator.cfg", HOME_DIR);

    if (FR_OK == f_mount(&fs, "", 1) && FR_OK == f_open(&file, pathname, FA_CREATE_ALWAYS | FA_WRITE)) {
        UINT bytes_writen;
        f_write(&file, &settings, sizeof(settings), &bytes_writen);
        f_close(&file);
    }
}
#if SOFTTV
typedef struct tv_out_mode_t {
    // double color_freq;
    float color_index;
    COLOR_FREQ_t c_freq;
    enum graphics_mode_t mode_bpp;
    g_out_TV_t tv_system;
    NUM_TV_LINES_t N_lines;
    bool cb_sync_PI_shift_lines;
    bool cb_sync_PI_shift_half_frame;
} tv_out_mode_t;
extern tv_out_mode_t tv_out_mode;

bool color_mode=true;
bool toggle_color() {
    color_mode=!color_mode;
    if(color_mode) {
        tv_out_mode.color_index= 1.0f;
    } else {
        tv_out_mode.color_index= 0.0f;
    }

    return true;
}
#endif
const MenuItem menu_items[] = {
        {"Swap AB <> BA: %s",     ARRAY, &settings.swap_ab,  nullptr, 1, {"NO ",       "YES"}},
        {},
        { "Ghosting pix: %i ", INT, &settings.ghosting, nullptr, 6 }, // 6 == shift 1, 5->2, 4->3, 3->4, 2->5, 1->6, 0->7
        { "Palette: %s ", ARRAY, &settings.palette, nullptr, count_of(palettes), {
                  "DEFAULT          "
                , "BLACK & WHITE    "
                , "AMBER            "
                , "GREEN            "
                , "BLUE             "
                , "BGB              "
                , "WATAROO          "
                , "GB_DMG           "
                , "GB_POCKET        "
                , "GB_LIGHT         "
                , "BLOSSOM_PINK     "
                , "BUBBLES_BLUE     "
                , "BUTTERCUP_GREEN  "
                , "DIGIVICE         "
                , "GAME_COM         "
                , "GAMEKING         "
                , "GAME_MASTER      "
                , "GOLDEN_WILD      "
                , "GREENSCALE       "
                , "HOKAGE_ORANGE    "
                , "LABO_FAWN        "
                , "SUPER_SAIYAN     "
                , "MICROVISION      "
                , "MILLION_LIVE_GOLD"
                , "ODYSSEY_GOLD     "
                , "SHINY_SKY_BLUE   "
                , "SLIME_BLUE       "
                , "TI_83            "
                , "TRAVEL_WOOD      "
                , "VIRTUAL_BOY      "
                , "TV-LINK          "
                , "CUSTOM           "
         }},
        { "RGB0: %06Xh ", HEX, &settings.rgb0, nullptr, 0xFFFFFF },
        { "RGB1: %06Xh ", HEX, &settings.rgb1, nullptr, 0xFFFFFF },
        { "RGB2: %06Xh ", HEX, &settings.rgb2, nullptr, 0xFFFFFF },
        { "RGB3: %06Xh ", HEX, &settings.rgb3, nullptr, 0xFFFFFF },
#if VGA
        { "Keep aspect ratio: %s",     ARRAY, &settings.aspect_ratio,  nullptr, 1, {"NO ",       "YES"}},
#endif
#if SOFTTV
        { "" },
        { "TV system %s", ARRAY, &tv_out_mode.tv_system, nullptr, 1, { "PAL ", "NTSC" } },
        { "TV Lines %s", ARRAY, &tv_out_mode.N_lines, nullptr, 3, { "624", "625", "524", "525" } },
        { "Freq %s", ARRAY, &tv_out_mode.c_freq, nullptr, 1, { "3.579545", "4.433619" } },
        { "Colors: %s", ARRAY, &color_mode, &toggle_color, 1, { "NO ", "YES" } },
        { "Shift lines %s", ARRAY, &tv_out_mode.cb_sync_PI_shift_lines, nullptr, 1, { "NO ", "YES" } },
        { "Shift half frame %s", ARRAY, &tv_out_mode.cb_sync_PI_shift_half_frame, nullptr, 1, { "NO ", "YES" } },
#endif
    //{ "Player 1: %s",        ARRAY, &player_1_input, 2, { "Keyboard ", "Gamepad 1", "Gamepad 2" }},
    //{ "Player 2: %s",        ARRAY, &player_2_input, 2, { "Keyboard ", "Gamepad 1", "Gamepad 2" }},
    {},
    { "Save state: %i", INT, &settings.save_slot, &save, 5 },
    { "Load state: %i", INT, &settings.save_slot, &load, 5 },
{},
{
    "Overclocking: %s MHz", ARRAY, &frequency_index, &overclock, count_of(frequencies) - 1,
    { "378", "396", "404", "408", "412", "416", "420", "424", "432" }
},
{ "Press START / Enter to apply", NONE },
    { "Reset to ROM select", ROM_SELECT },
    { "Return to game", RETURN }
};
#define MENU_ITEMS_NUMBER (sizeof(menu_items) / sizeof (MenuItem))

static inline void update_palette() {
    if (count_of(palettes) <= settings.palette) {
        graphics_set_palette(0, settings.rgb0);
        graphics_set_palette(1, settings.rgb1);
        graphics_set_palette(2, settings.rgb2);
        graphics_set_palette(3, settings.rgb3);
    } else {
        const uint8_t (&palette)[12] = palettes[settings.palette];
        for (int i = 0; i < 4; ++i) {
            int i3 = i * 3;
            graphics_set_palette(
                i,
                RGB888(
                    palette[i3],
                    palette[i3+1],
                    palette[i3+2]
                )
            );
        }
    }
}

void menu() {
    bool exit = false;
    graphics_set_mode(TEXTMODE_DEFAULT);
    char footer[TEXTMODE_COLS];
    snprintf(footer, TEXTMODE_COLS, ":: %s ::", PICO_PROGRAM_NAME);
    draw_text(footer, TEXTMODE_COLS / 2 - strlen(footer) / 2, 0, 11, 1);
    snprintf(footer, TEXTMODE_COLS, ":: %s build %s %s ::", PICO_PROGRAM_VERSION_STRING, __DATE__, __TIME__);
    draw_text(footer, TEXTMODE_COLS / 2 - strlen(footer) / 2, TEXTMODE_ROWS - 1, 11, 1);
    uint current_item = 0;
    int8_t hex_digit = -1;
    bool blink = false;

    while (!exit) {
        blink = !blink;
        bool hex_edit_mode = false;
        for (int i = 0; i < MENU_ITEMS_NUMBER; i++) {
            uint8_t y = i + (TEXTMODE_ROWS - MENU_ITEMS_NUMBER >> 1);
            uint8_t x = TEXTMODE_COLS / 2 - 10;
            uint8_t color = 0xFF;
            uint8_t bg_color = 0x00;
            if (current_item == i) {
                color = 0x01;
                bg_color = 0xFF;
            }
            const MenuItem* item = &menu_items[i];
            if (i == current_item) {
                switch (item->type) {
                    case HEX:
                        if (item->max_value != 0 && count_of(palettes) <= settings.palette) {
                            uint32_t* value = (uint32_t *)item->value;
                            if (gamepad1_bits.right && hex_digit == 5) {
                                hex_digit = -1;
                            } else if (gamepad1_bits.right && hex_digit < 6) {
                                hex_digit++;
                            }
                            if (gamepad1_bits.left && hex_digit == -1) {
                                hex_digit = 5;
                            } else if (gamepad1_bits.left && hex_digit >= 0) {
                                hex_digit--;
                            }
                            if (gamepad1_bits.up && hex_digit >= 0 && hex_digit <= 5) {
                                uint32_t vc = *value + (1 << (5 - hex_digit) * 4);
                                if (vc < item->max_value) *value = vc;
                            }
                            if (gamepad1_bits.down && hex_digit >= 0 && hex_digit <= 5) {
                                uint32_t vc = *value - (1 << (5 - hex_digit) * 4);
                                if (vc < item->max_value) *value = vc;
                            }
                        }
                        break;
                    case INT:
                    case ARRAY:
                        if (item->max_value != 0) {
                            uint8_t* value = (uint8_t *)item->value;
                            if (gamepad1_bits.right && *value < item->max_value) {
                                (*value)++;
                            }
                            if (gamepad1_bits.left && *value > 0) {
                                (*value)--;
                            }
                        }
                        break;
                    case RETURN:
                        if (gamepad1_bits.start)
                            exit = true;
                        break;

                    case ROM_SELECT:
                        if (gamepad1_bits.start) {
                            reboot = true;
                            return;
                        }
                        break;
                    default:
                        break;
                }

                if (nullptr != item->callback && gamepad1_bits.start) {
                    exit = item->callback();
                }
            }
            static char result[TEXTMODE_COLS];
            switch (item->type) {
                case HEX:
                    snprintf(result, TEXTMODE_COLS, item->text, *(uint32_t*)item->value);
                    if (i == current_item && hex_digit >= 0 && hex_digit < 6) {
                        hex_edit_mode = true;
                        if (blink) {
                            result[hex_digit+6] = ' ';
                        }
                    }
                    break;
                case INT:
                    snprintf(result, TEXTMODE_COLS, item->text, *(uint8_t *)item->value);
                    break;
                case ARRAY:
                    snprintf(result, TEXTMODE_COLS, item->text, item->value_list[*(uint8_t *)item->value]);
                    break;
                case TEXT:
                    snprintf(result, TEXTMODE_COLS, item->text, item->value);
                    break;
                case NONE:
                    color = 6;
                default:
                    snprintf(result, TEXTMODE_COLS, "%s", item->text);
            }
            draw_text(result, x, y, color, bg_color);
        }

        if (gamepad1_bits.b || (gamepad1_bits.select && !gamepad1_bits.start))
            exit = true;

        if (gamepad1_bits.down && !hex_edit_mode) {
            current_item = (current_item + 1) % MENU_ITEMS_NUMBER;

            if (menu_items[current_item].type == NONE)
                current_item++;
        }
        if (gamepad1_bits.up && !hex_edit_mode) {
            current_item = (current_item - 1 + MENU_ITEMS_NUMBER) % MENU_ITEMS_NUMBER;

            if (menu_items[current_item].type == NONE)
                current_item--;
        }

        sleep_ms(125);
    }

#if VGA
    if (settings.aspect_ratio) {
        graphics_set_offset(80, 40);
        graphics_set_mode(GRAPHICSMODE_ASPECT);
    } else {
        graphics_set_offset(0, 4);
        graphics_set_mode(GRAPHICSMODE_DEFAULT);
    }
#else
    graphics_set_mode(GRAPHICSMODE_DEFAULT);
#endif
    update_palette();
    save_config();
}


#define AUDIO_FREQ 44100
#define AUDIO_BUFFER_LENGTH ((AUDIO_FREQ /60 +1) * 2)
static int16_t audio_buffer[AUDIO_BUFFER_LENGTH] = { 0 };

/* Renderer loop on Pico's second core */
void __time_critical_func(render_core)() {
    multicore_lockout_victim_init();

    ps2kbd.init_gpio();
    nespad_begin(clock_get_hz(clk_sys) / 1000, NES_GPIO_CLK, NES_GPIO_DATA, NES_GPIO_LAT);

    graphics_init();

#ifndef HWAY
    i2s_config = i2s_get_default_config();
    i2s_config.sample_freq = AUDIO_FREQ;
    i2s_config.dma_trans_count = 1 + (AUDIO_FREQ / 60);
    i2s_volume(&i2s_config, 0);
    i2s_init(&i2s_config);
/* Typical AY-3-8910 configuration */
    PSG_init(&psg, 4'433'000 / 4, AUDIO_FREQ);
    PSG_setVolumeMode(&psg, 2); // AY style
    PSG_reset(&psg);

    psg.stereo_mask[0] = 0x01;
    psg.stereo_mask[1] = 0x03;
    psg.stereo_mask[2] = 0x02;
#else
    InitAY();
#endif

    const auto buffer = (uint8_t *)SCREEN;
    graphics_set_buffer(buffer, 160, 150);
    graphics_set_textbuffer(buffer);
    graphics_set_bgcolor(0x000000);
#if VGA
    graphics_set_offset(0, 0);
#else
    graphics_set_offset(80, 40);
#endif
    graphics_set_flashmode(false, false);
    sem_acquire_blocking(&vga_start_semaphore);

    // 60 FPS loop
    #define frame_tick (16666)
    uint64_t tick = time_us_64();
    uint64_t last_frame_tick = tick, last_sound_tick = tick;

    while (true) {

        if (tick >= last_frame_tick + frame_tick) {
#ifdef TFT
            refresh_lcd();
#endif
            ps2kbd.tick();
            nespad_tick();

            last_frame_tick = tick;
        }

#ifndef HWAY
        if (tick >= last_sound_tick + (1000000 / AUDIO_FREQ)) {
            PSG_calc_stereo(&psg, audio_buffer, AUDIO_BUFFER_LENGTH);
            i2s_dma_write(&i2s_config, audio_buffer);
            last_sound_tick = tick;
        }
#endif
        tick = time_us_64();

        // tuh_task();
        // hid_app_task();
        tight_loop_contents();
    }

    __unreachable();
}

int frame, frame_cnt = 0;
int frame_timer_start = 0;

extern "C" uint8_t __time_critical_func(Rd6502)(uint16_t address) {
    if (address <= 0x1FFF) {
        return RAM[address & 1023];
    }

    if (address >= 0x6000 && address <= 0x9FFF) {
        if (protection < 8) {
            return ((0x47 >> (7 - protection++)) & 1) << 1;
        }

        return ROM[bank0_offset + (address - 0x6000)];
    }

    if (address >= 0xA000 && address <= 0xDFFF) {
        return ROM[bank1_offset + (address - 0xA000)];
    }

    if (address >= 0x5000 && address <= 0x53FF) {
//        if ((address & 7) == 6)
            return vdp_read();
//        exit(1);
    }

    if (address >= 0x5A00 && address <= 0x5AFF) {
        return 0x5B;
    }

    // INPUT
    if (address == 0x4400) {
        uint8_t buttons = 0xff;
        if (gamepad1_bits.up) buttons ^= 0b1;
        if (gamepad1_bits.down) buttons ^= 0b10;
        if (gamepad1_bits.left) buttons ^= 0b100;
        if (gamepad1_bits.right) buttons ^= 0b1000;
        if (gamepad1_bits.a) buttons ^= 0b10000;
        if (gamepad1_bits.b) buttons ^= 0b100000;
        if (gamepad1_bits.start) buttons ^= 0b1000000;
        if (gamepad1_bits.select) buttons ^= 0b10000000;
        return buttons;
    }

    if (address == 0x4800) {
        return 0;

    }

    // BIOS
    if (address >= 0xE000) {
        return BIOS[address & 4095];
    }

//    printf("READ >>>>>>>>> WTF %04x %04x\r\n", address, m6502_registers.PC);
    return 0xFF;
}

extern "C" void __time_critical_func(Wr6502)(uint16_t address, uint8_t value) {
    if (address <= 0x1FFF) {
        RAM[address & 1023] = value;
        return;
    }

    if (address >= 0x4000 && address <= 0x43FF) {
#ifndef HWAY
        PSG_writeReg(&psg, address & 0xf, value);
#else
        WriteAY(address & 0xf, value);
#endif
        return;
    }

    if (address >= 0x5000 && address <= 0x53FF) {
        return vdp_write(address, value);
    }

    if (address >= 0x5900 && address <= 0x59FF) {
        return;
    }

    // 4in1 mapper switch first 16kb
    if (address == 0x8000) {
        bank0_offset = 0x4000 * value;
        return;
    }

    // regular mapper switch second 16kb
    if (address == 0xC000) {
        bank1_offset = 0x4000 * value;
        return;
    }

    //printf("WRITE >>>>>>>>> WTF %04x\r\n", address);
//    exit(1);
}

byte Loop6502(M6502 *R) {
    return INT_QUIT;
}

int __time_critical_func(main)() {
    overclock();

    sem_init(&vga_start_semaphore, 0, 1);
    multicore_launch_core1(render_core);
    sem_release(&vga_start_semaphore);


    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    for (int i = 0; i < 6; i++) {
        sleep_ms(33);
        gpio_put(PICO_DEFAULT_LED_PIN, true);
        sleep_ms(33);
        gpio_put(PICO_DEFAULT_LED_PIN, false);
    }

    load_config();
    update_palette();

    while (true) {
        graphics_set_mode(TEXTMODE_DEFAULT);
        filebrowser(HOME_DIR, "bin");
        graphics_set_buffer((uint8_t *)SCREEN, 160, 150);

#if VGA
        if (settings.aspect_ratio) {
            graphics_set_offset(80, 40);
            graphics_set_mode(GRAPHICSMODE_ASPECT);
        } else {
            graphics_set_offset(0, 4);
            graphics_set_mode(GRAPHICSMODE_DEFAULT);
        }
#else
        settings.aspect_ratio = false;
        graphics_set_mode(GRAPHICSMODE_DEFAULT);
#endif

        start_time = time_us_64();
        memset(RAM, 0xFF, sizeof(RAM));
        memset(VRAM, 0x0, sizeof(VRAM));

        bank0_offset = 0;
        bank1_offset = 0x4000;
        protection = 0;

        Reset6502(&cpu);
        cpu.IPeriod = 32768;

        while (!reboot) {
            if (fxPressedV) {
                if (altPressed) {
                    settings.save_slot = fxPressedV;
                    load();
                } else if (ctrlPressed) {
                    settings.save_slot = fxPressedV;
                    save();
                }
            }
            Run6502(&cpu); Int6502(&cpu, INT_IRQ); // There's a timer that fires
            cpu.IPeriod = 32768;                   // an IRQ every
            Run6502(&cpu); Int6502(&cpu, INT_IRQ); // 32768 clocks (approx. 135.28Hz).

            cpu.IPeriod = 7364;
            Run6502(&cpu);
            screen_update((uint8_t *)SCREEN, settings.ghosting); // It takes exactly 72900 clocks at 4.433MHz per frame.

            cpu.IPeriod = 32768 - 7364;

            if (gamepad1_bits.start && gamepad1_bits.select) {
                menu();
            }

            if (limit_fps) {
                if (++frame_cnt == 6) {
                    while (time_us_64() - frame_timer_start < 16666 * 6);  // 60 Hz
                    frame_timer_start = time_us_64();
                    frame_cnt = 0;
                }
            }

            tight_loop_contents();
        }

        reboot = false;
    }
    __unreachable();
}
