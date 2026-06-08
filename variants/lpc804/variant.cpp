// SPDX-License-Identifier: BSD-3-Clause
#include "variant.h"
#include "lpc8xx_registers.h"

extern "C" {

const lpc8xx_pin_info_t g_APinDescription[VARIANT_NUM_DIGITAL_PINS] = {
    {0, 0},  {0, 1},  {0, 2},  {0, 3},  {0, 4},  {0, 5},
    {0, 6},  {0, 7},  {0, 8},  {0, 9},  {0, 10}, {0, 11},
    {0, 12}, {0, 13}, {0, 14}, {0, 15}, {0, 16}, {0, 17},
    {0, 18}, {0, 19}, {0, 20}, {0, 21},
};

const uint8_t variant_pin_count = VARIANT_NUM_DIGITAL_PINS;

void initVariant(void) {
    lpc8xx_basic_peripheral_init();
}

}
