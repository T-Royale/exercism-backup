#include "grains.h"
uint64_t square(uint8_t index) {
    if(index == 0 || index > 64){
        return 0;         //No es valido
    }
    uint64_t granos = 1;
    for(int i = 1; i < index; i++){
    granos = granos*2;
    }
    return granos;
}
uint64_t total(void) {
    uint64_t granos = 1;
    uint64_t totalGranos = 0;
    for(int i = 1; i < 64; i++){
        granos = granos*2;
        totalGranos += granos;
    }
    return totalGranos+1;
}