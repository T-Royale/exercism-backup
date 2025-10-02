#include "run_length_encoding.h"

char *encode(const char *text){
    char* result = calloc(MAX_LEN, sizeof(char));
    int len = strlen(text);
    if(len <= 0) return result;
    int pos = 0;
    char current = text[0];
    int n = 1;
    for(int i = 1; i <= len; i++){
        if(text[i] != current || text[i] == '\0'){
            if(n > 1) {
                char buff[12];
                snprintf(buff, sizeof(buff), "%d", n);
                for(size_t j = 0; j < strlen(buff); j++){
                    result[pos++] = buff[j];
                }
            }
            result[pos++] = current;
            current = text[i];
            n = 1;
        } else n++;
    }
    return result;
}
char *decode(const char *data){
    char* result = calloc(MAX_LEN, sizeof(char));
    int pos = 0;
    int len = strlen(data);
    char buff[12];
    int buff_pos = 0;
    for(int i = 0; i < len; i++){
        if(isdigit(data[i])){
            buff[buff_pos++] = data[i];   
        } else {
            int n = 1;
            if(buff_pos){
                buff[buff_pos] = '\0';
                n = atoi(buff);
            }
            for(int j = 0; j < n; j++){
                result[pos++] = data[i];
            }
            buff_pos = 0;
        }
    }

    return result;
}