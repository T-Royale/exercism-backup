#include "secret_handshake.h"

char *actions[] = {
    "wink",
    "double blink",
    "close your eyes",
    "jump"
};

const char **commands(size_t number){
    char **result;
    result = calloc(4, sizeof(char*));
    if(!result) return NULL;
    
    int count = 0;
    for(int i = 0; i < 4; i++){
        if((number >> i) & 1){
            result[count] = malloc(MAX_COMMAND_LEN);
            if(!result[count]){
                for (int j = 0; j < count; j++) free(result[j]);
                free(result);
                return NULL;
            }
            strncpy(result[count], actions[i], MAX_COMMAND_LEN);
            count++;
        }
    }
    // Reverse order
    if((number >> 4) & 1){
        for(int i = 0; i < count/2; i++){
            char *tmp = result[i];
            result[i] = result[count - i - 1];
            result[count - i - 1] = tmp;
        }
    }
    
    return (const char**) result;
}