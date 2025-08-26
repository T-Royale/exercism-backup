#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#define MAX_SADDLE_POINTS 9

typedef struct saddle_point_t{
    uint8_t row;
    uint8_t column;
} saddle_point_t;

typedef struct saddle_points_t{
    size_t count;
    saddle_point_t points[MAX_SADDLE_POINTS];
} saddle_points_t;

saddle_points_t *saddle_points(uint8_t row_count, uint8_t column_count, uint8_t matrix[row_count][column_count]);

void free_saddle_points(saddle_points_t* actual);

#endif
