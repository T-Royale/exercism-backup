#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value){
    int len = strlen(value);
    char* result = malloc((len+1)*sizeof(char));
    for(int i = 0; i < len; i++){
        result[i] = value[len-1-i];
    }
    result[len] = '\0';
    return result;
}