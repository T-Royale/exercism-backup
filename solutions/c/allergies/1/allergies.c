#include "allergies.h"
int Resto;               //Variable importante que modificaremos para no afectar a Score

allergen_list_t get_allergens(int score) {
    allergen_list_t list;
    Resto = score;
    list.count = 0;
    for(int i =0 ; i<ALLERGEN_COUNT; i++){
        list.allergens[i] = false;
    }
    if(Resto == 0){
        return list;
    }
    while(Resto > 0){
    for(int i = 128, t = ALLERGEN_COUNT-1; i > 0 && t>=0; i=i/2, t--){
        if(Resto >= i) {
            Resto -= i;
            list.allergens[t] = true;
            list.count++;
        }
        else {
            list.allergens[t] = false;
            continue;
        }
    }
    if(Resto!=0){
        list.count = 0;
        for(int i =0 ; i<ALLERGEN_COUNT; i++){
            list.allergens[i] = false;
            Resto = score-256;
        }
    }
    }
    return list;
}
bool is_allergic_to (allergen_t ALLERGEN, int score) {
    allergen_list_t list = get_allergens(score);
    return list.allergens[ALLERGEN];
}
