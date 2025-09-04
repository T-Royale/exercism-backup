#include "collatz_conjecture.h"
int steps (int start){
    int count = 0;
    if(start <= 0) return ERROR_VALUE;
    for(int n=start; n!=1; count++){
        if(n==1) return count;
        if(n % 2 == 0){    //Is even
            n /= 2;        //x/2
        }
        else n = 3*n+1;     //3x+1
    }
    return count;
}