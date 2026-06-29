#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esptim.h"
#include "camera.h"
#include "wifi_manager.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "ap_wifi.h"



#define TAG "main"


void wifi_state_handler(WIFI_STATE state)
{
	if(state == WIFI_STATE_CONNECTED)
	{

		ESP_LOGI(TAG,"WIFI_STATE_CONNECTED");

	}
	if(state == WIFI_STATE_DISCONNECTED)
	{
		ESP_LOGI(TAG,"WIFI_STATE_DISCONNECTED");


	}
}





void app_main(void)
{
	//esptim_int_init(1000000);
	//camera_init();
	ESP_ERROR_CHECK(nvs_flash_init());

	ap_wifi_init(wifi_state_handler);


	vTaskDelay(pdMS_TO_TICKS(3000));
	
	ap_wifi_apcfg(true);


	while (1)
	{

		//camera_capture();

		
		

		
		//printf("hello world!\n");
		vTaskDelay(pdMS_TO_TICKS(20));
	}
}