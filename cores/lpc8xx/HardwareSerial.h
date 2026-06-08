// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx - HardwareSerial declaration.
#ifndef ARDUINO_CORE_LPC8XX_HARDWARE_SERIAL_H
#define ARDUINO_CORE_LPC8XX_HARDWARE_SERIAL_H

#include <stdint.h>
#include <stddef.h>

#include "Stream.h"

#define SERIAL_8N1 0x06

class HardwareSerial : public Stream {
public:
    void begin(uint32_t baud);
    void begin(uint32_t baud, uint16_t config);
    void end(void);
    int available(void) override;
    int availableForWrite(void);
    int read(void) override;
    int peek(void) override;
    void flush(void) override;
    size_t write(uint8_t b) override;
    size_t write(const uint8_t *buf, size_t len) override;
    using Print::write;

    explicit operator bool(void) const;
};

extern HardwareSerial Serial;

#endif
