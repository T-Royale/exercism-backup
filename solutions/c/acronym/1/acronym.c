#include "acronym.h"

char *abbreviate(const char *phrase){
    if(!phrase) return NULL;
    int len = strlen(phrase);
    if(len == 0){
        return NULL;
    }
    char *result = calloc(1, len);
    int pos = 1;
    bool valid = false;
    result[0] = phrase[0];
    for(int i = 1; i < len; i++){
        if(valid && isalpha(phrase[i])){
            result[pos++] = toupper(phrase[i]);
            valid = false;
        } else {
            switch(phrase[i]){
                case ' ':
                    valid = true;
                    break;
                case '-':
                    valid = true; 
                    break;
                case '_':
                    valid = true; 
                    break;
                default:
                    valid = false;
                    break;
            }
        }
    }
    return result;
}