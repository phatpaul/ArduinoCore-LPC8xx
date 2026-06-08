ENTRY(Reset_Handler)

SECTIONS
{
  .vectors ORIGIN(FLASH) :
  {
    LONG(_estack)
    LONG(Reset_Handler + 1)
    LONG(NMI_Handler + 1)
    LONG(HardFault_Handler + 1)
    LONG(0)
    LONG(0)
    LONG(0)
    LONG(0 - (_estack + (Reset_Handler + 1) + (NMI_Handler + 1) + (HardFault_Handler + 1)))
    LONG(0)
    LONG(0)
    LONG(0)
    LONG(SVC_Handler + 1)
    LONG(0)
    LONG(0)
    LONG(PendSV_Handler + 1)
    LONG(SysTick_Handler + 1)
    LONG(Default_Handler + 1) /* IRQ0 */
    LONG(Default_Handler + 1) /* IRQ1 */
    LONG(Default_Handler + 1) /* IRQ2 */
    LONG(Default_Handler + 1) /* IRQ3 */
    LONG(Default_Handler + 1) /* IRQ4 */
    LONG(Default_Handler + 1) /* IRQ5 */
    LONG(Default_Handler + 1) /* IRQ6 */
    LONG(Default_Handler + 1) /* IRQ7 */
    LONG(Default_Handler + 1) /* IRQ8 */
    LONG(Default_Handler + 1) /* IRQ9 */
    LONG(Default_Handler + 1) /* IRQ10 */
    LONG(Default_Handler + 1) /* IRQ11 */
    LONG(Default_Handler + 1) /* IRQ12 */
    LONG(Default_Handler + 1) /* IRQ13 */
    LONG(Default_Handler + 1) /* IRQ14 */
    LONG(Default_Handler + 1) /* IRQ15 */
    LONG(Default_Handler + 1) /* IRQ16 */
    LONG(Default_Handler + 1) /* IRQ17 */
    LONG(Default_Handler + 1) /* IRQ18 */
    LONG(Default_Handler + 1) /* IRQ19 */
    LONG(Default_Handler + 1) /* IRQ20 */
    LONG(Default_Handler + 1) /* IRQ21 */
    LONG(Default_Handler + 1) /* IRQ22 */
    LONG(Default_Handler + 1) /* IRQ23 */
    LONG(Default_Handler + 1) /* IRQ24 */
    LONG(Default_Handler + 1) /* IRQ25 */
    LONG(Default_Handler + 1) /* IRQ26 */
    LONG(Default_Handler + 1) /* IRQ27 */
    LONG(Default_Handler + 1) /* IRQ28 */
    LONG(Default_Handler + 1) /* IRQ29 */
    LONG(Default_Handler + 1) /* IRQ30 */
    LONG(Default_Handler + 1) /* IRQ31 */
  } > FLASH

  .crp 0x000002FC :
  {
    KEEP(*(.crp))
  } > FLASH = 0xFF

  .text :
  {
    KEEP(*(.after_vectors))
    *(.text*)
    *(.rodata*)
    KEEP(*(.init))
    KEEP(*(.fini))
    . = ALIGN(4);
    KEEP(*(.preinit_array*))
    KEEP(*(.init_array*))
    KEEP(*(.fini_array*))
    . = ALIGN(4);
    _etext = .;
  } > FLASH

  _sidata = LOADADDR(.data);

  .data : AT(_etext)
  {
    . = ALIGN(4);
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } > RAM

  .bss (NOLOAD) :
  {
    . = ALIGN(4);
    _sbss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } > RAM

  .heap_stack (NOLOAD) :
  {
    . = ALIGN(8);
    PROVIDE(end = .);
    PROVIDE(_end = .);
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } > RAM
}

PROVIDE(NMI_Handler = Default_Handler);
PROVIDE(HardFault_Handler = Default_Handler);
PROVIDE(SVC_Handler = Default_Handler);
PROVIDE(PendSV_Handler = Default_Handler);
