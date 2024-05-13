//
// Created by xrip on 11.05.2024.
//

#ifndef MYBOY_VDP_H
#define MYBOY_VDP_H
#include <cstdint>

void lcdcon_w(uint8_t data);
void xscroll_w(uint8_t data);
void yscroll_w(uint8_t data);
void xpos_w(uint8_t data);
void ypos_w(uint8_t data);
uint8_t vram_r();
void vram_w(uint8_t data);
uint32_t screen_update(uint8_t * screen);
#endif //MYBOY_VDP_H
