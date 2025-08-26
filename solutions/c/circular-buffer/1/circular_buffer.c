#include "circular_buffer.h"

#define vacio -99

//Crea un buffer circular
circular_buffer_t *new_circular_buffer(size_t size){
    // Asignar memoria para el buffer
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
    if(buffer == NULL){
        fprintf(stderr, "Error de asignación de memoria");
        exit(1);
    }
    // Asignar memoria para la cadena
    buffer->content = malloc(sizeof(buffer_value_t) * size);
    if(buffer->content == NULL){
        fprintf(stderr, "Error de asignación de memoria");
        exit(1);
    }
    buffer->size = size;
    buffer->write = 0;
    buffer->read = 0;
    clear_buffer(buffer);
    return buffer;
}
// Resetear el buffer
void clear_buffer(circular_buffer_t *buffer){
    for(int16_t i = 0; i < buffer->size; i++){
        buffer->content[i] = vacio;
    }
    buffer->write = 0;
    buffer->read = 0;
    buffer->oldest = 0;
    buffer->full = false;
}

// Lee los valores del buffer circular y los coloca en values
int16_t read(circular_buffer_t *buffer, buffer_value_t *value){
    if(buffer->content[buffer->read] == vacio){
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    *value = buffer->content[buffer->read];
    buffer->content[buffer->read] = vacio;
    buffer->read = (buffer->read + 1) % buffer->size;
    // Avanzar oldest al siguiente elemento
    buffer->oldest = (buffer->oldest + 1) % buffer->size;
    buffer->full = false;
    return EXIT_SUCCESS;
}

// Escribe el valor value en el buffer
// Si no hay espacios disponibles devuelve EXIT_FAILURE y establece errno a ENOBUFS
int16_t write(circular_buffer_t *buffer, buffer_value_t value){
    if(buffer->full){
        buffer->full = true;
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }
    buffer->content[buffer->write] = value;
    buffer->write = (buffer->write + 1) % buffer->size;
    if(buffer->write == buffer->read){
        buffer->full = true;
    }
    return EXIT_SUCCESS;
}


// Introduce value en el buffer, si no quedan espacios, sobreescribe el más antiguo
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value){
    if (write(buffer, value) == EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    }

    buffer->content[buffer->oldest] = value;

    if (buffer->read == buffer->oldest) {
        buffer->read = (buffer->read + 1) % buffer->size;
    }

    buffer->oldest = (buffer->oldest + 1) % buffer->size;
    buffer->write = buffer->oldest;

    return EXIT_SUCCESS;
}

void delete_buffer(circular_buffer_t *buffer){
    free(buffer->content);
    free(buffer);
}