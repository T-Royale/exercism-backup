#include "isogram.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool is_isogram(const char *frase) {
    if (frase == NULL) {
        return false;
    }
    bool LetrasVistas[26] = {false};
    for (size_t i = 0; i < strlen(frase); i++) {
        if (!isalpha(frase[i])) {
            continue; 
        }
        char Letra = tolower(frase[i]);
        int indice = Letra - 'a';
        if (LetrasVistas[indice]) {
            return false;
        } else {
            LetrasVistas[indice] = true;
        }
    }
    return true;
}

