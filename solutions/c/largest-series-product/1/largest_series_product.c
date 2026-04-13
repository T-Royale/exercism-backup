#include "largest_series_product.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int64_t largest_series_product(char* digits, size_t span) {
    size_t len = strlen(digits);
    if (len <= 0 || len < span) return -1;
    int64_t max = 0;
    char* pos = digits;
    char* serie = calloc(span + 1, sizeof(char));
    for (size_t i = 0; i < len - (span - 1); i++) {
        strncpy(serie, pos, span);
        int64_t n = 1;
        for (size_t j = 0; j < span; j++) {
            if (!isdigit(serie[j])) return -1;
            n *= serie[j] - '0';
        }
        if (n > max) max = n;
        pos++;
    }
    return max;
}
