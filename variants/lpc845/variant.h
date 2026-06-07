// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — LPC845 pin map
//
// SKELETON: physical pin numbers TBD against the LPC845M301JBD64 datasheet
// and the LPC845-BRK board silkscreen. Each entry resolves to a
// (port, bit) pair consumed by wiring_digital.c.
#ifndef ARDUINO_CORE_LPC8XX_VARIANT_LPC845_H
#define ARDUINO_CORE_LPC8XX_VARIANT_LPC845_H

#include <stdint.h>

#define VARIANT_MCU_LPC845      1
#define VARIANT_FLASH_SIZE      (64u * 1024u)
#define VARIANT_SRAM_SIZE       (16u * 1024u)
#define VARIANT_FRO_HZ          30000000u

#define VARIANT_NUM_DIGITAL_PINS 30u

#endif // ARDUINO_CORE_LPC8XX_VARIANT_LPC845_H
