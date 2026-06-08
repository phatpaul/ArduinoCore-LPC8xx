// SPDX-License-Identifier: BSD-3-Clause
// Minimal LPC8xx register definitions used by the Arduino shim.
#ifndef ARDUINO_CORE_LPC8XX_REGISTERS_H
#define ARDUINO_CORE_LPC8XX_REGISTERS_H

#include <stdint.h>
#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef F_CPU
#define F_CPU VARIANT_FRO_HZ
#endif

#define LPC8XX_SYSCON_BASE   (0x40048000UL)
#define LPC8XX_IOCON_BASE    (0x40044000UL)
#define LPC8XX_SWM_BASE      (0x4000C000UL)
#define LPC8XX_GPIO_BASE     (0xA0000000UL)
#define LPC8XX_USART0_BASE   (0x40064000UL)
#define LPC8XX_SPI0_BASE     (0x40058000UL)
#define LPC8XX_SYSTICK_BASE  (0xE000E010UL)

#define LPC8XX_AHBCLK_GPIO0  (6u)
#define LPC8XX_AHBCLK_SWM    (7u)
#define LPC8XX_AHBCLK_SPI0   (11u)
#define LPC8XX_AHBCLK_USART0 (14u)
#define LPC8XX_AHBCLK_IOCON  (18u)

#define LPC8XX_PRESET_SPI0   (11u)
#define LPC8XX_PRESET_USART0 (14u)

#define LPC8XX_USART_STAT_RXRDY (1u << 0)
#define LPC8XX_USART_STAT_TXRDY (1u << 2)
#define LPC8XX_USART_CFG_ENABLE (1u << 0)
#define LPC8XX_USART_CFG_8N1    (1u << 2)

#define LPC8XX_SPI_STAT_RXRDY   (1u << 0)
#define LPC8XX_SPI_STAT_TXRDY   (1u << 1)
#define LPC8XX_SPI_CFG_ENABLE   (1u << 0)
#define LPC8XX_SPI_CFG_MASTER   (1u << 2)

#define LPC8XX_SWM_PIN_DISABLED (0xFFu)

typedef struct {
    volatile uint32_t SYSMEMREMAP;
    volatile uint32_t PRESETCTRL0;
    volatile uint32_t PRESETCTRL1;
    volatile uint32_t reserved0[7];
    volatile uint32_t SYSPLLCTRL;
    volatile uint32_t SYSPLLSTAT;
    volatile uint32_t reserved1[4];
    volatile uint32_t SYSOSCCTRL;
    volatile uint32_t WDTOSCCTRL;
    volatile uint32_t FROOSCCTRL;
    volatile uint32_t reserved2[5];
    volatile uint32_t SYSRSTSTAT;
    volatile uint32_t reserved3[3];
    volatile uint32_t SYSPLLCLKSEL;
    volatile uint32_t SYSPLLCLKUEN;
    volatile uint32_t MAINCLKSEL;
    volatile uint32_t MAINCLKUEN;
    volatile uint32_t SYSAHBCLKDIV;
    volatile uint32_t reserved4;
    volatile uint32_t SYSAHBCLKCTRL0;
} LPC8XX_SYSCON_Type;

typedef struct {
    volatile uint32_t PIO[32];
} LPC8XX_IOCON_Type;

typedef struct {
    volatile uint32_t PINASSIGN[16];
    volatile uint32_t PINENABLE0;
} LPC8XX_SWM_Type;

typedef struct {
    volatile uint32_t CFG;
    volatile uint32_t CTL;
    volatile uint32_t STAT;
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RXDAT;
    volatile uint32_t RXDATSTAT;
    volatile uint32_t TXDAT;
    volatile uint32_t BRG;
    volatile uint32_t INTSTAT;
    volatile uint32_t OSR;
} LPC8XX_USART_Type;

typedef struct {
    volatile uint32_t CFG;
    volatile uint32_t DLY;
    volatile uint32_t STAT;
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RXDAT;
    volatile uint32_t TXDATCTL;
    volatile uint32_t TXDAT;
    volatile uint32_t TXCTRL;
    volatile uint32_t DIV;
    volatile uint32_t INTSTAT;
} LPC8XX_SPI_Type;

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} LPC8XX_SYSTICK_Type;

#define LPC8XX_SYSCON  ((LPC8XX_SYSCON_Type *)(uintptr_t)LPC8XX_SYSCON_BASE)
#define LPC8XX_IOCON   ((LPC8XX_IOCON_Type *)(uintptr_t)LPC8XX_IOCON_BASE)
#define LPC8XX_SWM     ((LPC8XX_SWM_Type *)(uintptr_t)LPC8XX_SWM_BASE)
#define LPC8XX_USART0  ((LPC8XX_USART_Type *)(uintptr_t)LPC8XX_USART0_BASE)
#define LPC8XX_SPI0    ((LPC8XX_SPI_Type *)(uintptr_t)LPC8XX_SPI0_BASE)
#define LPC8XX_SYSTICK ((LPC8XX_SYSTICK_Type *)(uintptr_t)LPC8XX_SYSTICK_BASE)

static inline volatile uint32_t *lpc8xx_gpio_dir(uint8_t port) {
    return (volatile uint32_t *)((uintptr_t)LPC8XX_GPIO_BASE + 0x2000u + ((uintptr_t)port * 4u));
}

static inline volatile uint32_t *lpc8xx_gpio_pin(uint8_t port) {
    return (volatile uint32_t *)((uintptr_t)LPC8XX_GPIO_BASE + 0x2100u + ((uintptr_t)port * 4u));
}

static inline volatile uint32_t *lpc8xx_gpio_set(uint8_t port) {
    return (volatile uint32_t *)((uintptr_t)LPC8XX_GPIO_BASE + 0x2200u + ((uintptr_t)port * 4u));
}

static inline volatile uint32_t *lpc8xx_gpio_clr(uint8_t port) {
    return (volatile uint32_t *)((uintptr_t)LPC8XX_GPIO_BASE + 0x2280u + ((uintptr_t)port * 4u));
}

static inline uint8_t lpc8xx_swm_pin(uint8_t port, uint8_t bit) {
    return (uint8_t)((port * 32u) + bit);
}

static inline void lpc8xx_enable_clock(uint32_t bit) {
    LPC8XX_SYSCON->SYSAHBCLKCTRL0 |= (1u << bit);
}

static inline void lpc8xx_reset_peripheral(uint32_t bit) {
    LPC8XX_SYSCON->PRESETCTRL0 &= ~(1u << bit);
    LPC8XX_SYSCON->PRESETCTRL0 |= (1u << bit);
}

static inline void lpc8xx_swm_assign(uint8_t function_index, uint8_t pin) {
    const uint8_t reg = (uint8_t)(function_index / 4u);
    const uint8_t shift = (uint8_t)((function_index % 4u) * 8u);
    const uint32_t mask = 0xFFu << shift;
    LPC8XX_SWM->PINASSIGN[reg] =
        (LPC8XX_SWM->PINASSIGN[reg] & ~mask) | ((uint32_t)pin << shift);
}

static inline void lpc8xx_basic_peripheral_init(void) {
    lpc8xx_enable_clock(LPC8XX_AHBCLK_GPIO0);
    lpc8xx_enable_clock(LPC8XX_AHBCLK_IOCON);
    lpc8xx_enable_clock(LPC8XX_AHBCLK_SWM);
}

#ifdef __cplusplus
}
#endif

#endif
