#ifndef __CAMERA_H
#define __CAMERA_H



#ifdef __cplusplus
extern "C" {
#endif


#include "stdio.h"
#include "esp_camera.h"

esp_err_t camera_init(void);
esp_err_t camera_capture(void);

#ifdef __cplusplus
}
#endif
#endif // __CAMERA_H