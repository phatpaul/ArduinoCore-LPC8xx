MEMORY
{
  FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 64K
  RAM   (rwx) : ORIGIN = 0x10000000, LENGTH = 16K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);
_Min_Heap_Size = 0x400;
_Min_Stack_Size = 0x800;

INCLUDE linker_scripts/gcc/lpc8xx_common.ld
