#include "hamming.h"
#include <string.h>
int compute(const char *lhs, const char *rhs){
    int len = strlen(lhs);
    int len2 = strlen(rhs);
    int Hamming_distance=0;
    if(len!=len2) {
        return -1;
    }
    for (int i=0; i<len; i++){
        if(lhs[i] != rhs[i]){
            Hamming_distance++;
        }
    }
    return Hamming_distance;
}