#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
    uint64_t number = n;
    uint64_t factor = 2;
    size_t nFactores = 0;
    while(number > 1){
        if(number%factor != 0){
            factor++;
        }
        else{
            factors[nFactores++] = factor;
            number/=factor;
        }
    }
    return nFactores;
}