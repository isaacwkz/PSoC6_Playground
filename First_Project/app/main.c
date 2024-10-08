/******************************************************************************
 * File Name:   main.c
 *
 * Description: This is the source code for Hello World Example using HAL APIs.
 *
 * Related Document: See README.md
 *
 *
 *******************************************************************************
 * Copyright 2022-2024, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 *******************************************************************************/

#include "common.h"

#include "USB_HW_Cypress_PSoC6.h"

#include "usb_device.h"

/*******************************************************************************
 * Macros
 *******************************************************************************/

/*******************************************************************************
 * Global Variables
 *******************************************************************************/
TX_THREAD    thread_0;
TX_THREAD    thread_1;
TX_BYTE_POOL byte_pool_0;
#define DEMO_BYTE_POOL_SIZE 102400
UCHAR memory_area[DEMO_BYTE_POOL_SIZE];
#define DEMO_STACK_SIZE (20480)

/*******************************************************************************
 * Function Prototypes
 *******************************************************************************/
void thread_0_entry(ULONG thread_input);
void thread_1_entry(ULONG thread_input);

TX_SEMAPHORE timer_sem;
void         timer_init(void);

/*******************************************************************************
 * Function Name: main
 ********************************************************************************
 *
 * Parameters:
 *  none
 *
 * Return:
 *  int
 *
 *******************************************************************************/
int main(void) {
	cy_rslt_t result;

#if defined(CY_DEVICE_SECURE)
	cyhal_wdt_t wdt_obj;

	/* Clear watchdog timer so that it doesn't trigger a reset */
	result = cyhal_wdt_init(&wdt_obj, cyhal_wdt_get_max_timeout_ms());
	CY_ASSERT(CY_RSLT_SUCCESS == result);
	cyhal_wdt_free(&wdt_obj);
#endif /* #if defined (CY_DEVICE_SECURE) */

	/* Initialize the device and board peripherals */
	result = cybsp_init();

	/* Board init failed. Stop program execution */
	if (result != CY_RSLT_SUCCESS) {
		CY_ASSERT(0);
	}

	/* Initialize the User LED */
	result = cyhal_gpio_init(CYBSP_USER_LED, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, CYBSP_LED_STATE_OFF);
	result |= cyhal_gpio_init(P9_0, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, CYBSP_LED_STATE_OFF);
	result |= cyhal_gpio_init(P9_1, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, CYBSP_LED_STATE_OFF);
	cyhal_gpio_write(CYBSP_USER_LED, false);
	/* GPIO init failed. Stop program execution */
	if (result != CY_RSLT_SUCCESS) {
		CY_ASSERT(0);
	}

	debug_console_init();

	LOG_INFO("System starting up!\n\r");

	/* Enable global interrupts */
	__enable_irq();

	// usb_stack_init();
	///* Wait for configuration */
	// while ((USBD_GetState() & USB_STAT_CONFIGURED) != USB_STAT_CONFIGURED) {
	//	/* Ready to Read and Write HID messages. */
	//	/* Waiting for USB_STAT_CONFIGURED */
	//	cyhal_system_delay_ms(500);
	//	cyhal_gpio_write(CYBSP_USER_LED, CYBSP_LED_STATE_ON);
	//	cyhal_system_delay_ms(500);
	//	cyhal_gpio_write(CYBSP_USER_LED, CYBSP_LED_STATE_OFF);
	//	printf("Waiting for connection...\n");
	// }
	// LOG_INFO("USB is attached!\n\r");
	// while (1) {
	//	usb_cdc_echo();
	//	// USB_DRIVER_Cypress_PSoC6_SysTick();
	//	cyhal_gpio_toggle(CYBSP_USER_LED);
	//	// tx_thread_sleep(10);
	// }

	// timer_init();
	// while (1);

	// for (uint32_t i = 0; i <= 50000000; i += 1) {
	//	__ASM("nop");
	// }

	tx_kernel_enter();

	for (;;) {
		LOG_INFO("Kernel did not start!\n\r");
		cyhal_gpio_toggle(CYBSP_USER_LED);
		cyhal_system_delay_ms(1000);
	}
}

void tx_application_define(void *first_unused_memory) {
	(void)first_unused_memory;
	CHAR *pointer = TX_NULL;
	/* Create a byte memory pool from which to allocate the thread stacks.  */
	tx_byte_pool_create(&byte_pool_0, "byte pool 0", memory_area, DEMO_BYTE_POOL_SIZE);
	/* Allocate the stack for thread 0.  */
	tx_byte_allocate(&byte_pool_0, (VOID **)&pointer, DEMO_STACK_SIZE * 2, TX_NO_WAIT);
	/* Create the main thread.  */
	tx_thread_create(
		&thread_0, "thread 0", thread_0_entry, 0, pointer, DEMO_STACK_SIZE * 2, 6, 1, TX_NO_TIME_SLICE, TX_AUTO_START);
	/* Allocate the stack for thread 0.  */
	tx_byte_allocate(&byte_pool_0, (VOID **)&pointer, DEMO_STACK_SIZE, TX_NO_WAIT);
	/* Create the main thread.  */
	tx_thread_create(
		&thread_1, "thread 1", thread_1_entry, 0, pointer, DEMO_STACK_SIZE, 6, 1, TX_NO_TIME_SLICE, TX_AUTO_START);

	debug_console_init_mutex();
}

void thread_0_entry(ULONG thread_input) {
	(void)thread_input;
	usb_stack_init();
	/* Wait for configuration */
	while ((USBD_GetState() & USB_STAT_CONFIGURED) != USB_STAT_CONFIGURED) {
		/* Ready to Read and Write HID messages. */
		/* Waiting for USB_STAT_CONFIGURED */
		cyhal_system_delay_ms(500);
		cyhal_gpio_write(CYBSP_USER_LED, CYBSP_LED_STATE_ON);
		cyhal_system_delay_ms(500);
		cyhal_gpio_write(CYBSP_USER_LED, CYBSP_LED_STATE_OFF);
		printf("Waiting for connection...\n");
	}
	LOG_INFO("USB is attached!\n\r");
	while (1) {
		usb_cdc_echo();
		// USB_DRIVER_Cypress_PSoC6_SysTick();
		LOG_INFO("Thread 0 spinning!\n\r");
		// cyhal_gpio_toggle(CYBSP_USER_LED);
		// tx_thread_sleep(1301);
	}
}

void thread_1_entry(ULONG thread_input) {
	(void)thread_input;

	tx_semaphore_create(&timer_sem, "time sem", 0);

	timer_init();

	while (1) {
		if (tx_semaphore_get(&timer_sem, TX_WAIT_FOREVER) == TX_SUCCESS) {
			LOG_INFO("Thread 1 spinning!\n\r");
			cyhal_gpio_toggle(CYBSP_USER_LED);
			cyhal_gpio_toggle(P9_1);
			tx_thread_sleep(773);
		}
	}
}

static void isr_timer(void *callback_arg, cyhal_timer_event_t event);
/* Timer object used for blinking the LED */
cyhal_timer_t led_blink_timer;

void timer_init(void) {
	cy_rslt_t result;

	const cyhal_timer_cfg_t led_blink_timer_cfg = {
		.compare_value = 0,
		.period        = 4000, // 400ms
		.direction     = CYHAL_TIMER_DIR_UP,
		.is_compare    = false,
		.is_continuous = true,
		.value         = 0};

	/* Initialize the timer object. Does not use input pin ('pin' is NC) and
	 * does not use a pre-configured clock source ('clk' is NULL). */
	result = cyhal_timer_init(&led_blink_timer, NC, NULL);

	/* timer init failed. Stop program execution */
	if (result != CY_RSLT_SUCCESS) {
		CY_ASSERT(0);
	}

	/* Configure timer period and operation mode such as count direction,
	   duration */
	cyhal_timer_configure(&led_blink_timer, &led_blink_timer_cfg);

	/* Set the frequency of timer's clock source */
	cyhal_timer_set_frequency(&led_blink_timer, 10000);

	/* Assign the ISR to execute on timer interrupt */
	cyhal_timer_register_callback(&led_blink_timer, isr_timer, NULL);

	/* Set the event on which timer interrupt occurs and enable it */
	cyhal_timer_enable_event(&led_blink_timer, CYHAL_TIMER_IRQ_TERMINAL_COUNT, 7, true);

	/* Start the timer with the configured settings */
	cyhal_timer_start(&led_blink_timer);
}

static volatile uint32_t bruhh = 0;

static void isr_timer(void *callback_arg, cyhal_timer_event_t event) {
	(void)callback_arg;
	(void)event;

	bruhh += 1;
	// cyhal_gpio_toggle(P9_0);
	// cyhal_gpio_toggle(CYBSP_USER_LED);
	tx_semaphore_put(&timer_sem);
}

/* [] END OF FILE */
