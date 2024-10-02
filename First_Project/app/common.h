#ifndef COMMON_H
#define COMMON_H

#include "cyhal.h"
#include "cybsp.h"

#include "debug_console.h"

#define LOG_INFO(format, ...) __LOG_printf(__FUNCTION__, __LINE__, format, ##__VA_ARGS__)

#endif