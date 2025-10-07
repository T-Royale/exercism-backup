#include "pythagorean_triplet.h"

triplets_t *triplets_with_sum(uint16_t sum){
    if(sum < 3) return NULL;
    triplets_t *result = malloc(sizeof(triplets_t));
    result->count = 0;
    result->triplets = NULL;
    uint16_t m, n;
    uint16_t limit = sqrt(sum/2);
    for(m = 2; m <= limit; m++){
        for(n = 1; n < m; n++){
            if (((m - n) % 2 == 0) || !coprimos(m, n)) continue;
            // Calcular los tripletes
            uint16_t sum_prim = 2 * m * (m + n);
            if (sum % sum_prim != 0) continue;

            uint16_t k = sum / sum_prim;

            uint16_t a = k * (m*m - n*n);
            uint16_t b = k * (2*m*n);
            uint16_t c = k * (m*m + n*n);

            // Ordenar
            if (c < b) swap(&c, &b);
            if (c < a) swap(&c, &a);
            if (b < a) swap(&b, &a);
            // Crear espacio para los tripletes
            if(result->count == 0){
                result->triplets = calloc(1, sizeof(triplet_t));
                if(!result->triplets) {
                    return NULL;
                }
            } else {
                void* tmp = realloc(result->triplets, sizeof(triplet_t)*(result->count+1));
                if(!tmp){
                    continue;
                }
                result->triplets = tmp;
            }
            result->triplets[result->count].a = a;
            result->triplets[result->count].b = b;
            result->triplets[result->count].c = c;
            result->count++;
        }
        // Comprobar resultados
        /*printf("El número de tripletes encontrados es de %d\n", result->count);
        for(int i = 0; i < result->count; i++){
            printf("Resultado nº%d\n\ta = %d\n\tb = %d\n\tc = %d\n", i, result->triplets[i].a, result->triplets[i].b, result->triplets[i].c);
        }*/
    }
    return result;
}
void free_triplets(triplets_t* triplets){
    if(triplets){
        if(triplets->triplets){
            free(triplets->triplets);
        }
        free(triplets);
    }
}

bool coprimos(uint16_t m, uint16_t n){
    int a = m, b = n;
    while(b != 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return (a == 1);
}

void swap(uint16_t *x, uint16_t *y) {
    uint16_t temp = *x;
    *x = *y;
    *y = temp;
}