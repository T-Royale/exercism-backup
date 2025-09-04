#include "difference_of_squares.h"
#include <stdint.h>
#include <math.h>
unsigned int sum_of_squares(unsigned int number){
    uint32_t suma=0;
    for(unsigned int i=1; i<=number; i++){
        suma+=pow(i, 2);
    }
    return suma;
}
unsigned int square_of_sum(unsigned int number){
    uint32_t suma=0;
    for(unsigned int i=0;i<=number;i++){
        suma+=i;
    }
    return pow(suma, 2);
}
unsigned int difference_of_squares(unsigned int number){
    unsigned int Suma_De_Cuadrados = sum_of_squares(number);
    unsigned int Cuadrado_De_La_Suma = square_of_sum(number);
    return Cuadrado_De_La_Suma - Suma_De_Cuadrados;
}