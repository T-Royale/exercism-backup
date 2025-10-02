#include "flower_field.h"

size_t n_rows = 0;

char **annotate(const char **garden, const size_t rows){
    n_rows = rows;
    char **result;
    if(!garden) return NULL;
    const size_t len = strlen(garden[0]);
    result = calloc(rows, sizeof(char*));
    if(!result) return NULL;
    for(size_t i = 0; i < rows; i++){
        result[i] = calloc(len+1, sizeof(char));
        if(!result[i]){
            for(size_t j = 0;  j < i; j++){
                free(result[j]);
            }
            free(result);
            return NULL;
        }
    }

    for(size_t y = 0; y < rows; y++){
        for(size_t x = 0; x < len; x++){
            if(garden[y][x] == '*'){
                result[y][x] = '*';
            }
            else{
                int flowers = 0;
                if(check_square(garden, len, rows, x-1, y-1)) flowers++;
                if(check_square(garden, len, rows, x, y-1)) flowers++;
                if(check_square(garden, len, rows, x+1, y-1)) flowers++;
                if(check_square(garden, len, rows, x-1, y)) flowers++;
                if(check_square(garden, len, rows, x+1, y)) flowers++;
                if(check_square(garden, len, rows, x-1, y+1)) flowers++;
                if(check_square(garden, len, rows, x, y+1)) flowers++;
                if(check_square(garden, len, rows, x+1, y+1)) flowers++;
                if(flowers == 0){
                    result[y][x] = ' ';
                }
                else result[y][x] = flowers + '0';
            }
        }
        result[y][len] = '\0';
    }

    return result;
}

bool check_square(const char** garden, const size_t len, const size_t rows, int check_x, int check_y){
    if(check_x >= (int)len || check_x < 0) return false;
    if(check_y >= (int)rows || check_y < 0) return false;

    if(garden[check_y][check_x] == '*') return true;
    else return false;
}

void free_annotation(char **annotation){
    if(!annotation) return;
    if(n_rows == 1){
        free(annotation);
        return;
    }
    for(size_t i = 0; i < n_rows; i++){
        free(annotation[i]);
    }
    free(annotation);
}