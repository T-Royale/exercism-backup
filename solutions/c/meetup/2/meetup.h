#ifndef MEETUP_H
#define MEETUP_H

#include <time.h>

#define days_in_week 	7
#define weeks_in_month 	4


int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week);
int get_wday(const char* day_of_week);
int get_weekn(const char* number);

#endif
