# ArduinoCore-LPC8xx

An Arduino-compatible API for NXP LPC8xx microcontrollers (Cortex-M0+).

> **Status: SKELETON.** Directory layout and stub headers are in place. No
> implementation yet. Tracked at
> [FastLED/fbuild#479](https://github.com/FastLED/fbuild/issues/479).

## Target parts

Initial targets:

- **LPC845** — 64 KB Flash, 16 KB RAM, Cortex-M0+ @ 30 MHz
- **LPC804** — 32 KB Flash, 4 KB RAM, Cortex-M0+ @ 15 MHz

The shared `cores/lpc8xx/` directory holds the Arduino API surface; each
MCU gets its own `variants/<part>/` directory with pin-map and clock-tree
specifics. New LPC8xx parts (LPC810/812/824/844 etc.) can be added by
contributing a new `variants/<part>/`.

## Why this exists

The official `nxplpc` PlatformIO platform supports only **mbed** and
**Zephyr** — no Arduino. The existing community Arduino-on-LPC efforts
either target the wrong subfamily (LPC810/812/824 in
[`bobc/OpenLasp`](https://github.com/bobc/OpenLasp),
[`julbouln/lpc_8xx_base`](https://github.com/julbouln/lpc_8xx_base)) or
are unfinished skeletons ([`dferbas/NXPduino`](https://github.com/dferbas/NXPduino)).
There is no maintained Arduino core for LPC845 or LPC804 anywhere.

This repo fills that gap by polyfilling the Arduino API on top of the NXP
**MCUXpresso SDK** (the official C HAL).

## Minimum API surface

The deliverable is the subset of Arduino that
[FastLED](https://github.com/FastLED/FastLED) needs:

| Category | Functions |
|---|---|
| Entry points | framework-owned `main()` → `setup()` + `loop()` |
| GPIO | `pinMode`, `digitalWrite`, `digitalRead` |
| Timing | `delay`, `delayMicroseconds`, `millis`, `micros` |
| SPI | `SPI` class — `begin`, `transfer`, `setClockDivider`, `setBitOrder`, `setDataMode` |
| Serial | `Serial` (UART0) — `begin`, `print`, `println`, `available`, `read`, `write` |
| Umbrella | `Arduino.h` pulls all of the above in |

**Out of scope** (for now): `Wire` (I2C), `analogRead`, `analogWrite`,
`attachInterrupt`, `String` class, `tone()`, USB-CDC (chip lacks native
USB).

## Layout

```
ArduinoCore-LPC8xx/
├── cores/
│   └── lpc8xx/             # shared Arduino API for the LPC8xx family
│       ├── Arduino.h
│       ├── wiring_digital.c
│       ├── wiring_time.c
│       ├── HardwareSerial.{h,cpp}
│       ├── SPI.{h,cpp}
│       └── main.cpp
├── variants/
│   ├── lpc845/             # LPC845-specific pin map, clock, vector table
│   └── lpc804/             # LPC804-specific pin map, clock, vector table
└── examples/
    └── Blink/Blink.ino
```

## Substrate

[NXP MCUXpresso SDK](https://mcuxpresso.nxp.com/) — the official C HAL.
Each Arduino API function delegates to MCUXpresso SDK calls (e.g.
`pinMode` → `GPIO_PortInit` + `IOCON_PinMuxSet` + `GPIO_PinSetDir`).

## How fbuild consumes this

fbuild vendors this repo via a `framework-library` package
([example pattern](https://github.com/FastLED/fbuild/blob/main/crates/fbuild-packages/src/library/teensy_core.rs)).
Board JSON
([`lpc845.json`](https://github.com/FastLED/fbuild/blob/main/crates/fbuild-config/assets/boards/json/lpc845.json),
[`lpc804.json`](https://github.com/FastLED/fbuild/blob/main/crates/fbuild-config/assets/boards/json/lpc804.json))
will gain `frameworks: ["arduino"]` once the implementation lands.

## License

BSD-3-Clause. See [LICENSE](LICENSE).
