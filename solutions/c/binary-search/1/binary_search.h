#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>
#include <stdbool.h>
//Value = valor que queremos encontrar en la lista
//Arr = puntero a lista
//Length = Longitud de lista
const int *binary_search(int value, const int *arr, size_t length);

#endif
