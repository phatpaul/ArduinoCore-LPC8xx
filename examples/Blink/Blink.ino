// SPDX-License-Identifier: BSD-3-Clause
// Blink — the canonical Arduino smoke test.
//
// SKELETON: relies on stubbed pinMode/digitalWrite/delay. When the
// implementation lands, this will toggle an LED on the LPC845-BRK or
// LPCXpresso804 reference boards.

#define LED_BUILTIN 13

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}
