#include "dnd_character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int modifier(int score){
    int points = score;
    if(score-10 < 0 && score % 2 == 1) points -= 1;
    return (points - 10)/2;
}
int ability(void){
    int random = rand();
    while(random > 17) {random /= 3;}
    if(random < 3) random += 4;
    return random;
}
dnd_character_t make_dnd_character(void){
    srand(time(NULL));
    dnd_character_t Juan;
    Juan.strength = ability();
    Juan.dexterity = ability();
    Juan.constitution = ability();
    Juan.intelligence = ability();
    Juan.wisdom = ability();
    Juan.charisma = ability();
    Juan.hitpoints = 10 + modifier(Juan.constitution);
    return Juan;
}