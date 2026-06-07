# cores/lpc8xx

Shared Arduino API surface for the LPC8xx family. Files here are
MCU-agnostic; per-MCU details (pin mux, clock tree, vector table) live
under `variants/<part>/`.

| File | Role |
|---|---|
| `Arduino.h` | Umbrella header. Pulls in `HardwareSerial.h` + `SPI.h`. |
| `wiring_digital.c` | `pinMode`, `digitalWrite`, `digitalRead` |
| `wiring_time.c` | `delay`, `delayMicroseconds`, `millis`, `micros` |
| `HardwareSerial.{h,cpp}` | `Serial` (USART0) |
| `SPI.{h,cpp}` | `SPI` (SPI0) |
| `main.cpp` | Framework-owned `main()` → `SystemInit` + `setup` + `loop` |

**Status: SKELETON.** All function bodies are TODO stubs that compile to
no-ops. Implementation tracked at
[FastLED/fbuild#479](https://github.com/FastLED/fbuild/issues/479).
