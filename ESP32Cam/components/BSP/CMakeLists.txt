set(src_dirs led/led.c
			 esptim/esptim.c
			 gptim/gptim.c
		
)

set(include_dirs led
				 esptim
				 gptim
)

set(requires driver
			 esp_timer
)

idf_component_register(SRCS ${src_dirs}
						   INCLUDE_DIRS ${include_dirs}
						   REQUIRES ${requires}
)


component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)