// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>

const unsigned int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
    for (size_t i = 0; i < sizeof(melody) / sizeof(melody[0]); ++i) {
        tone(LED_BUILTIN, melody[i], 100);
        delay(125);
    }
    noTone(LED_BUILTIN);
}

void loop() {}
