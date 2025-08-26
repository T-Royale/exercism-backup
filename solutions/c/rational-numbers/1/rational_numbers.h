#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H
//Estructura de numero racional:
typedef struct{           // Estructura del numero racional [x, y] = x/y
    int numerator;      //Numerador del numero racional (x)
    int denominator;       //Denominador del numero racional (y)
} rational_t;
//Funciones que van a ser probadas:
rational_t add(rational_t a, rational_t b);
rational_t subtract(rational_t a, rational_t b);
rational_t multiply(rational_t a, rational_t b);
rational_t divide(rational_t a, rational_t b);
rational_t absolute(rational_t a);
rational_t exp_rational(rational_t a, float exponent);
double exp_real(int a, rational_t b);
//Funciones extras:
int mcm(int a, int b);
rational_t reduce(rational_t rat);
#endif