set(src_dirs led/led.c
			 esptim/esptim.c
			 gptim/gptim.c
			 camera/camera.c
		
)

set(include_dirs led
				 esptim
				 gptim
				 camera
)

set(requires driver
			 esp_timer
			 espressif__esp32-camera
			 

)

idf_component_register(SRCS ${src_dirs}
						   INCLUDE_DIRS ${include_dirs}
						   REQUIRES ${requires}
)


component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)