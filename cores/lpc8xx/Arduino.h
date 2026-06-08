// SPDX-License-Identifier: BSD-3-Clause
// ArduinoCore-LPC8xx - umbrella header.
#ifndef ARDUINO_CORE_LPC8XX_ARDUINO_H
#define ARDUINO_CORE_LPC8XX_ARDUINO_H

#include <stdint.h>
#include <stddef.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif
#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HIGH 0x1
#define LOW  0x0

#define INPUT        0x0
#define OUTPUT       0x1
#define INPUT_PULLUP 0x2

typedef uint8_t byte;
typedef bool boolean;
typedef uint8_t pin_size_t;
typedef uint8_t PinStatus;
typedef uint8_t PinMode;

void pinMode(pin_size_t pin, PinMode mode);
void digitalWrite(pin_size_t pin, PinStatus value);
PinStatus digitalRead(pin_size_t pin);

void delay(uint32_t ms);
void delayMicroseconds(uint32_t us);
uint32_t millis(void);
uint32_t micros(void);
void yield(void);

void init(void);
void initVariant(void);

void setup(void);
void loop(void);

#ifdef __cplusplus
}

#define F(str) (str)

#include "HardwareSerial.h"
#include "SPI.h"

#endif

#endif
