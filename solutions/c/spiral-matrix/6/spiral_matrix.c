#include "spiral_matrix.h"

spiral_matrix_t *spiral_matrix_create(int size){
    spiral_matrix_t *result = malloc(sizeof(spiral_matrix_t));

    if(result == NULL){
        fprintf(stderr, "Error al reservar memoria para result\n");
        exit(1);
    }// else printf("Estructura asigndada correctamente\n");
    
    result->size = size;

    result->matrix = malloc((size+1) * sizeof(int *));
    if(result->matrix == NULL){
        fprintf(stderr, "Error al inicializar la matriz (1)\n");
        exit(1);
    }// else printf("Memoria asignada correctamente(1)\n");

    if(result->size == 0) {
        result->matrix = NULL;
        return result;
    }

    for(int i = 0; i < size; i++){
        result->matrix[i] = malloc(size * sizeof(int));
        if(result->matrix[i] == NULL){
            fprintf(stderr, "Error al inicializar la matriz (2)\n");
            exit(1);
        }
    }

    // Inicializar todas las casillas a -1
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            result->matrix[i][j] = -1;
        }
    }

    position_t pos_actual = {0, 0, {true, true, true}};
    // Rellenar casillas, el último elemento de la matriz es <<result->matrix[size][size]>>
    int n = 1;
    for(int i = 0; i < size*size; i++){
        result->matrix[pos_actual.y][pos_actual.x] = n;
        // Evitar sobreescrituras
        if(i < size*size-1){
            position_t pos_prueba = siguientePos(pos_actual);
            // 1. Verificar que 'pos_prueba' está dentro de la matriz
            bool dentroDeRango = (pos_prueba.x >= 0 && pos_prueba.x < size && pos_prueba.y >= 0 && pos_prueba.y < size);

            if (dentroDeRango && result->matrix[pos_prueba.y][pos_prueba.x] == -1) {
                // Si está en rango y sin ocupar, avanzas
                pos_actual = pos_prueba;
            } else {
                // Si está fuera de rango o no es -1, giras
                pos_actual.direccion = nextDirection(pos_actual.direccion);
                pos_actual = siguientePos(pos_actual);
            }
        }
        n++;
    }

    // Poner NULL en el ultimo elemento para saber donde termina
    result->matrix[size] = NULL;

    return result;
}

direction_t nextDirection(direction_t current){
    direction_t result;
    if(current.leftToRight == true && current.upToDown == true){
        result.leftToRight = false;
        result.upToDown = true;
    } else if(current.leftToRight == false && current.upToDown == true){
        result.leftToRight = false;
        result.upToDown = false;
    } else if(current.leftToRight == false && current.upToDown == false){
        result.leftToRight = true;
        result.upToDown = false;
    } else if(current.leftToRight == true && current.upToDown == false){
        result.leftToRight = true;
        result.upToDown = true;
    }
    result.horizontal = !current.horizontal;
    return result;
}

// Calcula siguiente posición
position_t siguientePos(position_t posicion){
    position_t result = {posicion.x, posicion.y, posicion.direccion};
    if (posicion.direccion.horizontal && posicion.direccion.leftToRight){
        result.x++;    // -->
    } else if (posicion.direccion.horizontal && !posicion.direccion.leftToRight){
        result.x--;    // <--
    } else if (!posicion.direccion.horizontal && posicion.direccion.upToDown){
        result.y++;    //  v
    } else if (!posicion.direccion.horizontal && !posicion.direccion.upToDown){
        result.y--;    //  ^
    }
    return result;
}

void spiral_matrix_destroy(spiral_matrix_t *matrix){
    if(matrix->matrix == NULL){
        free(matrix->matrix);
        free(matrix);
        return;
    }
    size_t i = 0;
    while (matrix->matrix[i] != NULL) {
        free(matrix->matrix[i]);
        matrix->matrix[i] = NULL;
        i++;
    }

    free(matrix->matrix);
    matrix->matrix = NULL;

    free(matrix);
    matrix = NULL;
}