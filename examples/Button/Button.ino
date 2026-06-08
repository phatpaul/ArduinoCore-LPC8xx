// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>

const pin_size_t buttonPin = 2;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, digitalRead(buttonPin) == LOW ? HIGH : LOW);
}
