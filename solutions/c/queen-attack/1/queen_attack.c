#include "queen_attack.h"
#include <math.h>
//Verify position of the queens
#define VALID_ROW(row) ((row) >= 0 && (row) < 8)
#define VALID_COLUMN(column) ((column) > 0 && (column) < 8)
#define VALID_POSITION(queen) (VALID_ROW((queen).row) && VALID_COLUMN((queen).column))
//They can attack eachother moving diagonal
bool diagonal(position_t queen_1, position_t queen_2){
    return (abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column)) ? true : false;
}
//They can attack eachother moving horizontal
bool horizontal(position_t queen_1, position_t queen_2){
    return (queen_1.row == queen_2.row || queen_1.column == queen_2.column) ? true : false;
}
attack_status_t can_attack(position_t queen_1, position_t queen_2){
    if (!VALID_POSITION(queen_1) || !VALID_POSITION(queen_2)) return 2; //Invalid position
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) return 2; //Same position
    return (diagonal(queen_1, queen_2) || horizontal(queen_1, queen_2)) ? 1 : 0;    //Valid position (can/'t attack eachother)
}