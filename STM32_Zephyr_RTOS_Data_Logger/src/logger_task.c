#include "common.h"
#include "logger_task.h"
#include "workqueue_handler.h"

struct sensor_data log_buffer[LOG_BUFFER_SIZE];

uint32_t log_index = 0;

/*----------------------------------------------------------
 * Logger Thread
 *---------------------------------------------------------*/

void logger_thread(void)
{
    struct sensor_data rx_data;\

    while(1)
    {
        /* Get the data from message queue */
        k_msgq_get(&sensor_msgq, &rx_data, K_FOREVER);

        /* Mutex Lock */
        k_mutex_lock(&buffer_mutex, K_FOREVER);

        log_buffer[log_index++] = rx_data;

        if(log_index >= LOG_BUFFER_SIZE)
        {
            log_index = 0;
        }

        /* Mutex Unlock */
        k_mutex_unlock(&buffer_mutex);

        printk("[%02d:%02d:%02d] Temp = %.2f C\n",
                rx_data.timestamp.tm_hour,
                rx_data.timestamp.tm_min,
                rx_data.timestamp.tm_sec,
                (double) rx_data.temperature);

        submit_log_work();
    }
}

/*----------------------------------------------------------
 * Thread Definition
 *---------------------------------------------------------*/

/* Creating logger thread */
K_THREAD_DEFINE(logger_thread_id,
                STACK_SIZE,
                logger_thread,
                NULL,
                NULL,
                NULL,
                THREAD_PRIORITY,
                0,
                0);