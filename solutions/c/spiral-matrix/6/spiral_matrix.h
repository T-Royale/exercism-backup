#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef SPIRAL_MATRIX_H
#define SPIRAL_MATRIX_H

typedef struct {
   int size;
   int **matrix;
} spiral_matrix_t;

typedef struct direction_t{
    bool leftToRight;
    bool upToDown;
    bool horizontal;
} direction_t;

typedef struct {
    int x;
    int y;
    direction_t direccion;    
} position_t;

spiral_matrix_t *spiral_matrix_create(int size);

void spiral_matrix_destroy(spiral_matrix_t *matrix);

position_t siguientePos(position_t posicion);

direction_t nextDirection(direction_t current);


#endif
