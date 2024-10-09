/*******************************************************************************
 * File Name: cycfg_pins.h
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

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined (CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define CYBSP_WCO_IN_ENABLED 1U
#define CYBSP_WCO_IN_PORT GPIO_PRT0
#define CYBSP_WCO_IN_PORT_NUM 0U
#define CYBSP_WCO_IN_PIN 0U
#define CYBSP_WCO_IN_NUM 0U
#define CYBSP_WCO_IN_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_WCO_IN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_0_HSIOM
    #define ioss_0_port_0_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_WCO_IN_HSIOM ioss_0_port_0_pin_0_HSIOM
#define CYBSP_WCO_IN_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_WCO_IN_HAL_PORT_PIN P0_0
#define CYBSP_WCO_IN P0_0
#define CYBSP_WCO_IN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_WCO_IN_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_WCO_IN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_WCO_OUT_ENABLED 1U
#define CYBSP_WCO_OUT_PORT GPIO_PRT0
#define CYBSP_WCO_OUT_PORT_NUM 0U
#define CYBSP_WCO_OUT_PIN 1U
#define CYBSP_WCO_OUT_NUM 1U
#define CYBSP_WCO_OUT_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_WCO_OUT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_1_HSIOM
    #define ioss_0_port_0_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_WCO_OUT_HSIOM ioss_0_port_0_pin_1_HSIOM
#define CYBSP_WCO_OUT_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_WCO_OUT_HAL_PORT_PIN P0_1
#define CYBSP_WCO_OUT P0_1
#define CYBSP_WCO_OUT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_WCO_OUT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_WCO_OUT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#define CYBSP_I2C_SCL (P0_2)
#define CYBSP_I2C_SDA (P0_3)
#define CYBSP_IMU_INT2 (P0_4)
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_10_pin_0_ENABLED 1U
#define ioss_0_port_10_pin_0_PORT GPIO_PRT10
#define ioss_0_port_10_pin_0_PORT_NUM 10U
#define ioss_0_port_10_pin_0_PIN 0U
#define ioss_0_port_10_pin_0_NUM 0U
#define ioss_0_port_10_pin_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_10_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_0_HSIOM
    #define ioss_0_port_10_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_10_pin_0_IRQ ioss_interrupts_gpio_10_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_10_pin_0_HAL_PORT_PIN P10_0
#define ioss_0_port_10_pin_0 P10_0
#define ioss_0_port_10_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_10_pin_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_10_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_10_pin_1_ENABLED 1U
#define ioss_0_port_10_pin_1_PORT GPIO_PRT10
#define ioss_0_port_10_pin_1_PORT_NUM 10U
#define ioss_0_port_10_pin_1_PIN 1U
#define ioss_0_port_10_pin_1_NUM 1U
#define ioss_0_port_10_pin_1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_10_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_1_HSIOM
    #define ioss_0_port_10_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_10_pin_1_IRQ ioss_interrupts_gpio_10_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_10_pin_1_HAL_PORT_PIN P10_1
#define ioss_0_port_10_pin_1 P10_1
#define ioss_0_port_10_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_10_pin_1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_10_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_10_pin_2_ENABLED 1U
#define ioss_0_port_10_pin_2_PORT GPIO_PRT10
#define ioss_0_port_10_pin_2_PORT_NUM 10U
#define ioss_0_port_10_pin_2_PIN 2U
#define ioss_0_port_10_pin_2_NUM 2U
#define ioss_0_port_10_pin_2_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_10_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_2_HSIOM
    #define ioss_0_port_10_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_10_pin_2_IRQ ioss_interrupts_gpio_10_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_10_pin_2_HAL_PORT_PIN P10_2
#define ioss_0_port_10_pin_2 P10_2
#define ioss_0_port_10_pin_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_10_pin_2_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_10_pin_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#define CYBSP_PDM_CLK (P10_4)
#define CYBSP_PDM_DATA (P10_5)
#define CYBSP_RSPI_IRQ (P11_0)
#define CYBSP_RXRES_L (P11_1)
#define CYBSP_QSPI_SS (P11_2)
#define CYBSP_QSPI_FLASH_SSEL CYBSP_QSPI_SS
#define CYBSP_QSPI_D3 (P11_3)
#define CYBSP_QSPI_D2 (P11_4)
#define CYBSP_QSPI_D1 (P11_5)
#define CYBSP_QSPI_D0 (P11_6)
#define CYBSP_QSPI_SCK (P11_7)
#define CYBSP_RSPI_MOSI (P12_0)
#define CYBSP_RSPI_MISO (P12_1)
#define CYBSP_RSPI_CLK (P12_2)
#define CYBSP_RSPI_CS (P12_3)
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_14_pin_0_ENABLED 1U
#define ioss_0_port_14_pin_0_PORT GPIO_PRT14
#define ioss_0_port_14_pin_0_PORT_NUM 14U
#define ioss_0_port_14_pin_0_PIN 0U
#define ioss_0_port_14_pin_0_NUM 0U
#define ioss_0_port_14_pin_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_14_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_14_pin_0_HSIOM
    #define ioss_0_port_14_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_14_pin_0_IRQ ioss_interrupts_gpio_14_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_14_pin_0_HAL_PORT_PIN P14_0
#define ioss_0_port_14_pin_0 P14_0
#define ioss_0_port_14_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_14_pin_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_14_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_14_pin_1_ENABLED 1U
#define ioss_0_port_14_pin_1_PORT GPIO_PRT14
#define ioss_0_port_14_pin_1_PORT_NUM 14U
#define ioss_0_port_14_pin_1_PIN 1U
#define ioss_0_port_14_pin_1_NUM 1U
#define ioss_0_port_14_pin_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_14_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_14_pin_1_HSIOM
    #define ioss_0_port_14_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_14_pin_1_IRQ ioss_interrupts_gpio_14_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_14_pin_1_HAL_PORT_PIN P14_1
#define ioss_0_port_14_pin_1 P14_1
#define ioss_0_port_14_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_14_pin_1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_14_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#define CYBSP_MAG_INT (P1_0)
#define CYBSP_PSEN_INT (P1_4)
#define CYBSP_IMU_INT1 (P1_5)
#define CYBSP_WIFI_SDIO_D0 (P2_0)
#define CYBSP_WIFI_SDIO_D1 (P2_1)
#define CYBSP_WIFI_SDIO_D2 (P2_2)
#define CYBSP_WIFI_SDIO_D3 (P2_3)
#define CYBSP_WIFI_SDIO_CMD (P2_4)
#define CYBSP_WIFI_SDIO_CLK (P2_5)
#define CYBSP_WIFI_WL_REG_ON (P2_6)
#define CYBSP_BT_UART_RX (P3_0)
#define CYBSP_BT_UART_TX (P3_1)
#define CYBSP_BT_UART_RTS (P3_2)
#define CYBSP_BT_UART_CTS (P3_3)
#define CYBSP_BT_POWER (P3_4)
#define CYBSP_BT_DEVICE_WAKE (P3_5)
#define CYBSP_BT_HOST_WAKE (P4_0)
#define CYBSP_WIFI_HOST_WAKE (P4_1)
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_DEBUG_UART_RX_ENABLED 1U
#define CYBSP_DEBUG_UART_RX_PORT GPIO_PRT5
#define CYBSP_DEBUG_UART_RX_PORT_NUM 5U
#define CYBSP_DEBUG_UART_RX_PIN 0U
#define CYBSP_DEBUG_UART_RX_NUM 0U
#define CYBSP_DEBUG_UART_RX_DRIVEMODE CY_GPIO_DM_HIGHZ
#define CYBSP_DEBUG_UART_RX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_0_HSIOM
    #define ioss_0_port_5_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_DEBUG_UART_RX_HSIOM ioss_0_port_5_pin_0_HSIOM
#define CYBSP_DEBUG_UART_RX_IRQ ioss_interrupts_gpio_5_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_DEBUG_UART_RX_HAL_PORT_PIN P5_0
#define CYBSP_DEBUG_UART_RX P5_0
#define CYBSP_DEBUG_UART_RX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_DEBUG_UART_RX_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_DEBUG_UART_RX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_DEBUG_UART_TX_ENABLED 1U
#define CYBSP_DEBUG_UART_TX_PORT GPIO_PRT5
#define CYBSP_DEBUG_UART_TX_PORT_NUM 5U
#define CYBSP_DEBUG_UART_TX_PIN 1U
#define CYBSP_DEBUG_UART_TX_NUM 1U
#define CYBSP_DEBUG_UART_TX_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CYBSP_DEBUG_UART_TX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_1_HSIOM
    #define ioss_0_port_5_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_DEBUG_UART_TX_HSIOM ioss_0_port_5_pin_1_HSIOM
#define CYBSP_DEBUG_UART_TX_IRQ ioss_interrupts_gpio_5_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_DEBUG_UART_TX_HAL_PORT_PIN P5_1
#define CYBSP_DEBUG_UART_TX P5_1
#define CYBSP_DEBUG_UART_TX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_DEBUG_UART_TX_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define CYBSP_DEBUG_UART_TX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#define CYBSP_SW12 (P5_2)
#define CYBSP_USER_BTN1 CYBSP_SW12
#define CYBSP_USER_BTN CYBSP_SW12
#define CYBSP_USER_LED1 (P5_3)
#define CYBSP_USER_LED CYBSP_USER_LED1
#define CYBSP_USER_LED2 (P5_4)
#define CYBSP_LBCPP_PG (P5_5)
#define CYBSP_LBCPP_CHG (P5_6)
#define CYBSP_LBCPP_CE (P5_7)
#define CYBSP_LBCPP_EN2 (P6_0)
#define CYBSP_LBCPP_EN1 (P6_1)
#define CYBSP_LBCPP_ITERM (P6_3)
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWO_ENABLED 1U
#define CYBSP_SWO_PORT GPIO_PRT6
#define CYBSP_SWO_PORT_NUM 6U
#define CYBSP_SWO_PIN 4U
#define CYBSP_SWO_NUM 4U
#define CYBSP_SWO_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CYBSP_SWO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_4_HSIOM
    #define ioss_0_port_6_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWO_HSIOM ioss_0_port_6_pin_4_HSIOM
#define CYBSP_SWO_IRQ ioss_interrupts_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWO_HAL_PORT_PIN P6_4
#define CYBSP_SWO P6_4
#define CYBSP_SWO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWO_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define CYBSP_SWO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWDIO_ENABLED 1U
#define CYBSP_SWDIO_PORT GPIO_PRT6
#define CYBSP_SWDIO_PORT_NUM 6U
#define CYBSP_SWDIO_PIN 6U
#define CYBSP_SWDIO_NUM 6U
#define CYBSP_SWDIO_DRIVEMODE CY_GPIO_DM_PULLUP
#define CYBSP_SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_6_HSIOM
    #define ioss_0_port_6_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDIO_HSIOM ioss_0_port_6_pin_6_HSIOM
#define CYBSP_SWDIO_IRQ ioss_interrupts_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWDIO_HAL_PORT_PIN P6_6
#define CYBSP_SWDIO P6_6
#define CYBSP_SWDIO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDIO_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDIO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWDCK_ENABLED 1U
#define CYBSP_SWDCK_PORT GPIO_PRT6
#define CYBSP_SWDCK_PORT_NUM 6U
#define CYBSP_SWDCK_PIN 7U
#define CYBSP_SWDCK_NUM 7U
#define CYBSP_SWDCK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CYBSP_SWDCK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_7_HSIOM
    #define ioss_0_port_6_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDCK_HSIOM ioss_0_port_6_pin_7_HSIOM
#define CYBSP_SWDCK_IRQ ioss_interrupts_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWDCK_HAL_PORT_PIN P6_7
#define CYBSP_SWDCK P6_7
#define CYBSP_SWDCK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDCK_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDCK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLDOWN
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_WCO_IN_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_WCO_IN_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_WCO_OUT_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_WCO_OUT_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_10_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_10_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_10_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_10_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_10_pin_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_10_pin_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_14_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_14_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_14_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_14_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_DEBUG_UART_RX_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_DEBUG_UART_RX_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_DEBUG_UART_TX_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_DEBUG_UART_TX_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWO_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWO_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWDIO_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDCK_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWDCK_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void);
void reserve_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PINS_H */
