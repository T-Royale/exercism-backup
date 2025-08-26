#include "eliuds_eggs.h"
int egg_count(const int eggs){
    int num = eggs;
    int count = 0;
    while (num > 0) {
        // Usa el operador AND bit a bit para verificar si el bit menos significativo es 1
        if (num & 1) {
            count++;
        }
        // Desplaza el número a la derecha para procesar el siguiente bit
        num >>= 1;
    }
    return count;
}