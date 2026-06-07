// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — framework-owned main()
//
// Replaces the hand-rolled main shim in fbuild's Stage-1 LPC8xx scaffold.
// SystemInit() is provided by startup_lpc8xx.S (per-variant).
#include "Arduino.h"

extern "C" void SystemInit(void);

int main(void) {
    SystemInit();
    // TODO: variant-specific clock/peripheral init before setup().
    setup();
    for (;;) {
        loop();
    }
    return 0;
}
