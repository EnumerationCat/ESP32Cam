# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# Override COMPONENT_DIRS to prevent auto-discovery of PROJECT_DIR/components
# which would pick up unwanted AI/display components (who_detect, who_frame_lcd_disp, etc.)
# that require unsupported models on ESP32 target. Only include what's needed.

add_compile_options(-fdiagnostics-color=always)


include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(ESP32)
