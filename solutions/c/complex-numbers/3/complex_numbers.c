#include "complex_numbers.h"
#include <math.h>

#define EULER exp(1)

complex_t c_add(complex_t a, complex_t b) {
    complex_t result = {a.real + b.real, a.imag + b.imag};
    return result;
}//(a + i * b) + (c + i * d) = (a + c) + (b + d) * i

complex_t c_sub(complex_t a, complex_t b) {
    complex_t result = {a.real - b.real, a.imag - b.imag};
    return result;
}//(a + i * b) - (c + i * d) = (a - c) + (b - d) * i

complex_t c_mul(complex_t a, complex_t b) {
    complex_t result = {a.real * b.real - a.imag * b.imag, 
        a.imag * b.real + a.real * b.imag};
    return result;
}// (a + bi) * (c + di) = (a * c - b * d) + (b * c + a * d) * i

complex_t c_div(complex_t a, complex_t b) {
    complex_t result = {(a.real * b.real + a.imag * b.imag) / (pow(b.real, 2) + pow(b.imag, 2)),
        (a.imag * b.real - a.real * b.imag) / (pow(b.real, 2) + pow(b.imag, 2))};
    return result;
}//(a + i * b) / (c + i * d)  = (a * c + b * d)/(c^2 + d^2) + (b * c - a * d)/(c^2 + d^2) * i

double c_abs(complex_t x) {
    double result = sqrt(pow(x.real, 2) + pow(x.imag, 2));
    return result;
} //|z| = sqrt(a^2 + b^2)

complex_t c_conjugate(complex_t x) {
    complex_t result = {x.real, -x.imag};
    return result;
}

double c_real(complex_t x) {
    return x.real;
}

double c_imag(complex_t x) {
    return x.imag;
}

complex_t c_exp(complex_t x) {
    double exp_real = pow(EULER, x.real);
    complex_t result = {exp_real * cos(x.imag), exp_real * sin(x.imag)};
    return result;
}//e^(a + i * b) = e^a * e^(i * b) -> e^(i * b) = cos(b) + i * sin(b)
