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

static size_t print_unsigned(HardwareSerial *serial, unsigned long value) {
    char buf[10];
    size_t len = 0;
    do {
        buf[len++] = (char)('0' + (value % 10u));
        value /= 10u;
    } while (value != 0u && len < sizeof(buf));

    size_t written = 0;
    while (len > 0u) {
        written += serial->write((uint8_t)buf[--len]);
    }
    return written;
}

void HardwareSerial::begin(uint32_t baud) {
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

size_t HardwareSerial::print(const char *s) {
    size_t n = 0;
    while (s && s[n] != '\0') {
        ++n;
    }
    return write((const uint8_t *)s, n);
}

size_t HardwareSerial::print(int n) {
    if (n < 0) {
        return write((uint8_t)'-') + print_unsigned(this, (unsigned long)(-n));
    }
    return print_unsigned(this, (unsigned long)n);
}

size_t HardwareSerial::print(unsigned int n) {
    return print_unsigned(this, (unsigned long)n);
}

size_t HardwareSerial::print(long n) {
    if (n < 0) {
        return write((uint8_t)'-') + print_unsigned(this, (unsigned long)(-n));
    }
    return print_unsigned(this, (unsigned long)n);
}

size_t HardwareSerial::print(unsigned long n) {
    return print_unsigned(this, n);
}

size_t HardwareSerial::println(const char *s) {
    return print(s) + println();
}

size_t HardwareSerial::println(int n) {
    return print(n) + println();
}

size_t HardwareSerial::println(unsigned int n) {
    return print(n) + println();
}

size_t HardwareSerial::println(long n) {
    return print(n) + println();
}

size_t HardwareSerial::println(unsigned long n) {
    return print(n) + println();
}

size_t HardwareSerial::println(void) {
    static const uint8_t newline[] = {'\r', '\n'};
    return write(newline, sizeof(newline));
}
