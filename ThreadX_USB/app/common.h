#ifndef COMMON_H
#define COMMON_H

#include "cyhal.h"
#include "cybsp.h"

#include "tx_user.h"
#include "tx_api.h"

#include "USB.h"

#include "debug_console.h"

/* Define interrupt priority */
#define USBD_ISR_PRIO     (6U)
#define BG_TIMER_ISR_PRIO (5U)

#endif