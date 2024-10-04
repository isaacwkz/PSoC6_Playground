#ifndef DEBUG_CONSOLE_H
#define DEBUG_CONSOLE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// 1 - CMSIS-DAP UART
// 2 - UART1 (J15 header)
// 3 - RTT
// Any other value defaults to CMSIS-DAP UART
#define DEBUG_OUTPUT_SINK 3

#define DEBUG_CONSOLE_MUTEX_WAIT 50

#define DEBUG_MAX_BUF_LENGTH 100
#define DEBUG_UART_BAUD_RATE 1500000

void debug_console_init(void);
void debug_console_init_mutex(void);

void __LOG_printf(const char *func, int line, const char *fmt, ...);
void LOG_printf(const char *fmt, ...);

#define LOG_INFO(format, ...) __LOG_printf(__FUNCTION__, __LINE__, format, ##__VA_ARGS__)

#endif