# variants/

Per-MCU specialisation directories. Each variant provides:

- `variant.h` — pin-number → port/bit map exposed via the Arduino
  `pin_size_t` index. Also clock-tree constants (FRO frequency, flash
  wait states).
- `variant.cpp` — pin-table definitions + any variant-specific init
  (e.g. clock switching, MRT prescaler).
- `startup_<part>.S` — Reset_Handler + vector table + `SystemInit`.
- `<part>.ld` — linker script (Flash + SRAM layout).

| Variant | MCU | Flash | RAM | Clock |
|---|---|---:|---:|---|
| `lpc845/` | LPC845M301JBD64 | 64 KB | 16 KB | 30 MHz FRO |
| `lpc804/` | LPC804M101JDH24 | 32 KB | 4 KB | 15 MHz FRO |

Adding a new LPC8xx part = create a new subdirectory mirroring the
`lpc845/` layout.
