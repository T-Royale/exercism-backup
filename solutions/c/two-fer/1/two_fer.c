#include "two_fer.h"
#include <string.h>
#define BUFFER_SIZE 100
//me pasa el puntero como char para que pueda editar el buffer, ahí tengo que poner el texto
void two_fer(char *buffer, const char *name){
    char nombre[5] = {'y', 'o', 'u', '\0'};
    strcpy(buffer, "One for ");
    if(name == NULL) strncat(buffer, nombre, BUFFER_SIZE);
    else strncat(buffer, name, BUFFER_SIZE);
    strncat(buffer, ", one for me.", BUFFER_SIZE);    
}