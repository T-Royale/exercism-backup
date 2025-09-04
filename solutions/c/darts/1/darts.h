#ifndef DARTS_H
#define DARTS_H
#include <stdint.h>
//Struct of the coordinates
typedef struct {
    float x;
    float y;
} coordinate_t;
//Functions//
uint8_t score(coordinate_t land_pos);
coordinate_t absolute(coordinate_t a);
double pythagorean(coordinate_t coordinate);
#endif