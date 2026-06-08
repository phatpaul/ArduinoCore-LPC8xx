# variants/

Arduino variants are board profiles. MCU-level support is shared where useful,
but FQBNs use board-named variants:

| Variant | FQBN board ID | MCU | Notes |
|---|---|---|---|
| `lpc845brk/` | `lpc845brk` | LPC845 | Breakout/prototyping board |
| `lpcxpresso804/` | `lpcxpresso804` | LPC804 | 3.3 V Arduino-header board |
| `lpcxpresso845max/` | `lpcxpresso845max` | LPC845 | 3.3 V Arduino-header board, provisional map |

The older `lpc804/` and `lpc845/` directories hold shared MCU-level direct GPIO
tables used by the board variants. Each pin entry records GPIO, ADC, DAC, PWM,
interrupt, voltage, and LED capability flags. Header-label verification against
NXP board manuals remains required before treating these as final physical
board maps.
