#include "nth_prime.h"
//devuelve el número primo número n
uint32_t nth(uint32_t n){
    if(n < 1) return 0;
    uint32_t nPrimos = 0;
    uint32_t numero = 1;
    while(nPrimos != n){
        numero++;
        if(EsPrimo(numero)) nPrimos++;
    }
    return numero;
}

bool EsPrimo(uint32_t Primo){
    if(Primo < 2) return false;
    uint32_t limite = (uint32_t)sqrt((double)Primo);
    for(uint32_t i = 2; i <= limite; i++){
        if(Primo % i == 0) return false;
    } 
    return true;
}