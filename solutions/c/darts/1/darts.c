#include "darts.h"
#include <math.h>
//Calculate the absolute value of the coordinate so we get it in the first quadrant(cartesian coordinates)
coordinate_t absolute(coordinate_t coordinate){
    coordinate.x = (coordinate.x < 0) ? -coordinate.x : coordinate.x;
    coordinate.y = (coordinate.y < 0) ? -coordinate.y : coordinate.y;
    return coordinate;
}
//Use the pythagorean theorem to calculate the distance of the point to the origin (hypotenuse)
double pythagorean(coordinate_t coordinate){
    double result;
    double x = pow(coordinate.x, 2);
    double y = pow(coordinate.y, 2);
    result = x + y;
    return sqrt(result);
}
//Main function that takes the score
uint8_t score(coordinate_t land_pos){
    coordinate_t land_pos_abs = absolute(land_pos);
    double radius = pythagorean(land_pos_abs);
    if(radius <= 1.00) return 10;
    else if(radius <= 5.00) return 5;
    else if(radius <= 10.00) return 1;
    else return 0;
}