#include "gigasecond.h"
#define GIGASECOND 1000000000

void gigasecond(time_t input, char *output, size_t size){
    time_t new_time = input + GIGASECOND;
    struct tm *gmtimeinfo;
    gmtimeinfo = gmtime(&new_time);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", gmtimeinfo);
}