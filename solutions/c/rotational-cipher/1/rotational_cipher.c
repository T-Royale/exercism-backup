#include "rotational_cipher.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char *rotate(const char *text, int shift_key){
    int len = strlen(text);
    char *result = calloc(len+1, sizeof(char));
    strcpy(result, text);
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            result[i] = (text[i] - base + shift_key) % 26;
            if (result[i] < 0) result[i] += 26;
            result[i] += base;
        } else {
            result[i] = text[i];
        }
    }
    return result;
}