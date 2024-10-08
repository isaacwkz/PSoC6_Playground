/*********************************************************************
*                   (c) SEGGER Microcontroller GmbH                  *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*       (c) 2003 - 2024     SEGGER Microcontroller GmbH              *
*                                                                    *
*       www.segger.com     Support: www.segger.com/ticket            *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device * USB Device stack for embedded applications    *
*                                                                    *
*       Please note: Knowledge of this file may under no             *
*       circumstances be used to write a similar product.            *
*       Thank you for your fairness !                                *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device version: V3.64.1                                *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
All Intellectual Property rights in the software belongs to SEGGER.
emUSB Device is protected by international copyright laws. This file
may only be used in accordance with the following terms:

The source code of the emUSB Device software has been licensed to Cypress
Semiconductor Corporation, whose registered office is 198 Champion
Court, San Jose, CA 95134, USA including the
right to create and distribute the object code version of
the emUSB Device software for its Cortex M0, M0+, M4, M33 and M55 based devices.
The object code version can be used by Cypress customers under the
terms and conditions of the associated End User License Agreement.
Support for the object code version is provided by Cypress,
full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Microcontroller Systems LLC
Licensed to:              Cypress Semiconductor Corp, 198 Champion Ct., San Jose, CA 95134, USA
Licensed SEGGER software: emUSB-Device
License number:           USBD-00500
License model:            Cypress Services and License Agreement, signed November 17th/18th, 2010
                          and Amendment Number One, signed December 28th, 2020 and February 10th, 2021
                          and Amendment Number Three, signed May 2nd, 2022 and May 5th, 2022 and Amendment Number Four,
signed August 28th, 2023 Licensed platform:        Cypress devices containing ARM Cortex M cores: M0, M0+, M4, M33 and
M55
----------------------------------------------------------------------
Support and Update Agreement (SUA)
SUA period:               2022-05-12 - 2024-05-19
Contact to extend SUA:    sales@segger.com
----------------------------------------------------------------------
File        : usbd_config.c
Purpose     : emUSB-Device configuration file for CAT1A device
--------  END-OF-HEADER  ---------------------------------------------
*/

#include "USB.h"
#include "USB_HW_Cypress_PSoC6.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#if defined(USBD_USE_PDL) && (USBD_USE_PDL == 1U)
#include "cy_pdl.h"
#else
#include "cyhal.h"
#endif /* #if defined (USBD_USE_PDL) && (USBD_USE_PDL == 1U) */

/* Define interrupt priority */
#define USBD_ISR_PRIO (0U)

/*  Use the driver with DMA support. Can be defined in Makefile */
#if !defined(USBD_ENABLE_DMA)
#define USBD_ENABLE_DMA (false)
#endif /* #if !defined (USBD_ENABLE_DMA) */

/* Define interrupt source */
#if (COMPONENT_CM0P)
/* The number of CM0+ interrupt vectors are different between device,
 * change this macro for your selected device.
 */
#define USBD_INTERRUPT_NUM (NvicMux7_IRQn)
#else
#define USBD_INTERRUPT_NUM (usb_interrupt_med_IRQn)
#endif /* #if (COMPONENT_CM0P) */

#if USBD_ENABLE_DMA == true
#define USBD_DMA_CHANNEL_PRIORITY_EP0 3U
#define USBD_DMA_CHANNEL_PRIORITY_EP1 3U
#define USBD_DMA_CHANNEL_PRIORITY_EP2 3U
#define USBD_DMA_CHANNEL_PRIORITY_EP3 3U
#define USBD_DMA_CHANNEL_PRIORITY_EP4 3U
#define USBD_DMA_CHANNEL_PRIORITY_EP5 3U
#define USBD_DMA_CHANNEL_PRIORITY_EP6 3U
#define USBD_DMA_CHANNEL_PRIORITY_EP7 3U
#define USBD_DMA_CHANNEL_ADDRESS_EP0  DW0_CH_STRUCT8
#define USBD_DMA_CHANNEL_ADDRESS_EP1  DW0_CH_STRUCT9
#define USBD_DMA_CHANNEL_ADDRESS_EP2  DW0_CH_STRUCT10
#define USBD_DMA_CHANNEL_ADDRESS_EP3  DW0_CH_STRUCT11
#define USBD_DMA_CHANNEL_ADDRESS_EP4  DW0_CH_STRUCT12
#define USBD_DMA_CHANNEL_ADDRESS_EP5  DW0_CH_STRUCT13
#define USBD_DMA_CHANNEL_ADDRESS_EP6  DW0_CH_STRUCT14
#define USBD_DMA_CHANNEL_ADDRESS_EP7  DW0_CH_STRUCT15
#define USBD_DMA_OUT_TRIG_MUX_EP0     TRIG_OUT_1TO1_6_PDMA0_TR_OUT8_TO_USB_ACK0
#define USBD_DMA_OUT_TRIG_MUX_EP1     TRIG_OUT_1TO1_6_PDMA0_TR_OUT9_TO_USB_ACK1
#define USBD_DMA_OUT_TRIG_MUX_EP2     TRIG_OUT_1TO1_6_PDMA0_TR_OUT10_TO_USB_ACK2
#define USBD_DMA_OUT_TRIG_MUX_EP3     TRIG_OUT_1TO1_6_PDMA0_TR_OUT11_TO_USB_ACK3
#define USBD_DMA_OUT_TRIG_MUX_EP4     TRIG_OUT_1TO1_6_PDMA0_TR_OUT12_TO_USB_ACK4
#define USBD_DMA_OUT_TRIG_MUX_EP5     TRIG_OUT_1TO1_6_PDMA0_TR_OUT13_TO_USB_ACK5
#define USBD_DMA_OUT_TRIG_MUX_EP6     TRIG_OUT_1TO1_6_PDMA0_TR_OUT14_TO_USB_ACK6
#define USBD_DMA_OUT_TRIG_MUX_EP7     TRIG_OUT_1TO1_6_PDMA0_TR_OUT15_TO_USB_ACK7

/* Define the size of memory dedicated for drivers with DMA in
 * bytes. The memory is used for endpoints buffers and
 * transfer descriptors. Update this value with the optimal
 * memory pool size (strongly recommended) for the application.
 * For details on selecting the optimal memory pool size, refer
 * to the USBD_AssignMemory() description in emUSB-Device User
 * Guide & Reference Manual.
 */
#define USBD_MEMORY_POOL_SIZE (2048U)
#endif /* #if USBD_ENABLE_DMA == true */

/*********************************************************************
 *
 *       enable_isr
 *  Function description
 *    Configure and enable interrupts.
 */
static void enable_isr(USB_ISR_HANDLER *pfISRHandler) {
#if defined(USBD_USE_PDL) && (USBD_USE_PDL == 1U)
	cy_stc_sysint_t usb_int_cfg = {
		.intrSrc = USBD_INTERRUPT_NUM,
#if defined(COMPONENT_CM0P)
		.cm0pSrc = usb_interrupt_med_IRQn,
#endif /* #if defined (COMPONENT_CM0P) */
		.intrPriority = USBD_ISR_PRIO};

	cy_en_sysint_status_t status;

	/* Install the interrupt service routine */
	status = Cy_SysInt_Init(&usb_int_cfg, pfISRHandler);
	CY_ASSERT(CY_RSLT_SUCCESS == status);
	(void)status; /* To avoid the compiler warning in Release mode */
#else
	/* Install the interrupt service routine */
	cy_rslt_t result;
	result = cyhal_system_set_isr(USBD_INTERRUPT_NUM, usb_interrupt_med_IRQn, USBD_ISR_PRIO, pfISRHandler);
	CY_ASSERT(CY_RSLT_SUCCESS == result);
	(void)result; /* To avoid the compiler warning in Release mode */
#endif /* #if defined (USBD_USE_PDL) && (USBD_USE_PDL == 1U) */
	NVIC_EnableIRQ(USBD_INTERRUPT_NUM);
}

#if USBD_ENABLE_DMA == true
/*********************************************************************
 *
 *       trig_mux_sw_trigger
 *
 *  Function description
 *    Triggers the burst end on an endpoint.
 *
 *  Parameters
 *    Endpoint      -  Endpoint number 0..7
 *
 */
static void trig_mux_sw_trigger(unsigned Endpoint) {
	uint32_t out_trig_mux = 0U;
	switch (Endpoint) {
#if defined(USBD_DMA_OUT_TRIG_MUX_EP0)
		case 0U:
			out_trig_mux = USBD_DMA_OUT_TRIG_MUX_EP0;
			break;
#endif /* #if defined (USBD_DMA_OUT_TRIG_MUX_EP0) */
#if defined(USBD_DMA_OUT_TRIG_MUX_EP1)
		case 1U:
			out_trig_mux = USBD_DMA_OUT_TRIG_MUX_EP1;
			break;
#endif /* #if defined (USBD_DMA_OUT_TRIG_MUX_EP1) */
#if defined(USBD_DMA_OUT_TRIG_MUX_EP2)
		case 2U:
			out_trig_mux = USBD_DMA_OUT_TRIG_MUX_EP2;
			break;
#endif /* #if defined (USBD_DMA_OUT_TRIG_MUX_EP2) */
#if defined(USBD_DMA_OUT_TRIG_MUX_EP3)
		case 3U:
			out_trig_mux = USBD_DMA_OUT_TRIG_MUX_EP3;
			break;
#endif /* #if defined (USBD_DMA_OUT_TRIG_MUX_EP3) */
#if defined(USBD_DMA_OUT_TRIG_MUX_EP4)
		case 4U:
			out_trig_mux = USBD_DMA_OUT_TRIG_MUX_EP4;
			break;
#endif /* #if defined (USBD_DMA_OUT_TRIG_MUX_EP4) */
#if defined(USBD_DMA_OUT_TRIG_MUX_EP5)
		case 5U:
			out_trig_mux = USBD_DMA_OUT_TRIG_MUX_EP5;
			break;
#endif /* #if defined (USBD_DMA_OUT_TRIG_MUX_EP5) */
#if defined(USBD_DMA_OUT_TRIG_MUX_EP6)
		case 6U:
			out_trig_mux = USBD_DMA_OUT_TRIG_MUX_EP6;
			break;
#endif /* #if defined (USBD_DMA_OUT_TRIG_MUX_EP6) */
#if defined(USBD_DMA_OUT_TRIG_MUX_EP7)
		case 7U:
			out_trig_mux = USBD_DMA_OUT_TRIG_MUX_EP7;
			break;
#endif /* #if defined (USBD_DMA_OUT_TRIG_MUX_EP7) */
		default:
			/* Never go to this */
			USB_OS_Panic("Incorrect SW trigger signal for DMA channel");
			break;
	}
	(void)Cy_TrigMux_SwTrigger(out_trig_mux, CY_TRIGGER_TWO_CYCLES);
}

/* DMA configuration */
static const USB_CYPRESS_PSoC6_DMA_CONFIG dma_config = {
	trig_mux_sw_trigger,
	{
#if defined(USBD_DMA_CHANNEL_ADDRESS_EP0) && defined(USBD_DMA_CHANNEL_PRIORITY_EP0)
		{USBD_DMA_CHANNEL_ADDRESS_EP0, USBD_DMA_CHANNEL_PRIORITY_EP0},
#endif /* #if defined (USBD_DMA_CHANNEL_ADDRESS_EP0) && defined (USBD_DMA_CHANNEL_PRIORITY_EP0) */
#if defined(USBD_DMA_CHANNEL_ADDRESS_EP1) && defined(USBD_DMA_CHANNEL_PRIORITY_EP1)
		{USBD_DMA_CHANNEL_ADDRESS_EP1, USBD_DMA_CHANNEL_PRIORITY_EP1},
#endif /* #if defined (USBD_DMA_CHANNEL_ADDRESS_EP1) && defined (USBD_DMA_CHANNEL_PRIORITY_EP1) */
#if defined(USBD_DMA_CHANNEL_ADDRESS_EP2) && defined(USBD_DMA_CHANNEL_PRIORITY_EP2)
		{USBD_DMA_CHANNEL_ADDRESS_EP2, USBD_DMA_CHANNEL_PRIORITY_EP2},
#endif /* #if defined (USBD_DMA_CHANNEL_ADDRESS_EP2) && defined (USBD_DMA_CHANNEL_PRIORITY_EP2) */
#if defined(USBD_DMA_CHANNEL_ADDRESS_EP3) && defined(USBD_DMA_CHANNEL_PRIORITY_EP3)
		{USBD_DMA_CHANNEL_ADDRESS_EP3, USBD_DMA_CHANNEL_PRIORITY_EP3},
#endif /* #if defined (USBD_DMA_CHANNEL_ADDRESS_EP3) && defined (USBD_DMA_CHANNEL_PRIORITY_EP3) */
#if defined(USBD_DMA_CHANNEL_ADDRESS_EP4) && defined(USBD_DMA_CHANNEL_PRIORITY_EP4)
		{USBD_DMA_CHANNEL_ADDRESS_EP4, USBD_DMA_CHANNEL_PRIORITY_EP4},
#endif /* #if defined (USBD_DMA_CHANNEL_ADDRESS_EP4) && defined (USBD_DMA_CHANNEL_PRIORITY_EP4) */
#if defined(USBD_DMA_CHANNEL_ADDRESS_EP5) && defined(USBD_DMA_CHANNEL_PRIORITY_EP5)
		{USBD_DMA_CHANNEL_ADDRESS_EP5, USBD_DMA_CHANNEL_PRIORITY_EP5},
#endif /* #if defined (USBD_DMA_CHANNEL_ADDRESS_EP5) && defined (USBD_DMA_CHANNEL_PRIORITY_EP5) */
#if defined(USBD_DMA_CHANNEL_ADDRESS_EP6) && defined(USBD_DMA_CHANNEL_PRIORITY_EP6)
		{USBD_DMA_CHANNEL_ADDRESS_EP6, USBD_DMA_CHANNEL_PRIORITY_EP6},
#endif /* #if defined (USBD_DMA_CHANNEL_ADDRESS_EP6) && defined (USBD_DMA_CHANNEL_PRIORITY_EP6) */
#if defined(USBD_DMA_CHANNEL_ADDRESS_EP7) && defined(USBD_DMA_CHANNEL_PRIORITY_EP7)
		{USBD_DMA_CHANNEL_ADDRESS_EP7, USBD_DMA_CHANNEL_PRIORITY_EP7},
#endif /* #if defined (USBD_DMA_CHANNEL_ADDRESS_EP7) && defined (USBD_DMA_CHANNEL_PRIORITY_EP7) */
		}
};

static U32 ep_mem_pool_dma[USBD_MEMORY_POOL_SIZE / 4U];

#endif /* #if USBD_ENABLE_DMA == true */

/*********************************************************************
 *
 *       USBD_X_Config
 *
 *  Function description
 *    Configure the USB stack. This function is always called from
 *    USBD_Init().
 *
 */
void USBD_X_Config(void) {
#if USBD_ENABLE_DMA == true
	Cy_TrigMux_Select(TRIG_OUT_1TO1_5_USB_DMA0_TO_PDMA0_TR_IN8, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_5_USB_DMA1_TO_PDMA0_TR_IN9, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_5_USB_DMA2_TO_PDMA0_TR_IN10, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_5_USB_DMA3_TO_PDMA0_TR_IN11, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_5_USB_DMA4_TO_PDMA0_TR_IN12, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_5_USB_DMA5_TO_PDMA0_TR_IN13, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_5_USB_DMA6_TO_PDMA0_TR_IN14, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_5_USB_DMA7_TO_PDMA0_TR_IN15, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_6_PDMA0_TR_OUT10_TO_USB_ACK2, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_6_PDMA0_TR_OUT11_TO_USB_ACK3, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_6_PDMA0_TR_OUT12_TO_USB_ACK4, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_6_PDMA0_TR_OUT13_TO_USB_ACK5, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_6_PDMA0_TR_OUT14_TO_USB_ACK6, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_6_PDMA0_TR_OUT15_TO_USB_ACK7, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_6_PDMA0_TR_OUT8_TO_USB_ACK0, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Select(TRIG_OUT_1TO1_6_PDMA0_TR_OUT9_TO_USB_ACK1, false, TRIGGER_TYPE_EDGE);
	/* Enable the DMA IP block */
	Cy_DMA_Enable(DW0);

	/* Add and configure DMA driver */
	USBD_AddDriver(&USB_Driver_Cypress_PSoC6_DMA);
	USBD_AssignMemory(ep_mem_pool_dma, sizeof(ep_mem_pool_dma));
	USB_DRIVER_Cypress_PSoC6_ConfigDMA(&USB_DRIVER_Cypress_PSoC6_DWx, &dma_config);
#else
	printf("Adding PSoC6 USB driver\r\n");
	/* Add USB Driver */
	USBD_AddDriver(&USB_Driver_Cypress_PSoC6);
#endif /* #if USBD_ENABLE_DMA == true */
	/* Configure interrupt */
	printf("Configuring USB IRQ handler\r\n");
	USBD_SetISREnableFunc(enable_isr);
}

/*********************************************************************
 *
 *       USBD_X_EnableInterrupt
 *
 *  Function description
 *    This function is called by the stack to enable USB interrupt(s)
 *    after they have been disabled by USBD_X_DisableInterrupt().
 *
 */
void USBD_X_EnableInterrupt(void) { NVIC_EnableIRQ(USBD_INTERRUPT_NUM); }

/*********************************************************************
 *
 *       USBD_X_DisableInterrupt
 *
 *  Function description
 *    This function is called by the stack in cases where the stack
 *    must perform a critical operation which can not be interrupted
 *    by a new incoming USB interrupt event.
 *
 */
void USBD_X_DisableInterrupt(void) { NVIC_DisableIRQ(USBD_INTERRUPT_NUM); }
