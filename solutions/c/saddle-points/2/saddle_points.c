#include "saddle_points.h"

// El más grande en su fila
// pero el mas pequeño en su columna


saddle_points_t *saddle_points(uint8_t row_count, uint8_t column_count, uint8_t matrix[row_count][column_count]){
	saddle_points_t valids = {0};

	// Ver los mayores de su fila
	for(uint8_t x = 0; x < row_count; x++){
		saddle_points_t max = {0};
		uint8_t max_value = matrix[x][0];
		for(uint8_t y = 0; y < column_count; y++){
			if(matrix[x][y] > max_value){
				max_value = matrix[x][y]; 
				max.count = 1;
				max.points[0].row = x;
				max.points[0].column = y;
			} else if(matrix[x][y] == max_value){
				max.points[max.count].row = x;
				max.points[max.count++].column = y;
			}
		}
		for(uint8_t i = 0; i < max.count; i++){
			valids.points[valids.count].row = max.points[i].row;
			valids.points[valids.count++].column = max.points[i].column;
		}
	}
	// Ver si son los menores de su columna 
	saddle_points_t *result = malloc(sizeof(saddle_points_t));
	if(!result) return NULL;
	result->count = 0;

	for(uint8_t i = 0; i < valids.count; i++){
		bool isSaddle = true;

		for(uint8_t j = 0; j < row_count; j++){
			if(matrix[j][valids.points[i].column] < matrix[valids.points[i].row][valids.points[i].column]) {
				isSaddle = false;
				break;
			}
		}

		if(isSaddle){
			result->points[result->count].row = valids.points[i].row + 1;
			result->points[result->count++].column = valids.points[i].column + 1;
		}
	}
	// Devolver los restantes
	return result;
}

void free_saddle_points(saddle_points_t* actual){
	free(actual);
}