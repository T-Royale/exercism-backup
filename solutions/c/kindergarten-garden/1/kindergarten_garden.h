#ifndef KINDERGARTEN_GARDEN_H
#define KINDERGARTEN_GARDEN_H

// Definición de la estructura `plants_t` y la enumeración `plant_t` antes de la declaración de la función.
typedef enum { CLOVER = 0, GRASS = 1, RADISHES = 2, VIOLETS = 3 } plant_t;

typedef struct {
    plant_t plants[4];
} plants_t;

// Declaración de la función con los parámetros correctos (const char*).
plants_t plants(const char* diagram, const char* student);

#endif