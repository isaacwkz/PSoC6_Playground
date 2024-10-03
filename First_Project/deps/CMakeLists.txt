cmake_minimum_required(VERSION 3.15)

set(COMMON_INC_DIR
    ${CMAKE_SOURCE_DIR}/deps/threadx/common/inc
)

set(CM4_PORT_INC_DIR
    ${CMAKE_SOURCE_DIR}/deps/threadx/ports/cortex_m4/gnu/inc/
)

set(CFG_INC_DIR
    ${CMAKE_SOURCE_DIR}/deps/custom_configs
)

set(COMMON_SRC_DIR
    ${CMAKE_SOURCE_DIR}/deps/threadx/common/src/*.c
)

set(CM4_PORT_SRC_DIR
    ${CMAKE_SOURCE_DIR}/deps/threadx/ports/cortex_m4/gnu/src/*.S
)

set(CFG_SRC_DIR
    ${CMAKE_SOURCE_DIR}/deps/custom_configs/tx_initialize_low_level.S
)

file(GLOB_RECURSE TX_SOURCES 
    ${COMMON_SRC_DIR} 
    ${CM4_PORT_SRC_DIR}
    ${CFG_SRC_DIR}
)

# Specify the library to be built
add_library(threadx_lib STATIC 
    ${TX_SOURCES}
)

# Include directories for threadx
target_include_directories(threadx_lib PUBLIC 
    ${COMMON_INC_DIR}
    ${CM4_PORT_INC_DIR}
    ${CFG_INC_DIR}
)

set(RTT_SRC_DIR
    ${CMAKE_SOURCE_DIR}/deps/RTT/RTT/SEGGER_RTT_ASM_ARMv7M.S
    ${CMAKE_SOURCE_DIR}/deps/RTT/RTT/SEGGER_RTT.c
)

set(RTT_INC_DIR
    ${CMAKE_SOURCE_DIR}/deps/RTT/RTT
    ${CMAKE_SOURCE_DIR}/deps/RTT/Config/
)

file(GLOB_RECURSE RTT_SOURCES 
    ${RTT_SRC_DIR} 
)

add_library(rtt_lib STATIC 
    ${RTT_SOURCES}
)

# Include directories for threadx
target_include_directories(rtt_lib PUBLIC 
    ${RTT_INC_DIR}
)

target_compile_definitions(rtt_lib PUBLIC RTT_USE_ASM)