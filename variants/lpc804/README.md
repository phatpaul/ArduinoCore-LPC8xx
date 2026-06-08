# variants/lpc804

Shared LPC804 MCU-level variant data. The Arduino FQBN uses the board-named
`variants/lpcxpresso804` wrapper.

- MCU: LPC804M101JDH24-compatible register layout
- Flash: 32 KB
- SRAM: 4 KB
- Default clock used by the core: 15 MHz
- Default Arduino pins map directly to GPIO port 0 bit numbers and include
  capability metadata.
- Default serial pins: TX `P0_4`, RX `P0_0`
- Default SPI0 pins: SSEL `P0_10`, MOSI `P0_11`, MISO `P0_12`, SCK `P0_13`
- Default Wire pins: SDA `P0_16`, SCL `P0_17`

The direct GPIO mapping is provisional. The board-named wrapper records the
supported FQBN while the physical Arduino-header labels and jumper/shared-bus
notes are verified against hardware.
