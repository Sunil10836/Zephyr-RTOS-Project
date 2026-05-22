#include "rtc.h"

const struct device *rtc_dev = DEVICE_DT_GET(DT_NODELABEL(rtc));

/*----------------------------------------------------------
 * RTC Init
 *---------------------------------------------------------*/

int rtc_init_function(void)
{
    int ret;

    /* Check rtc device */
	if(! device_is_ready(rtc_dev)){
		printk("rtc is not ready\r\n");
		return 0;
	}

    //set time
	struct rtc_time time = {
		.tm_sec = 00,
		.tm_min = 00,
		.tm_hour = 11,
		.tm_mday = 20,
		.tm_mon = 5,
		.tm_year = 2026-1900,
		.tm_wday = 3,
	};

	ret = rtc_set_time(rtc_dev, &time);

	if(ret < 0) {
		printk("Failed to Set RTC Time: %d\n", ret);
		return 0;
	}

    printk("RTC Time Set\n");

    return 0;
}

/*----------------------------------------------------------
 * RTC Get Current Time
 *---------------------------------------------------------*/

void rtc_get_current_time(struct rtc_time *time)
{
    rtc_get_time(rtc_dev, time);
}