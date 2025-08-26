#include "triangle.h"
#include <stdbool.h>

bool is_a_triangle(triangle_t sides){
    if (!(sides.a + sides.b >= sides.c)) return false;
    if (!(sides.b + sides.c >= sides.a)) return false;
    if (!(sides.a + sides.c >= sides.b)) return false;
    if (sides.a == 0 || sides.b == 0 || sides.c == 0) return false;
    return true;
}
bool is_equilateral(triangle_t sides){
    if (is_a_triangle(sides)){
        if(sides.a == sides.b && sides.b == sides.c) return true;
    }
    return false;
}
bool is_isosceles(triangle_t sides){
    if (is_a_triangle(sides)){
        if(sides.a == sides.b || sides.a == sides.c || sides.b == sides.c) return true;
    }
    return false;
}
bool is_scalene(triangle_t sides){
    if (is_a_triangle(sides)){
        if(!is_equilateral(sides) && !is_isosceles(sides)) return true;
    }
    return false;
}
