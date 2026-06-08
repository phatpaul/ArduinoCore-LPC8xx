// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>

const unsigned long interval = 500;
unsigned long previousMillis = 0;
PinStatus ledState = LOW;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    const unsigned long now = millis();
    if (now - previousMillis >= interval) {
        previousMillis = now;
        ledState = (ledState == LOW) ? HIGH : LOW;
        digitalWrite(LED_BUILTIN, ledState);
    }
}
