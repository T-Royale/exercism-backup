#include "perfect_numbers.h"
#include <stdlib.h>
int aliquot_sum(int number) {
    if (number <= 1) return -1;
    int sum = 1; // 1 es un divisor propio de cualquier número positivo
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int classify_number(int number) {
    if (number <= 0) return -1; // Añadir una verificación de entrada válida
    
    int sum = aliquot_sum(number);
    
    if (sum == number) return PERFECT_NUMBER;
    if (sum > number) return ABUNDANT_NUMBER;
    if (sum < number) return DEFICIENT_NUMBER;
    
    return 0;
}