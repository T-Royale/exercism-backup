#ifndef YACHT_H
#define YACHT_H

typedef enum {
   ONES = 1,   //Para que tenga el valor de los puntos que da
   TWOS,
   THREES,
   FOURS,
   FIVES,
   SIXES,
   FULL_HOUSE,
   FOUR_OF_A_KIND,
   LITTLE_STRAIGHT,
   BIG_STRAIGHT,
   CHOICE,
   YACHT
} category_t;

typedef struct {
   int faces[5];
} dice_t;

int score(dice_t dice, category_t category);

#endif