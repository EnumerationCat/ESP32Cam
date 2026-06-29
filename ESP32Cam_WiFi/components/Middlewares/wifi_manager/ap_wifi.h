#ifndef __AP_WIFI_H
#define __AP_WIFI_H


#ifdef __cplusplus
extern "C" {
#endif
#include "wifi_manager.h"

/** wifi功能和ap配网功能初始化
 * @param f wifi连接状态回调函数
 * @return 无 
*/
void ap_wifi_init(p_wifi_state_cb f);

/** 连接某个热点
 * @param ssid
 * @param password
 * @return 无 
*/
void ap_wifi_set(const char* ssid,const char* password);

/** 启动配网模式
 * @param enable 暂无用，强制true
 * @return 无 
*/
void ap_wifi_apcfg(bool enable);

#ifdef __cplusplus
}
#endif
#endif // __AP_WIFI_H