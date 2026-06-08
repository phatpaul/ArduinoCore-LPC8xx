# examples/

Representative Arduino sketches for package compile checks and hardware
bring-up.

| Example | Purpose |
|---|---|
| `Blink` | GPIO output and SysTick delay smoke test |
| `BlinkWithoutDelay` | `millis()` timing |
| `Button` | GPIO input with pull-up |
| `AnalogReadSerial` | `Serial` plus analog API surface |
| `Fading` | PWM/`analogWrite` API surface |
| `ToneMelody` | `tone` / `noTone` API surface |
| `Serial` | `HardwareSerial` as `Stream`/`Print` |
| `SPILoopback` | SPI transaction and transfer API surface |
| `I2CScanner` | `Wire` API surface |
| `FastLEDClocklessSmoke` | Guarded 3-wire FastLED smoke sketch |
| `FastLEDSpiSmoke` | Guarded 4-wire FastLED/SPI smoke sketch |

The FastLED sketches compile as no-ops by default. Define
`LPC8XX_ENABLE_FASTLED_EXAMPLE` and install FastLED to exercise those paths.
