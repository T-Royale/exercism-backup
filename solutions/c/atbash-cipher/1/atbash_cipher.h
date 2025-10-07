#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H

#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *atbash_encode(const char *input);
char *atbash_decode(const char *input);

#endif
