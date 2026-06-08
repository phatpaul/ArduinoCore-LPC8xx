// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>
#include <Wire.h>

void setup() {
    Serial.begin(115200);
    Wire.begin();
}

void loop() {
    for (uint8_t address = 1; address < 127; ++address) {
        Wire.beginTransmission(address);
        if (Wire.endTransmission() == 0) {
            Serial.print("I2C device at 0x");
            Serial.println(address, HEX);
        }
    }
    delay(5000);
}
