// SPDX-License-Identifier: BSD-3-Clause
// Minimal freestanding C++ runtime support for bare-metal builds.
#include <stddef.h>

extern "C" {

void *__dso_handle __attribute__((weak)) = 0;
char end __attribute__((weak));
char _end __attribute__((weak));

void __cxa_pure_virtual(void) {
    for (;;) {
    }
}

}

void operator delete(void *ptr) noexcept {
    (void)ptr;
}

void operator delete(void *ptr, unsigned int size) noexcept {
    (void)ptr;
    (void)size;
}

void operator delete(void *ptr, unsigned long size) noexcept {
    (void)ptr;
    (void)size;
}

void operator delete[](void *ptr) noexcept {
    (void)ptr;
}

void operator delete[](void *ptr, unsigned int size) noexcept {
    (void)ptr;
    (void)size;
}

void operator delete[](void *ptr, unsigned long size) noexcept {
    (void)ptr;
    (void)size;
}
