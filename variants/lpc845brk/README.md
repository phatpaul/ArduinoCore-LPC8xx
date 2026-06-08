# variants/lpc845brk

Board variant for the NXP LPC845-BRK breakout board.

- FQBN: `zackees:lpc8xx:lpc845brk`
- MCU family: LPC845, 64 KB flash, 16 KB SRAM
- Default upload path: CMSIS-DAP/SWD through OpenOCD
- Board model: breakout/prototyping board, not an Arduino UNO shield target

The current pin table exposes direct GPIO indexes with per-pin capability
metadata so sketches and compile checks can distinguish GPIO, ADC, PWM, and
interrupt-capable pins. Header-label verification against the board manual is
still required before this variant should be treated as a final physical pin
map.
