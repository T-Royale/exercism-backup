#include "sublist.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count, size_t base_list_element_count) {
    // Caso en que ambas listas están vacías
    if (base_list_element_count == 0 && list_to_compare_element_count == 0) {
        return EQUAL;
    }

    bool base_list_is_bigger;
    int *lista_grande;
    int *lista_pequeña;
    size_t elementos_lista_grande;
    size_t elementos_lista_pequeña;

    // Determinar cuál lista es más grande, o si son iguales en tamaño
    if (base_list_element_count > list_to_compare_element_count) {
        base_list_is_bigger = true;
        lista_grande = base_list;
        lista_pequeña = list_to_compare;
        elementos_lista_grande = base_list_element_count;
        elementos_lista_pequeña = list_to_compare_element_count;
    } else if (base_list_element_count < list_to_compare_element_count) {
        base_list_is_bigger = false;
        lista_grande = list_to_compare;
        lista_pequeña = base_list;
        elementos_lista_grande = list_to_compare_element_count;
        elementos_lista_pequeña = base_list_element_count;
    } else {
        // Mismo tamaño, comprobar si son iguales
        bool son_iguales = true;
        for (size_t i = 0; i < base_list_element_count; i++) {
            if (base_list[i] != list_to_compare[i]) {
                son_iguales = false;
                break;
            }
        }
        return (son_iguales) ? EQUAL : UNEQUAL;
    }

    // Si la lista pequeña está vacía, es sublista o superlista
    if (elementos_lista_pequeña == 0) {
        return (base_list_is_bigger) ? SUBLIST : SUPERLIST;
    }

    // Buscar todas las ocurrencias del primer elemento de la lista pequeña en la lista grande
    // Primero contamos cuántas ocurrencias hay
    size_t count = 0;
    for (size_t i = 0; i < elementos_lista_grande; i++) {
        if (lista_grande[i] == lista_pequeña[0]) {
            count++;
        }
    }

    // Si no hay ninguna coincidencia
    if (count == 0) {
        return UNEQUAL;
    }

    // Ahora que sabemos cuántas ocurrencias hay, reservamos memoria para guardarlas
    size_t *pos = malloc(count * sizeof(size_t));
    if (!pos) {
        // Si no se puede asignar memoria, regresar un error genérico
        return UNEQUAL; 
    }

    // Volvemos a iterar para guardar las posiciones
    size_t idx = 0;
    for (size_t i = 0; i < elementos_lista_grande; i++) {
        if (lista_grande[i] == lista_pequeña[0]) {
            pos[idx++] = i;
        }
    }

    // Array que guardará si pos[i] es el inicio de una sublista
    bool *hay_sublista = malloc(count * sizeof(bool));
    if (!hay_sublista) {
        free(pos);
        return UNEQUAL;
    }
    for (size_t j = 0; j < count; j++) {
        hay_sublista[j] = true;
    }

    // Mirar en cada una de las coincidencias si forman la sublista completa
    for (size_t i = 0; i < count; i++) {
        // Verificar primero si hay suficiente espacio para todos los elementos de la lista pequeña
        if (pos[i] + elementos_lista_pequeña > elementos_lista_grande) {
            hay_sublista[i] = false;
            continue;
        }

        for (size_t j = 0; j < elementos_lista_pequeña; j++) {
            if (lista_grande[pos[i] + j] != lista_pequeña[j]) {
                hay_sublista[i] = false;
                break;
            }
        }
    }

    // Comprobar si alguna coincidencia era el comienzo de una sublista
    for (size_t i = 0; i < count; i++) {
        if (hay_sublista[i]) {
            free(hay_sublista);
            free(pos);
            return (base_list_is_bigger) ? SUBLIST : SUPERLIST;
        }
    }

    // Si ninguna coincidencia resultó ser una sublista completa
    free(hay_sublista);
    free(pos);
    return UNEQUAL;
}
