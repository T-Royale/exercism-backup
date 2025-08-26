#include "isogram.h"
#include <ctype.h>
#define ALPHABET_SIZE ('z' - 'a' + 1)
bool is_isogram(const char *phrase)
{
    if (!phrase)
        return false;
    bool seen[ALPHABET_SIZE] = {false};
    for (; *phrase; ++phrase)
    {
        unsigned char c = *phrase;
        if (!isalpha(c))
            continue;
        int idx = tolower(c) - 'a';
        if (seen[idx])
            return false;
        seen[idx] = true;
    }
    return true;
}