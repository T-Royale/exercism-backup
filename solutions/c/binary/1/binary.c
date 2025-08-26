#include "binary.h"
#include <string.h>
#include <math.h>
#include <stdint.h>
//principal function
int invalid(const char *string, int len){
    for(int i = 0; i < len; i++){
        if(string[i] != '1' && string[i] != '0') return 1;
    }
    return 0;
}
int convert(const char *input){
    //integer with the lenght of the binary
    const int len = strlen(input);
    if(invalid(input, len)) return -1;
    //finar result
    int result = 0;
    //conversion
    for (int i = 0; i < len; i++) {
        if (input[len - 1 - i] == '1') {
            result += 1 << i; // 2^i
        }
    }
    return result;
}