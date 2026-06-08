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

class SPISettings {
public:
    SPISettings(uint32_t clock = 4000000u, uint8_t bitOrder = MSBFIRST, uint8_t dataMode = SPI_MODE0)
        : _clock(clock), _bitOrder(bitOrder), _dataMode(dataMode) {}

    uint32_t clock(void) const { return _clock; }
    uint8_t bitOrder(void) const { return _bitOrder; }
    uint8_t dataMode(void) const { return _dataMode; }

private:
    uint32_t _clock;
    uint8_t _bitOrder;
    uint8_t _dataMode;
};

class SPIClass {
public:
    void begin(void);
    void end(void);
    void beginTransaction(SPISettings settings);
    void endTransaction(void);
    void usingInterrupt(uint8_t interruptNumber);
    void notUsingInterrupt(uint8_t interruptNumber);
    uint8_t transfer(uint8_t b);
    uint16_t transfer16(uint16_t data);
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
    void applySettings(SPISettings settings);
};

extern SPIClass SPI;

#endif
