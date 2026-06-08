// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx - SPI class declaration.
#ifndef ARDUINO_CORE_LPC8XX_SPI_H
#define ARDUINO_CORE_LPC8XX_SPI_H

#include <stdint.h>
#include <stddef.h>

#define SPI_CLOCK_DIV2   2
#define SPI_CLOCK_DIV4   4
#define SPI_CLOCK_DIV8   8
#define SPI_CLOCK_DIV16  16

#define MSBFIRST 1
#define LSBFIRST 0

#define SPI_MODE0 0
#define SPI_MODE1 1
#define SPI_MODE2 2
#define SPI_MODE3 3

class SPIClass {
public:
    void begin(void);
    void end(void);
    uint8_t transfer(uint8_t b);
    void transfer(void *buf, size_t len);
    void setClockDivider(uint8_t divider);
    void setBitOrder(uint8_t order);
    void setDataMode(uint8_t mode);

private:
    uint8_t _divider = SPI_CLOCK_DIV4;
    uint8_t _bitOrder = MSBFIRST;
    uint8_t _dataMode = SPI_MODE0;
    bool _begun = false;
    void applyConfig(void);
};

extern SPIClass SPI;

#endif
