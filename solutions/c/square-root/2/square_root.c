#include "square_root.h"
#include <math.h>
int square_root(int A) {
    int result = 0;
    while(pow(result, 2) != A)result++;
    return result;
}