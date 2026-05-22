#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "temperature_sensor.h"

static float dummy_temperature = 30.0f;

/*----------------------------------------------------------
 * Dummy Temperature Sensor Init
 *---------------------------------------------------------*/

int temp_sensor_init(void)
{
    printk("Dummy Temperature sensor initialized\n");

    return 0;
}

/*----------------------------------------------------------
 * Dummy Temperature Sensor Read
 *---------------------------------------------------------*/

float temp_sensor_read(void)
{
    dummy_temperature += 0.5f;

     if (dummy_temperature > 40.0f) {
        dummy_temperature = 30.0f;
    }

    return dummy_temperature;
} 