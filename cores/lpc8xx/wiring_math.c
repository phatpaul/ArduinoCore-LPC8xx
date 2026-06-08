// SPDX-License-Identifier: BSD-3-Clause
#include "Arduino.h"

long map(long value, long fromLow, long fromHigh, long toLow, long toHigh) {
    return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}
