#include "crypto_square.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ciphertext(const char* input) {
    const size_t len = strlen(input);
    char* buff = calloc(len + 1, sizeof(char));
    char* pos = buff;
    char* result = calloc(len + 1, sizeof(char));
    // Format input
    for (size_t i = 0; i < len; i++) {
        if (isalnum(input[i])) *pos++ = tolower(input[i]);
    }
    if(len <= 0) return buff;
    // Get cols and rows
    const size_t buff_len = strlen(buff);
    size_t c, r;
    for (size_t i = 1; i <= buff_len; i++) {
        if (i * ( i - 1 ) >= buff_len) {
            c = i;
            r = i - 1;
            break;
        } else if (i * i >= buff_len) {
            c = i;
            r = i;
            break;
        }
    }
    printf("c is %zu, r is %zu\n", c, r);
    // cipher text
    pos = result;
    for (size_t i = 0; i < c; i++) {
        for (size_t j = 0; j < r; j++) {
            size_t write = j * c + i;
            *pos++ = (write >= buff_len) ? ' ' : buff[write];
        }
        if (i < c - 1) {
            *pos++ = ' ';
        }
    }
    *pos = '\0';
    return result;
}
