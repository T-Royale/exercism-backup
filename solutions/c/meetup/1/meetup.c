#include "meetup.h"
#include <stdio.h>
#include <string.h>

int get_wday(const char* day_of_week){
	const char* days[days_in_week] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	for(int day = 0; day < days_in_week; day++){
		if(strcmp(days[day], day_of_week) == 0) return day;	
	}
	printf("get-wday failed\n");
	return -1;
}

int get_weekn(const char* number){
	const char* weeks[weeks_in_month] = {"first", "second", "third", "fourth"};
	for(int week = 0; week < weeks_in_month; week++){
		if(strcmp(weeks[week], number) == 0) return week+1;	
	}
	printf("get-weekn failed\n");
	return -1;
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week){
	struct tm time = {0};
	time.tm_year = year-1900;
	time.tm_mon = month-1;
	const int wday=get_wday(day_of_week);
	
	if(strcmp(week, "teenth") == 0){
		for(int i = 13; i <= 19; i++){
			time.tm_mday = i;		
			mktime(&time);
			if(time.tm_wday == wday){
				return i;
			}
		}
	} else if(strcmp(week, "last") == 0) {
		time.tm_mday = 0;
		time.tm_mon++;
		mktime(&time);
		int days_until_target = (time.tm_wday+1) - (wday+1);
		if(days_until_target < 0) days_until_target = days_until_target + days_in_week;
		printf("%d - %d\n", time.tm_mday, days_until_target);
		return time.tm_mday - days_until_target;
	} else {
		const int weekn = get_weekn(week);
		int i;
		for(i = 1; i <= days_in_week; i++){
			time.tm_mday = i;
			mktime(&time);
			if(time.tm_wday == wday) break;
		}
		return i+((weekn-1)*days_in_week);
	}

	return 0;
}