#include "debug_console.h"
#include <stdarg.h>
#include "common.h"
#include "SEGGER_RTT.h"

#if DEBUG_OUTPUT_SINK != 3
static cyhal_uart_t debug_uart;
static uint8_t      rx_buf[DEBUG_MAX_BUF_LENGTH];
#endif
static uint8_t tx_buf[DEBUG_MAX_BUF_LENGTH];

static TX_MUTEX         debug_mutex;
static volatile uint8_t use_mutex = 0;

void debug_console_init(void) {
#if DEBUG_OUTPUT_SINK == 3
	SEGGER_RTT_Init();
#else
	cy_rslt_t              rslt        = 0;
	const cyhal_uart_cfg_t uart_config = {
		.data_bits      = 8,
		.stop_bits      = 1,
		.parity         = CYHAL_UART_PARITY_NONE,
		.rx_buffer      = rx_buf,
		.rx_buffer_size = DEBUG_MAX_BUF_LENGTH};
#if DEBUG_OUTPUT_SINK == 2
	rslt |= cyhal_uart_init(&debug_uart, P10_1, P10_0, NC, NC, NULL, &uart_config);
#else
	rslt |= cyhal_uart_init(&debug_uart, CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, NC, NC, NULL, &uart_config);
#endif
	rslt |= cyhal_uart_set_baud(&debug_uart, DEBUG_UART_BAUD_RATE, NULL);
	if (rslt != CY_RSLT_SUCCESS) {
		CY_ASSERT(0);
	}
#endif
}

void debug_console_init_mutex(void) {
	UINT status = tx_mutex_create(&debug_mutex, "Debug Console Mutex", TX_INHERIT);
	if (status == TX_SUCCESS) {
		use_mutex = 1;
	}
}

int _write(int fd, char *ptr, int len) {
	(void)fd;
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
}

void __LOG_printf(const char *func, int line, const char *fmt, ...) {
	int len = 0;
	len     = snprintf((char *)tx_buf, sizeof(tx_buf), "(%s:%i) ", func, line);
	va_list args;
	va_start(args, fmt);
	len += vsnprintf((char *)tx_buf + len, sizeof(tx_buf) - len, fmt, args);
	va_end(args);
	if (len > 0) {
		_write(0, (char *)tx_buf, len);
	}
}