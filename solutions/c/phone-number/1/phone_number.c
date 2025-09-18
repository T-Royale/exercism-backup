#include "phone_number.h"

char *phone_number_clean(const char *input){
    int len = strlen(input);
    const int MAX_PHONE_LEN = 10;
    char* result = calloc(1, MAX_PHONE_LEN+1);  // space for the \0 terminator
    int pos = 0;
    int i = 0;
    if(input[0] == '1') i = 1;
    for(; i < len; i++){
        if(pos >= MAX_PHONE_LEN+1){
            strncpy(result, "0000000000", 11);
            return result;
        }
        switch(input[i]){
            case '0':
                result[pos++] = '0';
                break;
            case '1':
                result[pos++] = '1';
                break;
            case '2':
                result[pos++] = '2';
                break;
            case '3':
                result[pos++] = '3';
                break;
            case '4':
                result[pos++] = '4';
                break;
            case '5':
                result[pos++] = '5';
                break;
            case '6':
                result[pos++] = '6';
                break;
            case '7':
                result[pos++] = '7';
                break;
            case '8':
                result[pos++] = '8';
                break;
            case '9':
                result[pos++] = '9';
                break;
            case '+':
                i++;
                break;
            default:
                break;
        }
    }
    if(result[0] < '2' ||  result[3] < '2'){
        strncpy(result, "0000000000", 11);
        return result;
    }
    if(pos != 10)
        strncpy(result, "0000000000", 11);
    return result;
}