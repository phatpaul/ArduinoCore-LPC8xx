// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx — umbrella header
//
// SKELETON: API shape only. Implementation TODO. See fbuild#479.
#ifndef ARDUINO_CORE_LPC8XX_ARDUINO_H
#define ARDUINO_CORE_LPC8XX_ARDUINO_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// ── Constants ────────────────────────────────────────────────────────
#define HIGH 0x1
#define LOW  0x0

#define INPUT        0x0
#define OUTPUT       0x1
#define INPUT_PULLUP 0x2

// ── Pin type ─────────────────────────────────────────────────────────
typedef uint8_t pin_size_t;
typedef uint8_t PinStatus;
typedef uint8_t PinMode;

// ── GPIO ─────────────────────────────────────────────────────────────
void pinMode(pin_size_t pin, PinMode mode);
void digitalWrite(pin_size_t pin, PinStatus value);
PinStatus digitalRead(pin_size_t pin);

// ── Timing ───────────────────────────────────────────────────────────
void delay(uint32_t ms);
void delayMicroseconds(uint32_t us);
uint32_t millis(void);
uint32_t micros(void);

// ── Framework entry points (user-provided) ──────────────────────────
void setup(void);
void loop(void);

#ifdef __cplusplus
}

#include "HardwareSerial.h"
#include "SPI.h"

#endif // __cplusplus

#endif // ARDUINO_CORE_LPC8XX_ARDUINO_H
