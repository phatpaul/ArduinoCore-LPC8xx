// SPDX-License-Identifier: BSD-3-Clause
#ifndef ARDUINO_CORE_LPC8XX_PRINTABLE_H
#define ARDUINO_CORE_LPC8XX_PRINTABLE_H

#include <stddef.h>

class Print;

class Printable {
public:
    virtual ~Printable() {}
    virtual size_t printTo(Print &p) const = 0;
};

#endif
