#ifndef RAIL_FENCE_CIPHER_H
#define RAIL_FENCE_CIPHER_H

#include <stddef.h>

typedef enum{
	ENCODE,
	DECODE,
} operations_e;

char *rail_fence_cipher(char* text, size_t rails, operations_e op);

char *encode(char *text, size_t rails);

char *decode(char *ciphertext, size_t rails);

#endif
