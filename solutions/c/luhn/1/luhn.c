#include "luhn.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool luhn(const char *num) {
    int cadena[50] = {0};
    int len = strlen(num);

    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == ' ') continue;

        if (!isdigit(num[i])) return false;

        int digit = num[i] - '0';

        if (j % 2 == 1) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        cadena[j++] = digit;
    }

    int sum = 0;
    for (int i = 0; i < j; i++) {
        sum += cadena[i];
    }

    if (j <= 1) return false;

    return (sum % 10 == 0);
}

// > <