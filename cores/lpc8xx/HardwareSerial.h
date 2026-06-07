// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — HardwareSerial declaration
//
// SKELETON: API shape only. Implementation TODO. See fbuild#479.
//
// Backed by USART0 on the LPC8xx switch matrix. USB-CDC is out of scope
// (these chips have no native USB).
#ifndef ARDUINO_CORE_LPC8XX_HARDWARE_SERIAL_H
#define ARDUINO_CORE_LPC8XX_HARDWARE_SERIAL_H

#include <stdint.h>
#include <stddef.h>

class HardwareSerial {
public:
    void begin(uint32_t baud);
    void end(void);
    int available(void);
    int read(void);
    size_t write(uint8_t b);
    size_t write(const uint8_t *buf, size_t len);

    // Convenience overloads — print / println family.
    size_t print(const char *s);
    size_t print(int n);
    size_t println(const char *s);
    size_t println(int n);
    size_t println(void);
};

extern HardwareSerial Serial;

#endif // ARDUINO_CORE_LPC8XX_HARDWARE_SERIAL_H
