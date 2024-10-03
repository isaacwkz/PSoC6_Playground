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

/*******************************************************************************
 * Macros
 *******************************************************************************/
/* LED blink timer clock value in Hz  */
#define LED_BLINK_TIMER_CLOCK_HZ (10000)

/* LED blink timer period value */
#define LED_BLINK_TIMER_PERIOD (1000)

/*******************************************************************************
 * Global Variables
 *******************************************************************************/
bool timer_interrupt_flag  = false;
bool led_blink_active_flag = true;

/* Variable for storing character read from terminal */
uint8_t uart_read_value;

/* Timer object used for blinking the LED */
cyhal_timer_t led_blink_timer;

TX_THREAD    thread_0;
TX_THREAD    thread_1;
TX_BYTE_POOL byte_pool_0;
#define DEMO_BYTE_POOL_SIZE 9120
UCHAR memory_area[DEMO_BYTE_POOL_SIZE];
#define DEMO_STACK_SIZE (1024)

/*******************************************************************************
 * Function Prototypes
 *******************************************************************************/
void thread_0_entry(ULONG thread_input);
void thread_1_entry(ULONG thread_input);

/*******************************************************************************
 * Function Name: main
 ********************************************************************************
 * Summary:
 * This is the main function. It sets up a timer to trigger a periodic interrupt.
 * The main while loop checks for the status of a flag set by the interrupt and
 * toggles an LED at 1Hz to create an LED blinky. Will be achieving the 1Hz Blink
 * rate based on the The LED_BLINK_TIMER_CLOCK_HZ and LED_BLINK_TIMER_PERIOD
 * Macros,i.e. (LED_BLINK_TIMER_PERIOD + 1) / LED_BLINK_TIMER_CLOCK_HZ = X ,Here,
 * X denotes the desired blink rate. The while loop also checks whether the
 * 'Enter' key was pressed and stops/restarts LED blinking.
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

	init_cycfg_pins();
	reserve_cycfg_pins();
	init_cycfg_peripherals();
	reserve_cycfg_peripherals();

	/* Initialize the User LED */
	result = cyhal_gpio_init(CYBSP_USER_LED, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, CYBSP_LED_STATE_OFF);
	cyhal_gpio_write(CYBSP_USER_LED, false);
	/* GPIO init failed. Stop program execution */
	if (result != CY_RSLT_SUCCESS) {
		CY_ASSERT(0);
	}

	debug_console_init();

	/* Enable global interrupts */
	__enable_irq();

	tx_kernel_enter();

	for (;;) {
		LOG_INFO("Kernel did not start!\n\r");
		cyhal_gpio_toggle(CYBSP_USER_LED);
		cyhal_system_delay_ms(250);
	}
}

void tx_application_define(void *first_unused_memory) {
	(void)first_unused_memory;
	CHAR *pointer = TX_NULL;
	/* Create a byte memory pool from which to allocate the thread stacks.  */
	tx_byte_pool_create(&byte_pool_0, "byte pool 0", memory_area, DEMO_BYTE_POOL_SIZE);
	/* Allocate the stack for thread 0.  */
	tx_byte_allocate(&byte_pool_0, (VOID **)&pointer, DEMO_STACK_SIZE, TX_NO_WAIT);
	/* Create the main thread.  */
	tx_thread_create(
		&thread_0, "thread 0", thread_0_entry, 0, pointer, DEMO_STACK_SIZE, 1, 1, TX_NO_TIME_SLICE, TX_AUTO_START);
	/* Allocate the stack for thread 0.  */
	tx_byte_allocate(&byte_pool_0, (VOID **)&pointer, DEMO_STACK_SIZE, TX_NO_WAIT);
	/* Create the main thread.  */
	tx_thread_create(
		&thread_1, "thread 1", thread_1_entry, 0, pointer, DEMO_STACK_SIZE, 1, 1, TX_NO_TIME_SLICE, TX_AUTO_START);

	debug_console_init_mutex();
}

static volatile uint8_t bruh = 0;

void thread_0_entry(ULONG thread_input) {
	(void)thread_input;

	while (1) {
		bruh += 1;
		LOG_INFO("ABCDEFGHIJ\n\r");
		cyhal_gpio_toggle(CYBSP_USER_LED);
		tx_thread_sleep(1);
	}
}

void thread_1_entry(ULONG thread_input) {
	(void)thread_input;

	while (1) {
		bruh += 1;
		LOG_INFO("1234567890!\n\r");
		cyhal_gpio_toggle(CYBSP_USER_LED);
		tx_thread_sleep(2);
	}
}

/* [] END OF FILE */
