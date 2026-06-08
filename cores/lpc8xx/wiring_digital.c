// SPDX-License-Identifier: BSD-3-Clause
#include "Arduino.h"
#include "lpc8xx_registers.h"

#define IOCON_MODE_MASK   (0x3u << 3)
#define IOCON_MODE_INACT  (0x0u << 3)
#define IOCON_MODE_PULLUP (0x2u << 3)

static int lookup_pin(pin_size_t pin, lpc8xx_pin_info_t *out) {
    if (pin >= variant_pin_count) {
        return 0;
    }
    *out = g_APinDescription[pin];
    return out->bit < 32u;
}

void pinMode(pin_size_t pin, PinMode mode) {
    lpc8xx_pin_info_t info;
    if (!lookup_pin(pin, &info)) {
        return;
    }

    lpc8xx_basic_peripheral_init();

    uint32_t iocon = LPC8XX_IOCON->PIO[info.bit] & ~IOCON_MODE_MASK;
    if (mode == INPUT_PULLUP) {
        iocon |= IOCON_MODE_PULLUP;
    } else {
        iocon |= IOCON_MODE_INACT;
    }
    LPC8XX_IOCON->PIO[info.bit] = iocon;

    const uint32_t mask = 1u << info.bit;
    volatile uint32_t *dir = lpc8xx_gpio_dir(info.port);
    if (mode == OUTPUT) {
        *dir |= mask;
    } else {
        *dir &= ~mask;
    }
}

void digitalWrite(pin_size_t pin, PinStatus value) {
    lpc8xx_pin_info_t info;
    if (!lookup_pin(pin, &info)) {
        return;
    }

    const uint32_t mask = 1u << info.bit;
    if (value == LOW) {
        *lpc8xx_gpio_clr(info.port) = mask;
    } else {
        *lpc8xx_gpio_set(info.port) = mask;
    }
}

PinStatus digitalRead(pin_size_t pin) {
    lpc8xx_pin_info_t info;
    if (!lookup_pin(pin, &info)) {
        return LOW;
    }

    const uint32_t mask = 1u << info.bit;
    return ((*lpc8xx_gpio_pin(info.port) & mask) != 0u) ? HIGH : LOW;
}
