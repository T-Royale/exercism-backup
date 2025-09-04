#include "binary_search.h"
//Función que devolverá un puntero a la dirección donde está el número deseado en la lista
const int *binary_search(int value, const int *arr, size_t length){
    if(length <= 0){               //Si la longitud no es valida
        return false;
    }
    int mitad;                     //Mitad de la cadena que hemos cogido(si es ese numero termina el while)
    int MaxN = length;             //Maximo numero sin descartar en arr
    int MinN = 0;                  //Minimo numero sin descartar en arr
    int pos = -1;                   //Posición del numero en la lista
    while (MinN <= MaxN) {  // Mientras el rango de búsqueda sea válido
        mitad = MinN + (MaxN - MinN) / 2;  // Calcular la mitad
        
        if (arr[mitad] == value) {  // Si el valor está en la posición de la mitad
            pos = mitad;            // Guardar la posición
            break;                  // Salir del bucle
        } else if (arr[mitad] < value) {
            MinN = mitad + 1;       // Actualizar el índice mínimo para buscar en la mitad superior
        } else {
            MaxN = mitad - 1;       // Actualizar el índice máximo para buscar en la mitad inferior
        }
    }
    //Devuelve la dirección del numero en la lista
    if (pos == -1){
        return false;
    }
    return &arr[pos];
}