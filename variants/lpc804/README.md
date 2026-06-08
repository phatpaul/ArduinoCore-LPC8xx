# variants/lpc804

LPC804 variant. Reference board: LPCXpresso804.

- MCU: LPC804M101JDH24-compatible register layout
- Flash: 32 KB
- SRAM: 4 KB
- Default clock used by the core: 15 MHz
- Default Arduino pins map directly to GPIO port 0 bit numbers.
- Default serial pins: TX `P0_4`, RX `P0_0`
- Default SPI0 pins: SSEL `P0_10`, MOSI `P0_11`, MISO `P0_12`, SCK `P0_13`

The direct GPIO mapping is deliberately simple for the first vendorable core.
Board-specific aliases can be layered on later once hardware pinout testing is
complete.
