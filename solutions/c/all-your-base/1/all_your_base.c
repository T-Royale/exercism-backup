#include "all_your_base.h"
size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length){
    if (input_base < 2 || output_base < 2 || input_length == 0) return 0; // Casos inválidos
    int32_t value = 0;    //Valor
    for (size_t i = 0; i < input_length; i++) {
        if (digits[i] < 0 || digits[i] >= input_base) return 0;
        value = value * input_base + digits[i];
    }
    if (value == 0) {
        digits[0] = 0;
        return 1;
    }
    //Pasar números a la base correcta pero al revés
    size_t index = 0;
    int8_t temp[DIGITS_ARRAY_SIZE] = {0};
    while (value > 0 && index < DIGITS_ARRAY_SIZE){
        temp[index] = value % output_base;
        value /= output_base;
        index++;
    }
    //Ordenar dígitos
    for (size_t i = 0; i < index; i++) {
        digits[i] = temp[index - 1 - i];
    }
    return index;
}