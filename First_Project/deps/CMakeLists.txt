cmake_minimum_required(VERSION 3.15)
#project(threadx)

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

file(GLOB_RECURSE SOURCES 
    ${COMMON_SRC_DIR} 
    ${CM4_PORT_SRC_DIR}
    ${CFG_SRC_DIR}
)

# Specify the library to be built
add_library(threadx_lib STATIC 
    ${SOURCES}
)

# Include directories for threadx
target_include_directories(threadx_lib PUBLIC 
    ${COMMON_INC_DIR}
    ${CM4_PORT_INC_DIR}
    ${CFG_INC_DIR}
)