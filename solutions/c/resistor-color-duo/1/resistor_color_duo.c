#include "resistor_color_duo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
int color_code(resistor_band_t color[]){
    char value1[5];
    char value2[5];
    sprintf(value1, "%d", color[0]);
    sprintf(value2, "%d", color[1]);
    int total;
    strcat(value1, value2);
    sscanf(value1, "%d", &total);
    return total;
}