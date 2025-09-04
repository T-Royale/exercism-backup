#include "resistor_color_duo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
int color_code(resistor_band_t color[]){
    //Create strings to convert the numbers to them
    char value1[3];    //Size has to be < 2 for sprintf() to work
    char value2[3];
    //Convert the numbers into strings so we can strcat() them
    sprintf(value1, "%d", color[0]);
    sprintf(value2, "%d", color[1]);
    //Create the variable for the result
    int total;
    //Concatenate the strings
    strcat(value1, value2);
    //Turn the value to an integer again
    sscanf(value1, "%d", &total);
    //Return the new value
    return total;
}