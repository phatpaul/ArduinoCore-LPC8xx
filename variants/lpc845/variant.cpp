// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — LPC845 variant init stubs
//
// TODO:
//   - Pin table: GPIO_PORT0_BASE → port/bit per Arduino pin index.
//   - Clock init: switch to FRO @ 30 MHz, set flash wait states (1WS @ 30 MHz).
//   - Switch-matrix defaults: leave USART0 + SPI0 mux'd to LPC845-BRK header pins.
#include "variant.h"
