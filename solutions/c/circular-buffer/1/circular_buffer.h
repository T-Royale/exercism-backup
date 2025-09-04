#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>

typedef int16_t buffer_value_t;

typedef struct circular_buffer_t{
    buffer_value_t *content;    // Circular buffer content
    int16_t size;               // Circular buffer size
    int16_t write;              // Índice de escritura
    int16_t read;               // Índice de escritura
    int16_t oldest;             // Valor más antiguo
    bool full;                  // Está lleno?
} circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t size);

void clear_buffer(circular_buffer_t *buffer);

int16_t read(circular_buffer_t *buffer, buffer_value_t *value);

int16_t write(circular_buffer_t *buffer, buffer_value_t value);

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);

void delete_buffer(circular_buffer_t *buffer);

#endif
