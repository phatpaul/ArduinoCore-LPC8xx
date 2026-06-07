// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — LPC804 variant init stubs
//
// TODO:
//   - Pin table (smaller pin count than LPC845; check DIP24/QFP24 package
//     against datasheet Rev 1.x).
//   - Clock init: FRO @ 15 MHz, zero flash wait states.
//   - Switch-matrix defaults: route USART0 + SPI0 to LPCXpresso804 header
//     pins.
#include "variant.h"
