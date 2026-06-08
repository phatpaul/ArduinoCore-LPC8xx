# Hardware Validation Checklist

Record board, probe firmware, Arduino CLI version, commit SHA, and sketch for
each validation pass.

## LPC845-BRK

- Blink on `LED_BUILTIN`
- `millis()` monotonicity with BlinkWithoutDelay
- USART0 TX/RX through probe VCOM
- SPI0 loopback MOSI to MISO
- I2C scan on the default bus after hardware pins are verified
- ADC read on each documented analog-capable header pin
- PWM output on each documented PWM-capable pin
- `tone()` output on a timer-capable pin
- PININT attach/detach on at least two pins
- OpenOCD/CMSIS-DAP upload and verify
- Image validation with `tools/lpc8xx_image_check.py`

## LPCXpresso804

- Blink on `LED_BUILTIN`
- `millis()` monotonicity with BlinkWithoutDelay
- USART0 TX/RX through probe VCOM
- SPI0 loopback MOSI to MISO
- I2C scan on the Arduino/Grove default bus after header sharing is verified
- ADC read on each documented analog-capable Arduino header pin
- DAC output on documented DAC-capable pin
- PWM output on CTimer-capable pin
- PININT attach/detach within the shared channel limit
- OpenOCD/CMSIS-DAP upload and verify
- Image validation with `tools/lpc8xx_image_check.py`
