// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>

#ifdef LPC8XX_ENABLE_FASTLED_EXAMPLE
#include <FastLED.h>

#define DATA_PIN 6
#define NUM_LEDS 1

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
    leds[0] = CRGB::Red;
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(500);
}
#else
void setup() {}
void loop() {}
#endif
