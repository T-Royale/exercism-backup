#include "etl.h"

int convert(const legacy_map *input, const size_t input_len, new_map **output){
    if(!input) return -1;
    *output = malloc(size * sizeof(new_map));
    if(!*output) return -1;
    int map[size];
    for(int i = 0; i < size; i++) map[i] = -1;
    size_t count = 0;
    for(size_t i = 0; i < input_len; i++){
        int len = strlen(input[i].keys);
        for(int j = 0; j < len; j++){
            map[(tolower(input[i].keys[j]) - 'a')] = input[i].value;
        }
    }
    for(size_t i = 0; i < size; i++){
        if(map[i] != -1){
            (*output)[count].key = i + 'a';
            (*output)[count++].value = map[i];
        }
    }
    return count;
}