#include "roman_numerals.h"

char *to_roman_numeral(unsigned int number){
    char *result = calloc(1, MAX_LEN);
    int pos = 0;

    number_t formated_num = parsenum(number);
    //Calculate thousands
    for(int i = 0; i < formated_num.thousands; i++){
        result[pos++] = 'M';
    }
    //Calculate hundreds
    if(formated_num.hundreds == 9){
        result[pos++] = 'C';
        result[pos++] = 'M';
        formated_num.hundreds = 0;
    } else if(formated_num.hundreds >= 5){
        result[pos++] = 'D';
        formated_num.hundreds -= 5;
    } else if(formated_num.hundreds == 4 ){
        result[pos++] = 'C';
        result[pos++] = 'D';
        formated_num.hundreds = 0;
    } for(int i = 0; i < formated_num.hundreds; i++){
        result[pos++] = 'C';
    }
    //Calculate tens
    if(formated_num.tens == 9){
        result[pos++] = 'X';
        result[pos++] = 'C';
        formated_num.tens = 0;
    } else if(formated_num.tens >= 5){
        result[pos++] = 'L';
        formated_num.tens -= 5;
    } else if(formated_num.tens == 4 ){
        result[pos++] = 'X';
        result[pos++] = 'L';
        formated_num.tens = 0;
    } for(int i = 0; i < formated_num.tens; i++){
        result[pos++] = 'X';
    }
    //Calculate units
    if(formated_num.units == 9){
        result[pos++] = 'I';
        result[pos++] = 'X';
        formated_num.units = 0;
    } else if(formated_num.units >= 5){
        result[pos++] = 'V';
        formated_num.units -= 5;
    } else if(formated_num.units == 4 ){
        result[pos++] = 'I';
        result[pos++] = 'V';
        formated_num.units = 0;
    } for(int i = 0; i < formated_num.units; i++){
        result[pos++] = 'I';
    }
    result[pos] = '\0';

    return result;
}

number_t parsenum(unsigned int number){
    number_t result;

    result.thousands = number / 1000;
    number %= 1000;

    result.hundreds = number / 100;
    number %= 100;

    result.tens = number / 10;
    number %= 10;

    result.units = number;

    return result;
}