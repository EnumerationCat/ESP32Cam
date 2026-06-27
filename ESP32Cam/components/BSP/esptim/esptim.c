#include "esptim.h"



void esp_tim_callback(void* arg)
{

	ESP_LOGI("ESP_TIMER", "Timer callback executed!");



}




esp_timer_handle_t esp_tim_handle;

void esptim_int_init(uint64_t period_us)
{

	
	esp_timer_create_args_t esp_periodic_args = 
	{
		.callback = esp_tim_callback,
		.arg = NULL,
		.dispatch_method = ESP_TIMER_TASK,
		.name = "esp_periodic_timer",
		.skip_unhandled_events = false
	};
	
	


	ESP_ERROR_CHECK(esp_timer_create(&esp_periodic_args, &esp_tim_handle));

	ESP_ERROR_CHECK(esp_timer_start_periodic(esp_tim_handle, period_us));

}






