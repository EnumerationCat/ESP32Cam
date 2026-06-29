#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esptim.h"
#include "camera.h"



void app_main(void)
{
	//esptim_int_init(1000000);
	//camera_init();
	while (1)
	{

		//camera_capture();
		
		//printf("hello world!\n");
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}