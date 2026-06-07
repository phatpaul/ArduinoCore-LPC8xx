// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — timing API stubs
//
// TODO:
//   - SysTick @ 1ms tick → drives millis(); micros() reads
//     CYCCNT-equivalent (LPC8xx M0+ has no DWT cycle counter — use
//     the MRT, Multi-Rate Timer, in free-running mode).
//   - delay(ms): busy-wait until millis()+ms.
//   - delayMicroseconds(us): MRT countdown or NOP loop tuned per clock.
//
// Tick source initialisation happens in main.cpp before setup() runs.
#include "Arduino.h"

static volatile uint32_t _systick_ms = 0;

void delay(uint32_t ms) {
    (void)ms;
}

void delayMicroseconds(uint32_t us) {
    (void)us;
}

uint32_t millis(void) {
    return _systick_ms;
}

uint32_t micros(void) {
    return 0;
}
