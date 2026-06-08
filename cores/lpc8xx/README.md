# cores/lpc8xx

Shared Arduino API surface for the LPC8xx family. Board and MCU details such as
pin maps, capability metadata, and default UART/SPI/I2C pins live under
`variants/<board>/`.

| File | Role |
|---|---|
| `Arduino.h` | Umbrella header; pulls in the selected variant, `HardwareSerial`, `SPI`, and `Wire`. |
| `Print.h`, `Stream.h`, `Printable.h`, `WString.h` | Arduino compatibility surface used by common libraries. |
| `fsl_device_registers.h` | Minimal NXP-style device-header selector for `LPC804.h` / `LPC845.h`. |
| `lpc8xx_registers.h` | Small direct-register layer used by the core implementation. |
| `wiring_digital.c` | `pinMode`, `digitalWrite`, `digitalRead`. |
| `wiring_time.c` | SysTick-backed `delay`, `delayMicroseconds`, `millis`, `micros`. |
| `wiring_analog.c` | `analogRead`, `analogWrite`, and resolution API surface. |
| `WInterrupts.c` | Interrupt API surface and pin capability checks. |
| `Tone.cpp` | `tone` / `noTone` API surface. |
| `Wire.{h,cpp}` | `TwoWire` compile surface; hardware I2C transfer work remains. |
| `HardwareSerial.{h,cpp}` | Blocking USART0 `Serial` implementation. |
| `SPI.{h,cpp}` | Blocking SPI0 implementation with transaction API compatibility. |
| `main.cpp` | Framework-owned `main()` -> `init`, `initVariant`, `setup`, `loop`. |
| `startup_lpc8xx.c` | Arduino-package reset handler, data/BSS init, constructors, CRP word. |
| `lpc8xx_runtime.cpp` | Minimal freestanding C++ runtime symbols and abort/pure-virtual reset handling. |

The implementation is intentionally direct-register and small. GPIO, timing,
USART0, and SPI0 have hardware-backed implementations; Wire, analog, PWM,
interrupt, and tone surfaces compile and document the remaining hardware work.
