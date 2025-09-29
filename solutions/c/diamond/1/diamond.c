#include "diamond.h"

char **make_diamond(const char letter){
    int size = (letter - 'A' + 1) * 2 - 1;
    if(size == 0) return NULL;
    char** result;
    // Allocate result
    result = malloc(size * sizeof(char*));
    if(!result) return NULL;
    for(int i = 0; i < size; i++){
        result[i] = malloc(size * sizeof(char)+1);
        if(!result[i]) return NULL;
    }
    // Fill with spaces
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            result[i][j] = ' ';
        }
        result[i][size] = '\0';
    }
    char c = 'A';
    int middle = size/2;
    for(int i = 0; i <= middle; i++){
        result[i][middle-i] = c;
        result[i][middle+i] = c;
        result[size -1 -i][middle-i] = c;
        result[size -1 -i][middle+i] = c;
        c++;
    }

    return result;
}

void free_diamond(char **diamond){
    if(!diamond) return;
    int size = strlen(diamond[0]);
    for(int i = 0; i < size; i++){
        free(diamond[i]);
    }
    free(diamond);
}