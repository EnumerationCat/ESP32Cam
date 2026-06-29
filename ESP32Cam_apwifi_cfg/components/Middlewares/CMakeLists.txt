set(src_dirs wifi_manager/wifi_manager.c
			 wifi_manager/websocket_server.c
			 wifi_manager/ap_wifi.c

)

set(include_dirs wifi_manager

)

set(requires driver
			 esp_wifi
             esp_event
			 esp_http_server
			 json
			 spiffs


)

idf_component_register(SRCS ${src_dirs}
						   INCLUDE_DIRS ${include_dirs}
						   REQUIRES ${requires}
)


component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)