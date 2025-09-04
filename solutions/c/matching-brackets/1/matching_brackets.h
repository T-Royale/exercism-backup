#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H


bool is_paired(const char *input);

typedef struct abierto_t {
    int pos;
    char value;
} abierto_t;

#endif
