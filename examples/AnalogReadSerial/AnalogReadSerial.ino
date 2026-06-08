// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    analogReadResolution(10);
}

void loop() {
    Serial.println(analogRead(A0));
    delay(250);
}
