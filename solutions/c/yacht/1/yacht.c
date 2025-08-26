#include "yacht.h"
#include <stdbool.h>
#define dice_count 5
#define MAX_DICE_SCORE 6

int score(dice_t dice, category_t category){
    int points = 0;
    int result[MAX_DICE_SCORE] = {0};        // result[2] accede al número de unos
    bool straight[MAX_DICE_SCORE] = {false}; // Apariencias de cada número en big y small straight
    for(int i = 0; i < dice_count; i++){
        if(dice.faces[i] < 0 || dice.faces[i] > MAX_DICE_SCORE) return 0;
        result[dice.faces[i] - 1]++;
    }
    switch(category){
        case FULL_HOUSE:        // 2 de un número y 3 de otro (total del dado)
            for(int i = 0; i < MAX_DICE_SCORE; i++){
                if(result[i] == 3){
                    for(int j = 0; j < MAX_DICE_SCORE; j++){
                        if(result[j] == 2){
                            for(int i = 0; i < dice_count; i++) points += dice.faces[i];
                        }
                    }
                }
            }
            break;
        case FOUR_OF_A_KIND:    // 4 de un mismo número (suma de los 4 dados)
            for(int i = 0;  i < MAX_DICE_SCORE; i++){
                if(result[i] >= 4) points = 4*(i+1);
            }
            break;
        case LITTLE_STRAIGHT:   // 	1-2-3-4-5 (30p)
            // Ver que números aparecen
            for(int i = 0; i < dice_count; i++){
                straight[dice.faces[i] - 1] = true;
            }
            // Chequear si son los validos
            for(int i = 0; i < 5; i++){
                if(!straight[i]) return 0;
            }
            points = 30;
            break;
        case BIG_STRAIGHT:      // 2-3-4-5-6 (30p)
            // Ver que números aparecen
            for(int i = 0; i < dice_count; i++){
                straight[dice.faces[i] - 1] = true;
            }
            // Chequear si son los validos
            for(int i = 1; i < 6; i++){
                if(!straight[i]) return 0;
            }
            points = 30;
            break;
        case CHOICE:            // Suma de los números
            for(int i = 0; i < dice_count; i++){
                points += dice.faces[i];
            }
            break;
        case YACHT:             // Todos los dados muestran el mismo número (50p)
            for(int i = 0; i < MAX_DICE_SCORE; i++){
                if (result[i] == dice_count){
                    points = 50;
                    break;
                }
            }
            break;
        default:                // 1, 2, 3, 4, 5, MAX_DICE_SCORE
            for(int i = 0; i < dice_count; i++){
                if(dice.faces[i] == (int)category){
                    points += category;
                }
            }
            break;
    }
    return points;
}