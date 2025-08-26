#include "scrabble_score.h"
#include <string.h>
#include <ctype.h>

#define char_offset 97

unsigned int score(const char *word){
    int score['z' - char_offset + 1] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    unsigned int result = 0;
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        char c = (isupper(word[i])) ? tolower(word[i]) : word[i];
        result += score[c - char_offset];
    }
    return result;
}