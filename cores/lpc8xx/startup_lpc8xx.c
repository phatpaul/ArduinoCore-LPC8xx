// SPDX-License-Identifier: BSD-3-Clause
#include <stdint.h>

#include "Arduino.h"

extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

extern uint32_t SystemCoreClock;
extern int main(void);
extern void __libc_init_array(void);

__attribute__((section(".crp"), used))
const uint32_t lpc8xx_crp_word = 0xFFFFFFFFu;

void Default_Handler(void) {
    for (;;) {
    }
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));

void SystemInit(void) {
    SystemCoreClock = F_CPU;
}

void Reset_Handler(void) {
    uint32_t *src = &_sidata;
    for (uint32_t *dst = &_sdata; dst < &_edata;) {
        *dst++ = *src++;
    }

    for (uint32_t *dst = &_sbss; dst < &_ebss;) {
        *dst++ = 0u;
    }

    SystemInit();
    __libc_init_array();
    (void)main();

    for (;;) {
    }
}
