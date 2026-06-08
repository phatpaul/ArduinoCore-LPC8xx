// SPDX-License-Identifier: BSD-3-Clause
#include "variant.h"
#include "lpc8xx_registers.h"

extern "C" {

#define PIN_GPIO(bit) {0u, bit, LPC8XX_PIN_CAP_GPIO | LPC8XX_PIN_CAP_INTERRUPT | LPC8XX_PIN_CAP_3V3_ONLY, LPC8XX_PIN_NO_ADC, LPC8XX_PIN_NO_DAC, LPC8XX_PIN_NO_PWM, bit}
#define PIN_ANALOG(bit, adc) {0u, bit, LPC8XX_PIN_CAP_GPIO | LPC8XX_PIN_CAP_ADC | LPC8XX_PIN_CAP_INTERRUPT | LPC8XX_PIN_CAP_3V3_ONLY, adc, LPC8XX_PIN_NO_DAC, LPC8XX_PIN_NO_PWM, bit}
#define PIN_PWM(bit, pwm) {0u, bit, LPC8XX_PIN_CAP_GPIO | LPC8XX_PIN_CAP_PWM | LPC8XX_PIN_CAP_INTERRUPT | LPC8XX_PIN_CAP_3V3_ONLY, LPC8XX_PIN_NO_ADC, LPC8XX_PIN_NO_DAC, pwm, bit}

const lpc8xx_pin_info_t g_APinDescription[VARIANT_NUM_DIGITAL_PINS] = {
    PIN_GPIO(0),  PIN_GPIO(1),  PIN_GPIO(2),  PIN_GPIO(3),  PIN_GPIO(4),  PIN_GPIO(5),
    PIN_GPIO(6),  PIN_GPIO(7),  PIN_GPIO(8),  PIN_GPIO(9),  PIN_GPIO(10), PIN_GPIO(11),
    PIN_GPIO(12), PIN_PWM(13, 0), PIN_ANALOG(14, 0), PIN_ANALOG(15, 1), PIN_ANALOG(16, 2), PIN_ANALOG(17, 3),
    PIN_ANALOG(18, 4), PIN_ANALOG(19, 5), PIN_GPIO(20), PIN_GPIO(21),
};

const uint8_t variant_pin_count = VARIANT_NUM_DIGITAL_PINS;

void initVariant(void) {
    lpc8xx_basic_peripheral_init();
}

}
