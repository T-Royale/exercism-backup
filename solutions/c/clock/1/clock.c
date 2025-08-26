#include "clock.h"
#include <stdio.h>
#include <string.h>
clock_t clock_create(int hour, int minute){
    clock_t result = {0};
    int time = hour * 60 + minute;
    int c_hour = (time / 60) % 24;
    int c_min = time % 60;
    if (c_min < 0) {
        c_min += 60;
        c_hour--;
    }
    if (c_hour < 0) c_hour += 24;
    if (c_hour >= 0 && c_hour < 24 && c_min >= 0 && c_min < 60) {
        snprintf(result.text, MAX_STR_LEN, "%02d:%02d", c_hour, c_min);
    }
    return result;
}

bool clock_is_equal(clock_t a, clock_t b){
    return strcmp(a.text, b.text) == 0;
}































clock_t clock_add(clock_t clock, int minute_add){
    int hours = 0;
    int minutes = 0;
    sscanf(clock.text, "%02d:%02d", &hours, &minutes);
    minutes += minute_add;
    while(minutes >= 60) {
        minutes -= 60;
        hours++;
    }
    hours %= 24;
    clock_t result = {0};
    sprintf(result.text, "%02d:%02d", hours, minutes);
    return result;
}
clock_t clock_subtract(clock_t clock, int minute_subtract){
    int hours = 0;
    int minutes = 0;
    sscanf(clock.text, "%02d:%02d", &hours, &minutes);
    minutes -= minute_subtract;
    while (minutes < 0) {
        minutes += 60;
        hours--;
    }
    while(hours < 0) hours += 24;
    clock_t result = {0};
    sprintf(result.text, "%02d:%02d", hours, minutes);
    return result;
}