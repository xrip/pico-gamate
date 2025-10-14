#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct __attribute__((__packed__)) {
    uint8_t version;
    bool swap_ab;
    bool aspect_ratio;
    uint8_t ghosting;
    uint8_t palette;
    uint8_t save_slot;
    uint16_t tba;
    uint32_t rgb0;
    uint32_t rgb1;
    uint32_t rgb2;
    uint32_t rgb3;
    bool instant_ignition;
} SETTINGS;

extern SETTINGS settings;
