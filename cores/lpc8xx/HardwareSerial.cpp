// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — HardwareSerial implementation stubs
//
// TODO: implement against MCUXpresso SDK
//   - begin(baud) → SWM_SetMovablePinSelect(SWM_USART0_TXD_*) +
//                   SWM_SetMovablePinSelect(SWM_USART0_RXD_*) +
//                   USART_Init(USART0, &cfg, srcclk)
//   - write(b)    → USART_WriteByte(USART0, b)  (blocking variant for v1)
//   - read()      → USART_ReadByte(USART0) gated on USART_GetStatusFlags
//   - available() → ring-buffer fill (filled by USART0_IRQHandler)
#include "HardwareSerial.h"

HardwareSerial Serial;

void HardwareSerial::begin(uint32_t baud) { (void)baud; }
void HardwareSerial::end(void) {}
int HardwareSerial::available(void) { return 0; }
int HardwareSerial::read(void) { return -1; }
size_t HardwareSerial::write(uint8_t b) { (void)b; return 1; }

size_t HardwareSerial::write(const uint8_t *buf, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        write(buf[i]);
    }
    return len;
}

size_t HardwareSerial::print(const char *s) {
    size_t n = 0;
    while (s && *s) { write(static_cast<uint8_t>(*s++)); ++n; }
    return n;
}

size_t HardwareSerial::print(int n) { (void)n; return 0; }
size_t HardwareSerial::println(const char *s) { size_t n = print(s); n += println(); return n; }
size_t HardwareSerial::println(int n) { print(n); return println(); }
size_t HardwareSerial::println(void) { write('\r'); write('\n'); return 2; }
