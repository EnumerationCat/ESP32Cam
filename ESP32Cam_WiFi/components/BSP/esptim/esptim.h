#ifndef __ESPTIM_H
#define __ESPTIM_H

// C++ 兼容核心：判断是否为 C++ 编译器，若是则启用 extern "C"
#ifdef __cplusplus
extern "C" {
#endif

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include <esp_log.h>

void esptim_int_init(uint64_t period_us);
#ifdef __cplusplus
}
#endif

#endif // __ESPTIM_H