#ifndef RTC_H
#define RTC_H

#include <zephyr/drivers/rtc.h>

int rtc_init_function(void);

void rtc_get_current_time(struct rtc_time *time);

#endif
