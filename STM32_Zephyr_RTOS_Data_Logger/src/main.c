/***********************************************************
Project Name : STM32 Zephyr RTOS Data Logger 
Author 		 : Sunil Sutar
Date   		 : 21-05-2026

Description  : This project demonstrates real-time sensor acquisition, 
			   inter-thread communication, synchronization, and 
			   modular firmware architecture.
*********************************************************** */

#include "common.h"
#include "temperature_sensor.h"
#include "rtc.h"
#include "sensor_task.h"
#include "logger_task.h"
#include "app_init.h"

/*----------------------------------------------------------
 * main function
 *---------------------------------------------------------*/

int main()
{
	printk("STM32 Zephyr RTOS Data Logger\n");

	/* temperature sensor init */
	temp_sensor_init();

	/* rtc init */
	if(rtc_init_function() != 0) {
		printk("RTC Init Failed\n");
		return 0;
	}

	/* start timer */
	start_timer();

	while(1)
	{
		k_sleep(K_SECONDS(1));
	}

	return 0;
}
