
#ifndef RTC_H
#define RTC_H

#include "kernel/types.h"

extern uint32_t boottime;

void rtc_init();
void rtc_read(struct rtc_time *t);
uint32_t rtc_time_to_timestamp(struct rtc_time *t);

#endif
