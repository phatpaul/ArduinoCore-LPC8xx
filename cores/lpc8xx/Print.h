// SPDX-License-Identifier: BSD-3-Clause
#ifndef ARDUINO_CORE_LPC8XX_PRINT_H
#define ARDUINO_CORE_LPC8XX_PRINT_H

#include <stddef.h>
#include <stdint.h>

#include "Printable.h"

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Print {
public:
    virtual ~Print() {}
    virtual size_t write(uint8_t b) = 0;

    virtual size_t write(const uint8_t *buffer, size_t size) {
        size_t n = 0;
        while (size-- > 0u) {
            n += write(*buffer++);
        }
        return n;
    }

    size_t write(const char *str) {
        if (str == nullptr) {
            return 0u;
        }
        const uint8_t *p = reinterpret_cast<const uint8_t *>(str);
        size_t len = 0u;
        while (p[len] != 0u) {
            ++len;
        }
        return write(p, len);
    }

    size_t print(const char str[]) { return write(str); }
    size_t print(char c) { return write(static_cast<uint8_t>(c)); }
    size_t print(unsigned char b, int base = DEC) { return printNumber(b, base); }
    size_t print(int n, int base = DEC) { return print(static_cast<long>(n), base); }
    size_t print(unsigned int n, int base = DEC) { return printNumber(n, base); }
    size_t print(long n, int base = DEC) {
        if (base == 0) {
            return write(static_cast<uint8_t>(n));
        }
        if (base == DEC && n < 0) {
            return write(static_cast<uint8_t>('-')) + printNumber(static_cast<unsigned long>(-n), DEC);
        }
        return printNumber(static_cast<unsigned long>(n), base);
    }
    size_t print(unsigned long n, int base = DEC) { return printNumber(n, base); }
    size_t print(const Printable &obj) { return obj.printTo(*this); }

    size_t println(void) {
        static const uint8_t newline[] = {'\r', '\n'};
        return write(newline, sizeof(newline));
    }
    size_t println(const char str[]) { return print(str) + println(); }
    size_t println(char c) { return print(c) + println(); }
    size_t println(unsigned char b, int base = DEC) { return print(b, base) + println(); }
    size_t println(int n, int base = DEC) { return print(n, base) + println(); }
    size_t println(unsigned int n, int base = DEC) { return print(n, base) + println(); }
    size_t println(long n, int base = DEC) { return print(n, base) + println(); }
    size_t println(unsigned long n, int base = DEC) { return print(n, base) + println(); }
    size_t println(const Printable &obj) { return print(obj) + println(); }

protected:
    size_t printNumber(unsigned long n, int base) {
        char buf[8 * sizeof(unsigned long) + 1];
        char *str = &buf[sizeof(buf) - 1];
        *str = '\0';

        if (base < 2) {
            base = DEC;
        }

        do {
            const unsigned long digit = n % static_cast<unsigned long>(base);
            *--str = static_cast<char>(digit < 10u ? ('0' + digit) : ('A' + digit - 10u));
            n /= static_cast<unsigned long>(base);
        } while (n != 0u);

        return write(str);
    }
};

#endif
