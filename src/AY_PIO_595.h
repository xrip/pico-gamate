#pragma once

#include "hardware/pio.h"

#define pioAY595 pio0
#define sm_AY595 1
#define CLK_LATCH_595_BASE_PIN (26)
#define DATA_595_PIN (28)
#define CLK_AY_PIN (21)

void Init_AY_595();

void send595(uint16_t data);