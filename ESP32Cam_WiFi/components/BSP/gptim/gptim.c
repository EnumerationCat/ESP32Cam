#include "gptim.h"



static struct GPTIMER_Device g_esp32_timer1; 
static struct GPTIMER_Device g_esp32_timer2;


struct GPTIMER_Data {

    gptimer_handle_t handle;

	gptimer_alarm_cb_t timer_callback;

	bool timer_reload_flag;

}; 






bool IRAM_ATTR Timer1Callback(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx)
{
    struct GPTIMER_Data *gptimer_data;
    
	gptimer_data = g_esp32_timer1.priv_data;
	
	gptimer_data->timer_reload_flag = true;
    // 无需低功耗唤醒返回false，需要唤醒低功耗模式返回true
    return false;
}



bool IRAM_ATTR Timer2Callback(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx)
{
    struct GPTIMER_Data *gptimer_data;
    
	gptimer_data = g_esp32_timer2.priv_data;
	
	gptimer_data->timer_reload_flag = true;
    // 无需低功耗唤醒返回false，需要唤醒低功耗模式返回true
    return false;
}





static int gptimer_init(struct GPTIMER_Device *pDev, int fre_Hz,int psc, int arr)
{

	


	struct GPTIMER_Data *gptimer_data = pDev->priv_data;


    gptimer_config_t gptimer_config =
    {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .flags.backup_before_sleep = 0,
        .flags.intr_shared = 0,
        .intr_priority = 0,
        .resolution_hz = (uint32_t)(fre_Hz/psc)
		
    };
    
    ESP_ERROR_CHECK(gptimer_new_timer(&gptimer_config, &(gptimer_data->handle)));

    //报警配置：1s周期触发，自动重载
    gptimer_alarm_config_t gptimer_alarm_config = {
        .alarm_count = (uint64_t)arr,
        .flags.auto_reload_on_alarm = true,
        .reload_count = 0
    };
    ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer_data->handle, &gptimer_alarm_config));

    //注册中断回调
    gptimer_event_callbacks_t gptimer_event_config = 
    {
        .on_alarm = gptimer_data->timer_callback
    };

    ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer_data->handle, &gptimer_event_config, NULL));

    //使能并启动定时器
    ESP_ERROR_CHECK(gptimer_enable(gptimer_data->handle));
    ESP_ERROR_CHECK(gptimer_start(gptimer_data->handle));
	return 0;
}




static struct GPTIMER_Data g_esp32_timer1_data = {
     NULL,
	 Timer1Callback,
	 false

};

static struct GPTIMER_Data g_esp32_timer2_data = {
     NULL,
	 Timer2Callback,
	 false

};


static struct GPTIMER_Device g_esp32_timer1 = {
    "esp32_timer1",
    gptimer_init,
	&g_esp32_timer1_data

};

static struct GPTIMER_Device g_esp32_timer2 = {
    "esp32_timer2",
    gptimer_init,
	&g_esp32_timer2_data

};



static struct GPTIMER_Device *g_gptimer_devs[] = {
	&g_esp32_timer1,
	&g_esp32_timer2

};



struct GPTIMER_Device *GetGPTIMER_Device(char *name)
{

	
    for (uint8_t i = 0; i < sizeof(g_gptimer_devs)/sizeof(g_gptimer_devs[0]); i++)
    {
        if (0 == strcmp(name, g_gptimer_devs[i]->name))
		{

			return g_gptimer_devs[i];

		}
            
    }

    return NULL;
}


bool *GPTIMER_GetReloadFlag(struct GPTIMER_Device *pDev)
{
    if (pDev == NULL) return NULL;
    struct GPTIMER_Data *data = (struct GPTIMER_Data *)pDev->priv_data;
    return &data->timer_reload_flag;
}