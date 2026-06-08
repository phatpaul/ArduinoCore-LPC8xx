// SPDX-License-Identifier: BSD-3-Clause
#include "Arduino.h"

static int g_analog_read_resolution = 10;
static int g_analog_write_resolution = 8;

void analogReadResolution(int bits) {
    if (bits > 0 && bits <= 32) {
        g_analog_read_resolution = bits;
    }
}

void analogWriteResolution(int bits) {
    if (bits > 0 && bits <= 32) {
        g_analog_write_resolution = bits;
    }
}

int analogRead(pin_size_t pin) {
    (void)pin;
    (void)g_analog_read_resolution;
    return 0;
}

void analogWrite(pin_size_t pin, int value) {
    (void)pin;
    (void)value;
    (void)g_analog_write_resolution;
}
