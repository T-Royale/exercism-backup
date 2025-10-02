#ifndef ETL_H
#define ETL_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define size 26   // 26 letters of the alphabet

typedef struct {
   int value;
   const char *keys;
} legacy_map;

typedef struct {
   char key;
   int value;
} new_map;

int convert(const legacy_map *input, const size_t input_len, new_map **output);

#endif
