// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>

unsigned long counter = 0;

void setup() {
    Serial.begin(115200, SERIAL_8N1);
}

void loop() {
    Serial.print("tick ");
    Serial.println(counter++);
    delay(1000);
}
