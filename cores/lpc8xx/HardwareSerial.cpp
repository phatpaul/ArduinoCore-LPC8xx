// SPDX-License-Identifier: BSD-3-Clause
#include "HardwareSerial.h"
#include "lpc8xx_registers.h"

HardwareSerial Serial;

static const uint8_t SWM_U0_TXD = 0u;
static const uint8_t SWM_U0_RXD = 1u;

static uint32_t serial_brg(uint32_t baud) {
    if (baud == 0u) {
        baud = 115200u;
    }
    const uint32_t div = (F_CPU + (baud * 8u)) / (baud * 16u);
    return div > 0u ? div - 1u : 0u;
}

void HardwareSerial::begin(uint32_t baud) {
    begin(baud, SERIAL_8N1);
}

void HardwareSerial::begin(uint32_t baud, uint16_t config) {
    (void)config;
    lpc8xx_basic_peripheral_init();
    lpc8xx_enable_clock(LPC8XX_AHBCLK_USART0);
    lpc8xx_reset_peripheral(LPC8XX_PRESET_USART0);

    const uint8_t tx = lpc8xx_swm_pin(g_APinDescription[PIN_SERIAL_TX].port,
                                      g_APinDescription[PIN_SERIAL_TX].bit);
    const uint8_t rx = lpc8xx_swm_pin(g_APinDescription[PIN_SERIAL_RX].port,
                                      g_APinDescription[PIN_SERIAL_RX].bit);
    lpc8xx_swm_assign(SWM_U0_TXD, tx);
    lpc8xx_swm_assign(SWM_U0_RXD, rx);

    LPC8XX_USART0->CFG = 0u;
    LPC8XX_USART0->OSR = 15u;
    LPC8XX_USART0->BRG = serial_brg(baud);
    LPC8XX_USART0->CFG = LPC8XX_USART_CFG_8N1 | LPC8XX_USART_CFG_ENABLE;
}

void HardwareSerial::end(void) {
    LPC8XX_USART0->CFG = 0u;
}

int HardwareSerial::available(void) {
    return (LPC8XX_USART0->STAT & LPC8XX_USART_STAT_RXRDY) ? 1 : 0;
}

int HardwareSerial::availableForWrite(void) {
    return (LPC8XX_USART0->STAT & LPC8XX_USART_STAT_TXRDY) ? 1 : 0;
}

int HardwareSerial::read(void) {
    if (!available()) {
        return -1;
    }
    return (int)(LPC8XX_USART0->RXDAT & 0xFFu);
}

int HardwareSerial::peek(void) {
    return available() ? (int)(LPC8XX_USART0->RXDAT & 0xFFu) : -1;
}

void HardwareSerial::flush(void) {
    while ((LPC8XX_USART0->STAT & LPC8XX_USART_STAT_TXRDY) == 0u) {
    }
}

size_t HardwareSerial::write(uint8_t b) {
    while ((LPC8XX_USART0->STAT & LPC8XX_USART_STAT_TXRDY) == 0u) {
    }
    LPC8XX_USART0->TXDAT = b;
    return 1u;
}

size_t HardwareSerial::write(const uint8_t *buf, size_t len) {
    size_t written = 0;
    for (size_t i = 0; i < len; ++i) {
        written += write(buf[i]);
    }
    return written;
}

HardwareSerial::operator bool(void) const {
    return true;
}
