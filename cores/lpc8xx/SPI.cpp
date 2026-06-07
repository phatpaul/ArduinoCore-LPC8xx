// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — SPI implementation stubs
//
// TODO: implement against MCUXpresso SDK
//   - begin()        → SWM mux SPI0_SCK/MOSI/MISO + SPI_MasterInit
//   - transfer(b)    → SPI_MasterTransferBlocking with 1-byte buffer
//   - setClockDivider → recompute baudRate_Bps, SPI_MasterSetBaudRate
//   - setDataMode    → SPI_Enable false + reconfigure CPOL/CPHA, re-enable
#include "SPI.h"

SPIClass SPI;

void SPIClass::begin(void) {}
void SPIClass::end(void) {}

uint8_t SPIClass::transfer(uint8_t b) { (void)b; return 0; }

void SPIClass::transfer(void *buf, size_t len) {
    uint8_t *p = static_cast<uint8_t *>(buf);
    for (size_t i = 0; i < len; ++i) {
        p[i] = transfer(p[i]);
    }
}

void SPIClass::setClockDivider(uint8_t divider) { (void)divider; }
void SPIClass::setBitOrder(uint8_t order) { (void)order; }
void SPIClass::setDataMode(uint8_t mode) { (void)mode; }
