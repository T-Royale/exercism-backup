#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;
//                0                1            2

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);
bool diagonal(position_t queen_1, position_t queen_2);
bool horizontal(position_t queen_1, position_t queen_2);
#endif
