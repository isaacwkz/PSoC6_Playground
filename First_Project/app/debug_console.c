#include "debug_console.h"
#include <stdarg.h>
#include "common.h"

static cyhal_uart_t debug_uart;
static uint8_t      rx_buf[DEBUG_MAX_BUF_LENGTH];
static uint8_t      tx_buf[DEBUG_MAX_BUF_LENGTH];

void debug_console_init(void) {
	cy_rslt_t              rslt        = 0;
	const cyhal_uart_cfg_t uart_config = {
		.data_bits      = 8,
		.stop_bits      = 1,
		.parity         = CYHAL_UART_PARITY_NONE,
		.rx_buffer      = rx_buf,
		.rx_buffer_size = DEBUG_MAX_BUF_LENGTH};
#ifdef DEBUG_OUTPUT_TO_CMSIS_DAP
	rslt |= cyhal_uart_init(&debug_uart, CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, NC, NC, NULL, &uart_config);
#else
	rslt |= cyhal_uart_init(&debug_uart, P10_1, P10_0, NC, NC, NULL, &uart_config);
#endif
	rslt |= cyhal_uart_set_baud(&debug_uart, DEBUG_UART_BAUD_RATE, NULL);
	if (rslt != CY_RSLT_SUCCESS) {
		CY_ASSERT(0);
	}
}

// int _write(int fd, char *ptr, int len) {
// 	(void)fd;
// 	SEGGER_RTT_Write(0, (char *)ptr, len);
// 	return (int)len;
// }

int _write(int fd, char *ptr, int len) {
	(void)fd;
	size_t    sz     = len;
	cy_rslt_t status = CY_RSLT_SUCCESS;
	status           = cyhal_uart_write(&debug_uart, (void *)ptr, &sz);
	if (status == CY_RSLT_SUCCESS) {
		return len;
	} else {
		return 0;
	}
}

void __LOG_printf(const char *func, int line, const char *fmt, ...) {
	int len = 0;
	len     = snprintf((char *)tx_buf, sizeof(tx_buf), "%s (%i):", func, line);
	va_list args;
	va_start(args, fmt);
	len += vsnprintf((char *)tx_buf + len, sizeof(tx_buf) - len, fmt, args);
	va_end(args);
	if (len > 0) {
		_write(0, (char *)tx_buf, len);
	}
}