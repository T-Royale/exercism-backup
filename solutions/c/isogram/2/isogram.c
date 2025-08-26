#include "isogram.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool is_isogram(const char *phrase) {
    if (phrase == NULL) {
        return false;
    }
    bool LetrasVistas[26] = {false};
    for (size_t i = 0; i < strlen(phrase); i++) {
        if (!isalpha(phrase[i])) {
            continue; 
        }
        char Letra = tolower(phrase[i]);
        int indice = Letra - 'a';
        if (LetrasVistas[indice]) {
            return false;
        } else {
            LetrasVistas[indice] = true;
        }
    }
    return true;
}

