MEMORY
{
  FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 32K
  RAM   (rwx) : ORIGIN = 0x10000000, LENGTH = 4K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);
_Min_Heap_Size = 0x100;
_Min_Stack_Size = 0x400;

INCLUDE linker_scripts/gcc/lpc8xx_common.ld
