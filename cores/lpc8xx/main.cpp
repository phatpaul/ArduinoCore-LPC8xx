// SPDX-License-Identifier: BSD-3-Clause
// Framework-owned main().
#include "Arduino.h"

int main(void) {
    // Reset_Handler owns SystemInit on fbuild's LPC804/LPC845 startup path.
    // main() only initializes Arduino peripherals before user code runs.
    init();
    initVariant();
    setup();
    for (;;) {
        loop();
        yield();
    }
    return 0;
}
