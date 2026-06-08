// SPDX-License-Identifier: BSD-3-Clause
// LPC804 variant for LPCXpresso804 style headers.
#ifndef ARDUINO_CORE_LPC8XX_VARIANT_LPC804_H
#define ARDUINO_CORE_LPC8XX_VARIANT_LPC804_H

#include <stdint.h>

#define VARIANT_MCU_LPC804      1
#define VARIANT_FLASH_SIZE      (32u * 1024u)
#define VARIANT_SRAM_SIZE       (4u * 1024u)
#define VARIANT_FRO_HZ          15000000u

#define VARIANT_NUM_DIGITAL_PINS 22u

#define LED_BUILTIN 13u

#define PIN_SERIAL_TX 4u
#define PIN_SERIAL_RX 0u

#define PIN_SPI_SS   10u
#define PIN_SPI_MOSI 11u
#define PIN_SPI_MISO 12u
#define PIN_SPI_SCK  13u

#define PIN_WIRE_SDA 16u
#define PIN_WIRE_SCL 17u

#define A0 14u
#define A1 15u
#define A2 16u
#define A3 17u
#define A4 18u
#define A5 19u
#define PIN_A0 A0
#define PIN_A1 A1
#define PIN_A2 A2
#define PIN_A3 A3
#define PIN_A4 A4
#define PIN_A5 A5
#define NUM_ANALOG_INPUTS 6u

#define LPC8XX_PIN_NO_ADC 0xFFu
#define LPC8XX_PIN_NO_DAC 0xFFu
#define LPC8XX_PIN_NO_PWM 0xFFu
#define LPC8XX_PIN_NO_INTERRUPT 0xFFu

#define LPC8XX_PIN_CAP_GPIO       (1u << 0)
#define LPC8XX_PIN_CAP_ADC        (1u << 1)
#define LPC8XX_PIN_CAP_DAC        (1u << 2)
#define LPC8XX_PIN_CAP_PWM        (1u << 3)
#define LPC8XX_PIN_CAP_INTERRUPT  (1u << 4)
#define LPC8XX_PIN_CAP_3V3_ONLY   (1u << 5)
#define LPC8XX_PIN_CAP_ACTIVE_LOW (1u << 6)

typedef struct {
    uint8_t port;
    uint8_t bit;
    uint16_t capabilities;
    uint8_t adc_channel;
    uint8_t dac_channel;
    uint8_t pwm_channel;
    uint8_t interrupt_channel;
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
