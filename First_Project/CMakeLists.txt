cmake_minimum_required(VERSION 3.15)
project(first-project VERSION 1.0.0 LANGUAGES C ASM)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)

set(CMAKE_ASM_FLAGS "-mcpu=cortex-m4 -mthumb")
# Prod
#set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -Wall --specs=nano.specs -ffunction-sections -fdata-sections -ffat-lto-objects -pipe -O3")
# Debug
# set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -Wall -Wextra --specs=nano.specs -ffunction-sections -fdata-sections -ffat-lto-objects -pipe -Og -g")
set(CMAKE_C_FLAGS "-mcpu=cortex-m4 --specs=nano.specs -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -mthumb -ffunction-sections -fdata-sections -ffat-lto-objects -g -Wall")

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/linker.ld)
# No idea what this is for :thonk:
#set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/COMPONENT_CM0P/TOOLCHAIN_GCC_ARM/linker.ld)

set(CMAKE_EXE_LINKER_FLAGS "-T ${LINKER_SCRIPT}")

# Add compile definitions globally
#add_compile_definitions(CY8C624ABZI_S2D44 CORE_NAME_CM4_0 COMPONENT_CAT1 COMPONENT_CAT1A CY_USING_HAL COMPONENT_CM0P_SLEEP COMPONENT_CM4 COMPONENT_CM4_0 COMPONENT_MW_CAT1CM0P COMPONENT_PSOC6_02 DEBUG=2 )
#add_compile_definitions(CY8C624ABZI_S2D44 CORE_NAME_CM4_0 COMPONENT_CAT1 COMPONENT_CAT1A CY_USING_HAL COMPONENT_CM0P_SLEEP COMPONENT_CM4 COMPONENT_CM4_0 COMPONENT_MW_CAT1CM0P COMPONENT_PSOC6_02 DEBUG=2 COMPONENT_RTOS_AWARE)
#add_compile_definitions(CY8C624ABZI_S2D44 CORE_NAME_CM4_0 COMPONENT_CAT1 COMPONENT_CAT1A CY_USING_HAL COMPONENT_CM0P_SLEEP COMPONENT_CM4 COMPONENT_CM4_0 COMPONENT_MW_CAT1CM0P COMPONENT_PSOC6_02 USBD_ENABLE_DMA)
add_compile_definitions(CY8C624ABZI_S2D44 CORE_NAME_CM4_0 COMPONENT_CAT1 COMPONENT_CAT1A CY_USING_HAL COMPONENT_CM0P_SLEEP COMPONENT_CM4 COMPONENT_CM4_0 COMPONENT_MW_CAT1CM0P COMPONENT_PSOC6_02 USBD_ENABLE_DMA COMPONENT_RTOS_AWARE)
#add_compile_definitions(COMPONENT_43439 COMPONENT_APP_CY8CKIT_062S2_AI COMPONENT_CAT1 COMPONENT_CAT1A COMPONENT_CM0P_SLEEP COMPONENT_CM4 COMPONENT_CM4_0 COMPONENT_Debug COMPONENT_GCC_ARM COMPONENT_HCI_UART COMPONENT_MURATA_1YN COMPONENT_MW_CAT1CM0P COMPONENT_MW_CMSIS COMPONENT_MW_CORE_LIB COMPONENT_MW_CORE_MAKE COMPONENT_MW_EMUSB_DEVICE COMPONENT_MW_MTB_HAL_CAT1 COMPONENT_MW_MTB_PDL_CAT1 COMPONENT_MW_RECIPE_MAKE_CAT1A COMPONENT_MW_RETARGET_IO COMPONENT_PSOC6_02 COMPONENT_SOFTFP COMPONENT_USBD_BASE COMPONENT_WIFI_INTERFACE_SDIO CORE_NAME_CM4_0=1 CY8C624ABZI_S2D44 CY_APPNAME_mtb_example_usb_device_hid_generic CY_RETARGET_IO_CONVERT_LF_TO_CRLF CY_SUPPORTS_DEVICE_VALIDATION CY_TARGET_BOARD=APP_CY8CKIT_062S2_AI CY_USING_HAL DEBUG TARGET_APP_CY8CKIT_062S2_AI) #COMPONENT_RTOS_AWARE

set(PROJECT_INC_DIRS
    ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/bluetooth
    ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/config/GeneratedSource
    ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI
)

set(SDK_INC_DIRS
    ${CMAKE_SOURCE_DIR}/sdk/mtb-hal-cat1/release-v2.6.1/include
    ${CMAKE_SOURCE_DIR}/sdk/mtb-hal-cat1/release-v2.6.1/include_pvt
    ${CMAKE_SOURCE_DIR}/sdk/mtb-pdl-cat1/release-v3.12.0/drivers/include
    ${CMAKE_SOURCE_DIR}/sdk/mtb-pdl-cat1/release-v3.12.0/devices/COMPONENT_CAT1A/include
    ${CMAKE_SOURCE_DIR}/sdk/cmsis/release-v5.8.1/Core/Include
    ${CMAKE_SOURCE_DIR}/sdk/core-lib/release-v1.4.2/include
    ${CMAKE_SOURCE_DIR}/sdk/retarget-io/release-v1.6.0/include
    ${CMAKE_SOURCE_DIR}/sdk/mtb-hal-cat1/release-v2.6.1/COMPONENT_CAT1A/include
    ${CMAKE_SOURCE_DIR}/sdk/abstraction-rtos/release-v1.8.2/include
    ${CMAKE_SOURCE_DIR}/sdk/abstraction-rtos/release-v1.8.2/include/COMPONENT_THREADX
    ${CMAKE_SOURCE_DIR}/sdk/emusb-device/release-v1.4.0/USBD
    ${CMAKE_SOURCE_DIR}/sdk/emusb-device/release-v1.4.0/USBD/COMPONENT_CAT1A
    ${CMAKE_SOURCE_DIR}/sdk/emusb-device/release-v1.4.0/USBD/COMPONENT_USBD_BASE/COMPONENT_CAT1A/CONFIG_Release
)

set(CM0P_PRE_BUILT_INC_DIRS
    ${CMAKE_SOURCE_DIR}/sdk/cat1cm0p/release-v1.7.0/COMPONENT_CAT1A
)

set(APP_INC_DIRS
    ${CMAKE_SOURCE_DIR}/app
)

# Set the source directories and file patterns
set(PROJECT_SRC_FILES
    ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/cybsp.c
    ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/bluetooth/*.c
    #${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/COMPONENT_CM0P/system_psoc6_cm0plus.c
    #${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/COMPONENT_CM0P/TOOLCHAIN_GCC_ARM/startup_psoc6_02_cm0plus.S
    ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/COMPONENT_CM4/system_psoc6_cm4.c
    ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/startup_psoc6_02_cm4.S
    ${CMAKE_SOURCE_DIR}/bsps/TARGET_APP_CY8CKIT-062S2-AI/config/GeneratedSource/*.c
)

set(SDK_SRC_DIRS
    ${CMAKE_SOURCE_DIR}/sdk/mtb-hal-cat1/release-v2.6.1/source/*.c
    ${CMAKE_SOURCE_DIR}/sdk/mtb-pdl-cat1/release-v3.12.0/drivers/source/*.c
    ${CMAKE_SOURCE_DIR}/sdk/mtb-pdl-cat1/release-v3.12.0/devices/COMPONENT_CAT1A/source/*.c
    ${CMAKE_SOURCE_DIR}/sdk/retarget-io/release-v1.6.0/source/*.c
    ${CMAKE_SOURCE_DIR}/sdk/mtb-hal-cat1/release-v2.6.1/COMPONENT_CAT1A/source/pin_packages/cyhal_psoc6_02_124_bga.c
    ${CMAKE_SOURCE_DIR}/sdk/mtb-hal-cat1/release-v2.6.1/COMPONENT_CAT1A/source/triggers/cyhal_triggers_psoc6_02.c
    ${CMAKE_SOURCE_DIR}/sdk/mtb-pdl-cat1/release-v3.12.0/drivers/source/TOOLCHAIN_GCC_ARM/cy_syslib_ext.S
    ${CMAKE_SOURCE_DIR}/sdk/abstraction-rtos/release-v1.8.2/source/COMPONENT_THREADX/cyabs_rtos_threadx.c
    ${CMAKE_SOURCE_DIR}/sdk/abstraction-rtos/release-v1.8.2/source/cy_worker_thread.c
    ${CMAKE_SOURCE_DIR}/sdk/emusb-device/release-v1.4.0/OS/usbd_os_abs_rtos.c
)

set(IMPORTED_LIB_SRC_DIRS
    ${CMAKE_SOURCE_DIR}/imports/emusb-device/Config/COMPONENT_CAT1A/usbd_config.c
    ${CMAKE_SOURCE_DIR}/imports/emusb-device/Config/usbd_config_io.c
)

set(CM0P_PRE_BUILT_SRC_DIRS
# This is for SoC bootup sequence
    ${CMAKE_SOURCE_DIR}/sdk/cat1cm0p/release-v1.7.0/COMPONENT_CAT1A/COMPONENT_CM0P_SLEEP/*.c
)

set(APP_SRC_FILE
    ${CMAKE_SOURCE_DIR}/app/*.c
)

set(EMUSB_BINARY_LIB
    # Prod version
    # ${CMAKE_SOURCE_DIR}/sdk/emusb-device/release-v1.4.0/USBD/COMPONENT_USBD_BASE/COMPONENT_CAT1A/CONFIG_Release/COMPONENT_CM4/COMPONENT_SOFTFP/TOOLCHAIN_GCC_ARM/libusbd_base_r_cm4_gcc.a
    # Debug version
    ${CMAKE_SOURCE_DIR}/sdk/emusb-device/release-v1.4.0/USBD/COMPONENT_USBD_BASE/COMPONENT_CAT1A/CONFIG_Debug/COMPONENT_CM4/COMPONENT_SOFTFP/TOOLCHAIN_GCC_ARM/libusbd_base_d_cm4_gcc.a
)

# Collect all sources using glob
file(GLOB_RECURSE SOURCES 
    ${PROJECT_SRC_FILES} 
    ${SDK_SRC_DIRS} 
    ${CM0P_PRE_BUILT_SRC_DIRS} 
    ${APP_SRC_FILE}
    ${IMPORTED_LIB_SRC_DIRS}
)

add_executable(${PROJECT_NAME}.elf ${SOURCES})

# Add subdirectory for threadx
add_subdirectory(${CMAKE_SOURCE_DIR}/deps)
target_link_libraries(${PROJECT_NAME}.elf PUBLIC threadx_lib rtt_lib ${EMUSB_BINARY_LIB})
target_include_directories(${PROJECT_NAME}.elf PUBLIC
        ${PROJECT_INC_DIRS}
        ${SDK_INC_DIRS} 
        ${CM0P_PRE_BUILT_INC_DIRS} 
        ${APP_INC_DIRS}
)
target_link_options(${PROJECT_NAME}.elf PRIVATE "LINKER:--gc-sections,-print-memory-usage,--sort-section=alignment")

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD COMMAND arm-none-eabi-size ARGS ${PROJECT_NAME}.elf)

# convert embedded executable to intel hex format
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY} ARGS -v -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex)

#add_executable(${PROJECT_NAME}.elf ${SOURCES})
#
#add_custom_target(CopyHex ALL
#    COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex)