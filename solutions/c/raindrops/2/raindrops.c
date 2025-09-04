#include "raindrops.h"
#include <stdio.h>
#include <string.h>
//Los resultados tienen que estar escritos en result
void convert(char result[], int drops){
    if(drops % 3 == 0){
        strcat(result, "Pling");
    }
    if(drops % 5 == 0){
        strcat(result, "Plang");
    }
    if(drops % 7 == 0){
        strcat(result, "Plong");
    }
    else if(drops % 3 != 0 && drops % 5 != 0){
        sprintf(result, "%d", drops);
    }
}