// SPDX-License-Identifier: BSD-3-Clause
// LPC845 variant for LPC845-BRK style headers.
#ifndef ARDUINO_CORE_LPC8XX_VARIANT_LPC845_H
#define ARDUINO_CORE_LPC8XX_VARIANT_LPC845_H

#include <stdint.h>

#define VARIANT_MCU_LPC845      1
#define VARIANT_FLASH_SIZE      (64u * 1024u)
#define VARIANT_SRAM_SIZE       (16u * 1024u)
#define VARIANT_FRO_HZ          30000000u

#define VARIANT_NUM_DIGITAL_PINS 30u

#define LED_BUILTIN 13u

#define PIN_SERIAL_TX 4u
#define PIN_SERIAL_RX 0u

#define PIN_SPI_SS   10u
#define PIN_SPI_MOSI 11u
#define PIN_SPI_MISO 12u
#define PIN_SPI_SCK  13u

typedef struct {
    uint8_t port;
    uint8_t bit;
} lpc8xx_pin_info_t;

#ifdef __cplusplus
extern "C" {
#endif

extern const lpc8xx_pin_info_t g_APinDescription[VARIANT_NUM_DIGITAL_PINS];
extern const uint8_t variant_pin_count;

void initVariant(void);

#ifdef __cplusplus
}
#endif

#endif
