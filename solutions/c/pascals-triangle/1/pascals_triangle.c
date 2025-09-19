#include "pascals_triangle.h"

uint8_t **create_triangle(size_t rows){
    uint8_t **triangle;
    if(rows == 0){
        triangle = calloc(1, sizeof(uint8_t*));
        triangle[0] = calloc(1, sizeof(uint8_t));
        return triangle;
    }
    triangle = calloc(rows, sizeof(uint8_t*));
    for(size_t i = 0; i < rows; i++)
        triangle[i] = calloc(rows, sizeof(uint8_t));
    
    triangle[0][0] = 1;
    for(size_t n = 1; n < rows; n++){
        triangle[n][0] = 1;
        for(size_t k = 1; k < n; k++){
            triangle[n][k] = triangle[n-1][k-1] + triangle[n-1][k];
        }
        triangle[n][n] = 1;
    }
    return triangle;
}
void free_triangle(uint8_t **triangle, size_t rows){
    for(size_t i = 0; i < rows; i++)
        free(triangle[i]);
    free(triangle);
}