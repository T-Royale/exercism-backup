#include "resistor_color_trio.h"
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
//devolverá la unidad y de paso convertirá el resto al equivalente en esta unidad 
int unidades(resistor_band_t color, int *resto){
    *resto += color;
    int unidad = 0;
    if(*resto >= GIGAOHMS) {
        unidad = GIGAOHMS;
        *resto -= GIGAOHMS;
    }
    else if(*resto >= MEGAOHMS) {
        unidad = MEGAOHMS;
        *resto -= MEGAOHMS;
    }
    else if(*resto >= KILOOHMS) {
        unidad = KILOOHMS;
        *resto -= KILOOHMS;
    }
    else unidad = OHMS;
    return unidad;
}

resistor_value_t color_code(resistor_band_t resistor[]) {
    resistor_value_t resistencia;    //resistencia del resistor
    int resto = 0;
    if(resistor[1] == 0){
        resto = 1;
        resistencia.value = resistor[0];
    }
    else resistencia.value = resistor[1] + (resistor[0] * 10);
    resistencia.unit = unidades(resistor[2], &resto);
    //número por el que multiplicar los dos dígitos juntos
    double multiplicador = pow(10, resto);
    resistencia.value *= (int)multiplicador;
    return resistencia;
}







