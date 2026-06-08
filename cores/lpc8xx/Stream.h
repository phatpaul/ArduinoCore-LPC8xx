// SPDX-License-Identifier: BSD-3-Clause
#ifndef ARDUINO_CORE_LPC8XX_STREAM_H
#define ARDUINO_CORE_LPC8XX_STREAM_H

#include "Print.h"

class Stream : public Print {
public:
    virtual int available(void) = 0;
    virtual int read(void) = 0;
    virtual int peek(void) = 0;
    virtual void flush(void) = 0;
};

#endif
