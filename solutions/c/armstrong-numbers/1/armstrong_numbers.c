#include "armstrong_numbers.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

bool is_armstrong_number(int a) {
    int dup_a = a;
    char numero_str[20]; // Elige un tamaño suficientemente grande para la cadena
    sprintf(numero_str, "%d", dup_a);
    int ncifras = strlen(numero_str);
    int cifras[ncifras];
    int num_comprobacion = 0;
    for(int i = 0; i < ncifras; i++) {
        cifras[i] = dup_a % 10;
        dup_a /= 10;
    }
    for(int i = 0; i < ncifras; i++) {
        num_comprobacion += pow(cifras[i], ncifras);
    }
    return num_comprobacion == a;
}