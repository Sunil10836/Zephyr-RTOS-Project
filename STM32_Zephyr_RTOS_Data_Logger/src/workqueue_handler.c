#include "common.h"
#include "workqueue_handler.h"

static void log_work_handler(struct k_work *work);

/*----------------------------------------------------------
 * Workqueue
 *---------------------------------------------------------*/

K_WORK_DEFINE(log_work, log_work_handler);

/*----------------------------------------------------------
 * Workqueue Handler
 *---------------------------------------------------------*/

static void log_work_handler(struct k_work *work)
{
    ARG_UNUSED(work);

    printk("Background logging Task is Running\n");
}

/*----------------------------------------------------------
 * Submit Log Work
 *---------------------------------------------------------*/

void submit_log_work(void)
{
    k_work_submit(&log_work);
}