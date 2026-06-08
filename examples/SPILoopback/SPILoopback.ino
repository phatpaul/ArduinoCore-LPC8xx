// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>
#include <SPI.h>

void setup() {
    Serial.begin(115200);
    SPI.begin();
}

void loop() {
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
    const uint8_t value = SPI.transfer(0xA5);
    SPI.endTransaction();
    Serial.println(value, HEX);
    delay(500);
}
