#ifndef PIG_LATIN_H
#define PIG_LATIN_H

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LEN 64

char *translate(const char *phrase);
int translate_word(char word[MAX_WORD_LEN]);

#endif
