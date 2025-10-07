#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct triplet_t {
    uint16_t a;
    uint16_t b;
    uint16_t c;
} triplet_t;

typedef struct triplets_t {
    triplet_t* triplets;
    uint16_t count;
}triplets_t;

triplets_t *triplets_with_sum(uint16_t);
void free_triplets(triplets_t*);
void swap(uint16_t *x, uint16_t *y);
bool coprimos(uint16_t m, uint16_t n);

#endif
