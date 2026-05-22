#ifndef COMMON_H
#define COMMON_H

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/rtc.h>
#include <zephyr/logging/log.h>

#define STACK_SIZE             2048
#define THREAD_PRIORITY        5

#define LOG_BUFFER_SIZE        50

/* timer period */
#define SENSOR_PERIOD_MS        1000

/*----------------------------------------------------------
 * Sensor Data Structure
 *---------------------------------------------------------*/
struct sensor_data
{
    float temperature;
    struct rtc_time timestamp;
};

extern struct k_sem sensor_sem;
extern struct k_msgq sensor_msgq;
extern struct k_mutex buffer_mutex;

extern struct sensor_data log_buffer[LOG_BUFFER_SIZE];
extern uint32_t log_index;

#endif