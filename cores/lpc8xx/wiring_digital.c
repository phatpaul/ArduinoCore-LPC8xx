// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — GPIO API stubs
//
// TODO: implement against MCUXpresso SDK
//   - pinMode  → IOCON_PinMuxSet + GPIO_PortInit + GPIO_PinSetDir
//   - digitalWrite → GPIO_PortToggle / GPIO_PortSet / GPIO_PortClear
//   - digitalRead  → GPIO_PinRead
//
// Pin → port/bit mapping comes from variants/<part>/variant.h.
#include "Arduino.h"

void pinMode(pin_size_t pin, PinMode mode) {
    (void)pin;
    (void)mode;
}

void digitalWrite(pin_size_t pin, PinStatus value) {
    (void)pin;
    (void)value;
}

PinStatus digitalRead(pin_size_t pin) {
    (void)pin;
    return LOW;
}
