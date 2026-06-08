// SPDX-License-Identifier: BSD-3-Clause
#ifndef ARDUINO_CORE_LPC8XX_WIRE_H
#define ARDUINO_CORE_LPC8XX_WIRE_H

#include <stddef.h>
#include <stdint.h>

#include "Stream.h"

#define BUFFER_LENGTH 32

class TwoWire : public Stream {
public:
    void begin(void);
    void begin(uint8_t address);
    void end(void);
    void setClock(uint32_t clock);
    void setWireTimeout(uint32_t timeout = 25000, bool reset_with_timeout = false);
    bool getWireTimeoutFlag(void) const;
    void clearWireTimeoutFlag(void);

    void beginTransmission(uint8_t address);
    size_t write(uint8_t data) override;
    size_t write(const uint8_t *data, size_t quantity) override;
    uint8_t endTransmission(void);
    uint8_t endTransmission(bool stopBit);
    uint8_t requestFrom(uint8_t address, uint8_t quantity);
    uint8_t requestFrom(uint8_t address, uint8_t quantity, bool stopBit);

    int available(void) override;
    int read(void) override;
    int peek(void) override;
    void flush(void) override;

private:
    uint8_t _address = 0u;
    uint32_t _clock = 100000u;
    bool _timeoutFlag = false;
};

extern TwoWire Wire;

#endif
