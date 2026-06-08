// SPDX-License-Identifier: BSD-3-Clause
#pragma once

#if defined(CPU_LPC845M301JBD48) || defined(__LPC845__) || defined(LPC845)
#ifndef CPU_LPC845M301JBD48
#define CPU_LPC845M301JBD48 1
#endif
#include "LPC845.h"
#elif defined(CPU_LPC804M101JDH24) || defined(__LPC804__) || defined(LPC804)
#ifndef CPU_LPC804M101JDH24
#define CPU_LPC804M101JDH24 1
#endif
#include "LPC804.h"
#else
#error "No supported LPC8xx part selected"
#endif
