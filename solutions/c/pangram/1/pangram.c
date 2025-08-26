#include "pangram.h"
#include <string.h>
#include <ctype.h>
bool is_pangram(const char *sentence){
    if(sentence == NULL) return false;
    for (char c = 'a'; c <= 'z'; c++) {
        // Buscar tanto minúsculas como mayúsculas
        if (!strchr(sentence, tolower(c)) && !strchr(sentence, toupper(c))) {
            return false;
        }
    }
    return true;
}