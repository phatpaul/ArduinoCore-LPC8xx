// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx - HardwareSerial declaration.
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
    int peek(void);
    void flush(void);
    size_t write(uint8_t b);
    size_t write(const uint8_t *buf, size_t len);

    size_t print(const char *s);
    size_t print(int n);
    size_t print(unsigned int n);
    size_t print(long n);
    size_t print(unsigned long n);
    size_t println(const char *s);
    size_t println(int n);
    size_t println(unsigned int n);
    size_t println(long n);
    size_t println(unsigned long n);
    size_t println(void);
};

extern HardwareSerial Serial;

#endif
