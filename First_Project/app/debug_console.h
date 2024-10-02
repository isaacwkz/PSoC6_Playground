#ifndef DEBUG_CONSOLE_H
#define DEBUG_CONSOLE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define DEBUG_OUTPUT_TO_CMSIS_DAP

#define DEBUG_MAX_BUF_LENGTH 100
#define DEBUG_UART_BAUD_RATE 1000000

void debug_console_init(void);

void __LOG_printf(const char *func, int line, const char *fmt, ...);

#endif