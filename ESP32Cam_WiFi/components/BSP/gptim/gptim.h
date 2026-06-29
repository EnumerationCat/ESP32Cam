#ifndef __GPTIM_H
#define __GPTIM_H
#ifdef __cplusplus
extern "C" {
#endif

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gptimer.h"
#include "esp_log.h"
#include "esp_attr.h"
#include <stdbool.h>
#include <string.h>



struct GPTIMER_Device {
    char *name;
    int (*Init)(struct GPTIMER_Device *pDev, int fre_Hz,int psc, int arr);
    void *priv_data;

};

struct GPTIMER_Device *GetGPTIMER_Device(char *name);

bool *GPTIMER_GetReloadFlag(struct GPTIMER_Device *pDev);


#ifdef __cplusplus
}
#endif
#endif // __GPTIM_H