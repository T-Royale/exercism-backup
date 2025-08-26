#include "beer_song.h"
#include <string.h>
#include <stdio.h>
/*NOTA: song es un puntero doble lo cual quiere decir que cada song[i] es un arreglo de caracteres*/

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
    int bottles = start_bottles;
    int line_index = 0; // para saber en qué línea escribimos

    for (int i = 0; i < take_down; i++) {
        // Formatear
        if (bottles > 2) {
            sprintf(song[line_index++], "%d bottles of beer on the wall, %d bottles of beer.", bottles, bottles);
            sprintf(song[line_index++], "Take one down and pass it around, %d bottles of beer on the wall.", bottles - 1);
        } else if (bottles == 2) {
            sprintf(song[line_index++], "2 bottles of beer on the wall, 2 bottles of beer.");
            sprintf(song[line_index++], "Take one down and pass it around, 1 bottle of beer on the wall.");
        } else if (bottles == 1) {
            sprintf(song[line_index++], "1 bottle of beer on the wall, 1 bottle of beer.");
            sprintf(song[line_index++], "Take it down and pass it around, no more bottles of beer on the wall.");
        } else { // bottles == 0
            sprintf(song[line_index++], "No more bottles of beer on the wall, no more bottles of beer.");
            sprintf(song[line_index++], "Go to the store and buy some more, 99 bottles of beer on the wall.");
            bottles = 100; // por si se sigue el patrón
        }

        // Se espera una línea vacía entre versos
        if (i < take_down - 1) {
            strcpy(song[line_index++], "");
        }
        bottles--;
    }
}
