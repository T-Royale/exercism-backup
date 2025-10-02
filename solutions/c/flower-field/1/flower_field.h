#ifndef FLOWER_FIELD_H
#define FLOWER_FIELD_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char **annotate(const char **garden, const size_t rows);
bool check_square(const char** garden, const size_t len, const size_t rows, int check_x, int check_y);
void free_annotation(char **annotation);

#endif
