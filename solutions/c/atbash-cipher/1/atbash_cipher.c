#include "atbash_cipher.h"

char translate[26];

char *atbash_encode(const char *input){
    int len = strlen(input);
    char *result = calloc(len+1 + (len/4), sizeof(char));
    int j = 0;
    for(char c = 'z'; c >= 'a'; c--) translate[j++] = c;
    j = 0;
    int count = 0;
    for(int i = 0; i < len; i++){
        char c = tolower(input[i]);
        if(!isalnum(c)) continue;
        if(count % 5 == 0 && count != 0){
            result[j++] = ' ';
        }
        if(isdigit(c)) {
            result[j++] = c;
        } else{
            result[j++] = translate[c-'a'];
        }
        count++;
    }
    return result;
}
char *atbash_decode(const char *input){
    int len = strlen(input);
    char *result = calloc(len, sizeof(char));
    int j = 0;
    for(char c = 'z'; c >= 'a'; c--) translate[j++] = c;
    j = 0;
    for(int i = 0; i < len; i++){
        if(isdigit(input[i])){
            result[j++] = input[i];
            continue;
        }
        char c = tolower(input[i]);
        if(!isalpha(c)) continue;
        else result[j++] = translate[c - 'a'];
    }
    return result;
}