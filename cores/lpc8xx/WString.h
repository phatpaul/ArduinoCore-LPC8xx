// SPDX-License-Identifier: BSD-3-Clause
#ifndef ARDUINO_CORE_LPC8XX_WSTRING_H
#define ARDUINO_CORE_LPC8XX_WSTRING_H

#include <stddef.h>

class String {
public:
    String() : _value("") {}
    String(const char *value) : _value(value ? value : "") {}
    String(char value) : _value(_buffer) {
        _buffer[0] = value;
        _buffer[1] = '\0';
    }

    const char *c_str(void) const { return _value; }
    size_t length(void) const {
        size_t n = 0u;
        while (_value[n] != '\0') {
            ++n;
        }
        return n;
    }

    operator const char *() const { return _value; }
    char operator[](size_t index) const { return _value[index]; }

private:
    const char *_value;
    char _buffer[2] = {'\0', '\0'};
};

#endif
