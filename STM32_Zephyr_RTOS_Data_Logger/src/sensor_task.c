#include "common.h"
#include "temperature_sensor.h"
#include "rtc.h"
#include "sensor_task.h"

/*----------------------------------------------------------
 * Sensor Thread
 *---------------------------------------------------------*/

void sensor_thread(void)
{
    struct sensor_data data;

    while(1)
    {
        /* Take the Semaphore */
        k_sem_take(&sensor_sem, K_FOREVER);

        /* Get Data : temperature */
        data.temperature = temp_sensor_read();

        /* Get Data : rtc time */
        rtc_get_current_time(&data.timestamp);

        /* Put the data into message queue */
        k_msgq_put(&sensor_msgq, &data, K_NO_WAIT);
    }
}

/*----------------------------------------------------------
 * Thread Definition
 *---------------------------------------------------------*/

K_THREAD_DEFINE(sensor_thread_id,
                STACK_SIZE,
                sensor_thread,
                NULL,
                NULL,
                NULL,
                THREAD_PRIORITY,
                0,
                0);