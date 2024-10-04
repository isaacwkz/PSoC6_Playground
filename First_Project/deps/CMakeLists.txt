cmake_minimum_required(VERSION 3.15)

#---------------- ThreadX -----------------#
set(THREADX_INC_DIR
    ${CMAKE_SOURCE_DIR}/deps/threadx/common/inc
    ${CMAKE_SOURCE_DIR}/deps/threadx/ports/cortex_m4/gnu/inc/
    ${CMAKE_SOURCE_DIR}/deps/custom_configs
)

set(THREADX_SRC_DIR
    ${CMAKE_SOURCE_DIR}/deps/threadx/common/src/*.c
    ${CMAKE_SOURCE_DIR}/deps/threadx/ports/cortex_m4/gnu/src/*.S
    ${CMAKE_SOURCE_DIR}/deps/custom_configs/tx_initialize_low_level.S
)

file(GLOB_RECURSE TX_SOURCES ${THREADX_SRC_DIR})
add_library(threadx_lib STATIC ${TX_SOURCES})
target_include_directories(threadx_lib PUBLIC ${THREADX_INC_DIR})

#---------------- SEGGER RTT -----------------#
set(RTT_SRC_DIR
    ${CMAKE_SOURCE_DIR}/deps/RTT/RTT/SEGGER_RTT_ASM_ARMv7M.S
    ${CMAKE_SOURCE_DIR}/deps/RTT/RTT/SEGGER_RTT.c
)

set(RTT_INC_DIR
    ${CMAKE_SOURCE_DIR}/deps/RTT/RTT
    ${CMAKE_SOURCE_DIR}/deps/RTT/Config/
)

file(GLOB_RECURSE RTT_SOURCES ${RTT_SRC_DIR})
add_library(rtt_lib STATIC ${RTT_SOURCES})
target_include_directories(rtt_lib PUBLIC ${RTT_INC_DIR})
target_compile_definitions(rtt_lib PUBLIC RTT_USE_ASM)
