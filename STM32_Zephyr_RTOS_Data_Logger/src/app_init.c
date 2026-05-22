#include "common.h"

/*----------------------------------------------------------
 * Semaphore
 *---------------------------------------------------------*/

K_SEM_DEFINE(sensor_sem, 0, 1);

/*----------------------------------------------------------
 * Mutex
 *---------------------------------------------------------*/

K_MUTEX_DEFINE(buffer_mutex);

/*----------------------------------------------------------
 * Message Queue
 *---------------------------------------------------------*/

K_MSGQ_DEFINE(sensor_msgq, sizeof(struct sensor_data), 10, 4);

/*----------------------------------------------------------
 * Timer Callback
 *---------------------------------------------------------*/

void timer_handler(struct k_timer *timer)
{
    ARG_UNUSED(timer);

    k_sem_give(&sensor_sem);
}

/*----------------------------------------------------------
 * Software Timer
 *---------------------------------------------------------*/

K_TIMER_DEFINE(sensor_timer, timer_handler, NULL);

/*----------------------------------------------------------
 * Start Software Timer
 *---------------------------------------------------------*/

void start_timer(void)
{
    k_timer_start(&sensor_timer, K_MSEC(SENSOR_PERIOD_MS), K_MSEC(SENSOR_PERIOD_MS));
}
