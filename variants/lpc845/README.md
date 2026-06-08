# variants/lpc845

Shared LPC845 MCU-level variant data. Arduino FQBNs use the board-named
`variants/lpc845brk` and `variants/lpcxpresso845max` wrappers.

- MCU: LPC845M301JBD48-compatible register layout
- Flash: 64 KB
- SRAM: 16 KB
- Default clock used by the core: 30 MHz
- Default Arduino pins map directly to GPIO port 0 bit numbers and include
  capability metadata.
- Default serial pins: TX `P0_4`, RX `P0_0`
- Default SPI0 pins: SSEL `P0_10`, MOSI `P0_11`, MISO `P0_12`, SCK `P0_13`
- Default Wire pins: SDA `P0_16`, SCL `P0_17`

The direct GPIO mapping is provisional. LPC845-BRK is a breakout target;
LPCXpresso845-MAX needs a separate Arduino-header audit before its physical pin
labels are final.
