// SPDX-License-Identifier: BSD-3-Clause
#include "Arduino.h"

int digitalPinToInterrupt(pin_size_t pin) {
    if (pin >= variant_pin_count) {
        return NOT_AN_INTERRUPT;
    }
    return (g_APinDescription[pin].capabilities & LPC8XX_PIN_CAP_INTERRUPT) ? (int)pin : NOT_AN_INTERRUPT;
}

void attachInterrupt(int interruptNum, void (*userFunc)(void), int mode) {
    (void)interruptNum;
    (void)userFunc;
    (void)mode;
}

void detachInterrupt(int interruptNum) {
    (void)interruptNum;
}
