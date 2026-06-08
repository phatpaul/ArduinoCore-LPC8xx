// SPDX-License-Identifier: BSD-3-Clause
#include <Arduino.h>

#ifdef LPC8XX_ENABLE_FASTLED_EXAMPLE
#include <FastLED.h>

#define DATA_PIN PIN_SPI_MOSI
#define CLOCK_PIN PIN_SPI_SCK
#define NUM_LEDS 1

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
}

void loop() {
    leds[0] = CRGB::Blue;
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
