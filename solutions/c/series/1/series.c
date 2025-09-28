#include "series.h"

slices_t slices(char *input_text, unsigned int substring_length){
    slices_t result;
    unsigned int len = strlen(input_text);
    result.substring_count = len - substring_length + 1;
    result.substring = malloc(result.substring_count * sizeof(char*));
    if (substring_length == 0 || substring_length > len) {
        result.substring_count = 0;
        result.substring = NULL;
        return result;
    }
    for(unsigned int i = 0; i < result.substring_count; i++){
        result.substring[i] = calloc(1, substring_length + 1);
        memcpy(result.substring[i], input_text + i, substring_length);
        result.substring[i][substring_length] = '\0';
    }
    return result;
}