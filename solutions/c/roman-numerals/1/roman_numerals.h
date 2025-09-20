#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

#include <stdlib.h>
#include <stdio.h>
#define MAX_LEN 64

typedef struct {
    int units;
    int tens;
    int hundreds;
    int thousands;
} number_t;

char *to_roman_numeral(unsigned int number);
number_t parsenum(unsigned int);

#endif
