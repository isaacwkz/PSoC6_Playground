/*******************************************************************************
 * File Name: cycfg_pins.c
 *
 * Description:
 * Pin configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.20.0
 * device-db 4.17.0.6514
 * mtb-pdl-cat1 3.12.0.36524
 *
 *******************************************************************************
 * Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#include "cycfg_pins.h"

const cy_stc_gpio_pin_config_t CYBSP_WCO_IN_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom     = CYBSP_WCO_IN_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_WCO_IN_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = CYBSP_WCO_IN_PORT_NUM,
	.channel_num = CYBSP_WCO_IN_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t CYBSP_WCO_OUT_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom     = CYBSP_WCO_OUT_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_WCO_OUT_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = CYBSP_WCO_OUT_PORT_NUM,
	.channel_num = CYBSP_WCO_OUT_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_10_pin_0_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom     = ioss_0_port_10_pin_0_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_10_pin_0_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = ioss_0_port_10_pin_0_PORT_NUM,
	.channel_num = ioss_0_port_10_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_10_pin_1_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom     = ioss_0_port_10_pin_1_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_10_pin_1_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = ioss_0_port_10_pin_1_PORT_NUM,
	.channel_num = ioss_0_port_10_pin_1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_10_pin_2_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom     = ioss_0_port_10_pin_2_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_10_pin_2_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = ioss_0_port_10_pin_2_PORT_NUM,
	.channel_num = ioss_0_port_10_pin_2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t CYBSP_DEBUG_UART_RX_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom     = CYBSP_DEBUG_UART_RX_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_DEBUG_UART_RX_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = CYBSP_DEBUG_UART_RX_PORT_NUM,
	.channel_num = CYBSP_DEBUG_UART_RX_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t CYBSP_DEBUG_UART_TX_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom     = CYBSP_DEBUG_UART_TX_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_DEBUG_UART_TX_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = CYBSP_DEBUG_UART_TX_PORT_NUM,
	.channel_num = CYBSP_DEBUG_UART_TX_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t CYBSP_SWO_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom     = CYBSP_SWO_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_SWO_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = CYBSP_SWO_PORT_NUM,
	.channel_num = CYBSP_SWO_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_PULLUP,
	.hsiom     = CYBSP_SWDIO_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_SWDIO_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = CYBSP_SWDIO_PORT_NUM,
	.channel_num = CYBSP_SWDIO_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t CYBSP_SWDCK_config = {
	.outVal    = 1,
	.driveMode = CY_GPIO_DM_PULLDOWN,
	.hsiom     = CYBSP_SWDCK_HSIOM,
	.intEdge   = CY_GPIO_INTR_DISABLE,
	.intMask   = 0UL,
	.vtrip     = CY_GPIO_VTRIP_CMOS,
	.slewRate  = CY_GPIO_SLEW_FAST,
	.driveSel  = CY_GPIO_DRIVE_1_2,
	.vregEn    = 0UL,
	.ibufMode  = 0UL,
	.vtripSel  = 0UL,
	.vrefSel   = 0UL,
	.vohSel    = 0UL,
};

#if defined(CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_SWDCK_obj = {
	.type        = CYHAL_RSC_GPIO,
	.block_num   = CYBSP_SWDCK_PORT_NUM,
	.channel_num = CYBSP_SWDCK_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void) {
	Cy_GPIO_Pin_Init(CYBSP_WCO_IN_PORT, CYBSP_WCO_IN_PIN, &CYBSP_WCO_IN_config);
	Cy_GPIO_Pin_Init(CYBSP_WCO_OUT_PORT, CYBSP_WCO_OUT_PIN, &CYBSP_WCO_OUT_config);
	// Cy_GPIO_Pin_Init(ioss_0_port_10_pin_0_PORT, ioss_0_port_10_pin_0_PIN, &ioss_0_port_10_pin_0_config);
	// Cy_GPIO_Pin_Init(ioss_0_port_10_pin_1_PORT, ioss_0_port_10_pin_1_PIN, &ioss_0_port_10_pin_1_config);
	// Cy_GPIO_Pin_Init(ioss_0_port_10_pin_2_PORT, ioss_0_port_10_pin_2_PIN, &ioss_0_port_10_pin_2_config);
	// Cy_GPIO_Pin_Init(CYBSP_DEBUG_UART_RX_PORT, CYBSP_DEBUG_UART_RX_PIN, &CYBSP_DEBUG_UART_RX_config);
	// Cy_GPIO_Pin_Init(CYBSP_DEBUG_UART_TX_PORT, CYBSP_DEBUG_UART_TX_PIN, &CYBSP_DEBUG_UART_TX_config);
	Cy_GPIO_Pin_Init(CYBSP_SWO_PORT, CYBSP_SWO_PIN, &CYBSP_SWO_config);
	Cy_GPIO_Pin_Init(CYBSP_SWDIO_PORT, CYBSP_SWDIO_PIN, &CYBSP_SWDIO_config);
	Cy_GPIO_Pin_Init(CYBSP_SWDCK_PORT, CYBSP_SWDCK_PIN, &CYBSP_SWDCK_config);
}
void reserve_cycfg_pins(void) {
#if defined(CY_USING_HAL)
	cyhal_hwmgr_reserve(&CYBSP_WCO_IN_obj);
	cyhal_hwmgr_reserve(&CYBSP_WCO_OUT_obj);
	// cyhal_hwmgr_reserve(&ioss_0_port_10_pin_0_obj);
	// cyhal_hwmgr_reserve(&ioss_0_port_10_pin_1_obj);
	// cyhal_hwmgr_reserve(&ioss_0_port_10_pin_2_obj);
	// cyhal_hwmgr_reserve(&CYBSP_DEBUG_UART_RX_obj);
	// cyhal_hwmgr_reserve(&CYBSP_DEBUG_UART_TX_obj);
	cyhal_hwmgr_reserve(&CYBSP_SWO_obj);
	cyhal_hwmgr_reserve(&CYBSP_SWDIO_obj);
	cyhal_hwmgr_reserve(&CYBSP_SWDCK_obj);
#endif /* defined (CY_USING_HAL) */
}
