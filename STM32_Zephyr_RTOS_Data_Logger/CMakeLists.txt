#-------------------------------------------------------------------------------
# STM32 Zephyr RTOS Data Logger 
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(014_STM32_Dummy_Temp_Sensor)

# Add source files
target_sources(app PRIVATE src/main.c
                            src/temperature_sensor.c
                            src/rtc.c
                            src/sensor_task.c
                            src/logger_task.c
                            src/workqueue_handler.c
                            src/app_init.c)

# Add include directory
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)