// SPDX-License-Identifier: BSD-3-Clause
#include "Wire.h"

TwoWire Wire;

void TwoWire::begin(void) {}

void TwoWire::begin(uint8_t address) {
    _address = address;
}

void TwoWire::end(void) {}

void TwoWire::setClock(uint32_t clock) {
    _clock = clock;
}

void TwoWire::setWireTimeout(uint32_t timeout, bool reset_with_timeout) {
    (void)timeout;
    (void)reset_with_timeout;
    _timeoutFlag = false;
}

bool TwoWire::getWireTimeoutFlag(void) const {
    return _timeoutFlag;
}

void TwoWire::clearWireTimeoutFlag(void) {
    _timeoutFlag = false;
}

void TwoWire::beginTransmission(uint8_t address) {
    _address = address;
}

size_t TwoWire::write(uint8_t data) {
    (void)data;
    return 1u;
}

size_t TwoWire::write(const uint8_t *data, size_t quantity) {
    (void)data;
    return quantity;
}

uint8_t TwoWire::endTransmission(void) {
    return endTransmission(true);
}

uint8_t TwoWire::endTransmission(bool stopBit) {
    (void)stopBit;
    return 0u;
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity) {
    return requestFrom(address, quantity, true);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, bool stopBit) {
    (void)address;
    (void)quantity;
    (void)stopBit;
    return 0u;
}

int TwoWire::available(void) {
    return 0;
}

int TwoWire::read(void) {
    return -1;
}

int TwoWire::peek(void) {
    return -1;
}

void TwoWire::flush(void) {}
