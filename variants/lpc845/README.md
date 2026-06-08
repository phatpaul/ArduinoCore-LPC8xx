# variants/lpc845

LPC845 variant. Reference board: LPC845-BRK.

- MCU: LPC845M301JBD48-compatible register layout
- Flash: 64 KB
- SRAM: 16 KB
- Default clock used by the core: 30 MHz
- Default Arduino pins map directly to GPIO port 0 bit numbers.
- Default serial pins: TX `P0_4`, RX `P0_0`
- Default SPI0 pins: SSEL `P0_10`, MOSI `P0_11`, MISO `P0_12`, SCK `P0_13`

The direct GPIO mapping is deliberately simple for the first vendorable core.
Board-specific aliases can be layered on later once hardware pinout testing is
complete.
