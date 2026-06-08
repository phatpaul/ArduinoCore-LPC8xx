# variants/lpcxpresso845max

Board variant for the NXP LPCXpresso845-MAX board.

- FQBN: `zackees:lpc8xx:lpcxpresso845max`
- MCU family: LPC845, 64 KB flash, 16 KB SRAM
- Default upload path: CMSIS-DAP/SWD through OpenOCD
- Board model: 3.3 V Arduino-header-compatible evaluation board

This variant is exposed so Arduino CLI can list and compile the requested
board ID. Its direct GPIO pin table is provisional until the LPCXpresso845-MAX
Arduino-header map is verified against the board manual.
