#include "debug_console.h"
#include <stdarg.h>
#include <string.h>
#include "common.h"
#include "SEGGER_RTT.h"

#if !(DEBUG_OUTPUT_SINK == 3) && (DEBUG_OUTPUT_SINK < 4)
static cyhal_uart_t debug_uart;
#if (DEBUG_OUTPUT_SINK == 2)
extern const cyhal_uart_configurator_t scb_1_hal_config;
#else
extern const cyhal_uart_configurator_t scb_5_hal_config;
#endif // (DEBUG_OUTPUT_SINK == 2)
uint8_t rx_buf[DEBUG_MAX_BUF_LENGTH];
#endif // !(DEBUG_OUTPUT_SINK == 3) && (DEBUG_OUTPUT_SINK < 4)

#if (DEBUG_OUTPUT_SINK < 4)
static TX_MUTEX         debug_mutex;
static volatile uint8_t use_mutex = 0;
#endif

void debug_console_init(void) {
#if (DEBUG_OUTPUT_SINK < 4)
#if (DEBUG_OUTPUT_SINK == 3)
	SEGGER_RTT_Init();
#else
	cy_rslt_t rslt = 0;

#if (DEBUG_OUTPUT_SINK == 2)
	rslt |= cyhal_uart_init_cfg(&debug_uart, &scb_1_hal_config);
#else
	rslt |= cyhal_uart_init_cfg(&debug_uart, &scb_5_hal_config);
#endif // (DEBUG_OUTPUT_SINK == 2)
	// rslt |= cyhal_uart_set_baud(&debug_uart, DEBUG_UART_BAUD_RATE, NULL);
	if (rslt != CY_RSLT_SUCCESS) {
		CY_ASSERT(0);
	}
#endif // (DEBUG_OUTPUT_SINK == 3)
#endif // (DEBUG_OUTPUT_SINK < 4)
}

void debug_console_init_mutex(void) {
#if (DEBUG_OUTPUT_SINK < 4)
	UINT status = tx_mutex_create(&debug_mutex, "Debug Console Mutex", TX_INHERIT);
	if (status == TX_SUCCESS) {
		use_mutex = 1;
	}
#endif
}

int _write(int fd, char *ptr, int len) {
	(void)fd;
#if (DEBUG_OUTPUT_SINK < 4)
	size_t sz = len;
	if (use_mutex) {
		UINT status = tx_mutex_get(&debug_mutex, DEBUG_CONSOLE_MUTEX_WAIT);
		if (status == TX_SUCCESS) {
#if DEBUG_OUTPUT_SINK == 3
			SEGGER_RTT_Write(0, (void *)ptr, sz);
#else
			cyhal_uart_write(&debug_uart, (void *)ptr, &sz);
#endif
			tx_mutex_put(&debug_mutex);
		} // If we can't take the mutex we just drop the message
	} else {
#if DEBUG_OUTPUT_SINK == 3
		SEGGER_RTT_Write(0, (void *)ptr, sz);
#else
		cyhal_uart_write(&debug_uart, (void *)ptr, &sz);
#endif
	}
	return sz;
#else
	(void)ptr;
	return len;
#endif // (DEBUG_OUTPUT_SINK < 4)
}

#if (DEBUG_OUTPUT_SINK < 4)
static uint8_t tx_buf[DEBUG_MAX_BUF_LENGTH];
#endif
void __LOG_printf(const char *func, int line, const char *fmt, ...) {
#if (DEBUG_OUTPUT_SINK < 4)
	int len = 0;
	len     = snprintf((char *)tx_buf, sizeof(tx_buf), "(%s:%i) ", func, line);
	va_list args;
	va_start(args, fmt);
	len += vsnprintf((char *)tx_buf + len, sizeof(tx_buf) - len, fmt, args);
	va_end(args);
	if (len > 0) {
		_write(0, (char *)tx_buf, len);
	}
#else
	(void)func;
	(void)line;
	(void)fmt;
#endif
}

void LOG_str(const char *s) {
#if (DEBUG_OUTPUT_SINK < 4)
	int len = strlen(s);
	_write(0, (char *)s, len);
#else
	(void)s;
#endif
}