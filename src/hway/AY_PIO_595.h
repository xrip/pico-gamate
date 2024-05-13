#pragma once

#include "hardware/pio.h"

#define pioAY595 pio0
#define sm_AY595 1
#define CLK_LATCH_595_BASE_PIN (26)
#define DATA_595_PIN (28)
#define CLK_AY_PIN (21)

#define BEEPER_ON (1<<12)
#define RESET (0x0000)
#define AY_Enable (1<<14)
#define PIN_AY_BC1 (1<<8)
#define PIN_AY_BDIR (1<<9)
#define CHIP_SELECT_1 (1<<10|AY_Enable)
#define CHIP_SELECT_2 (1<<11|AY_Enable)
#define SET_REG_CHIP_1 (CHIP_SELECT_1|PIN_AY_BDIR|PIN_AY_BC1)
#define SET_REG_CHIP_2 (CHIP_SELECT_2|PIN_AY_BDIR|PIN_AY_BC1)
#define SET_DATA_CHIP_1 (CHIP_SELECT_1|PIN_AY_BDIR)
#define SET_DATA_CHIP_2 (CHIP_SELECT_2|PIN_AY_BDIR)


void InitAY();
void SendAY(uint16_t data);