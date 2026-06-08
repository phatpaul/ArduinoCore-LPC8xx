// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>

int brightness = 0;
int fadeAmount = 5;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    analogWriteResolution(8);
}

void loop() {
    analogWrite(LED_BUILTIN, brightness);
    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
    }
    delay(30);
}
