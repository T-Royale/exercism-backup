#include "rational_numbers.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
rational_t add(rational_t a, rational_t b) {        //Suma de numeros racionales
    int numer = (a.numerator * b.denominator) + (b.numerator * a.denominator);  // Suma los numeradores
    int denom = a.denominator * b.denominator;               // Multiplica los denominadores
    rational_t result = { numer, denom };         // Crea el resultado
    if(a.denominator == b.denominator) {
        result.numerator = a.numerator + b.numerator;
        result.denominator = a.denominator;
    }
    return reduce(result);
}
rational_t subtract(rational_t a, rational_t b) {    //Lo mismo que la suma pero restando
    int numer = (a.numerator * b.denominator) - (b.numerator * a.denominator);  // Suma los numeradores
    int denom = a.denominator * b.denominator;               // Multiplica los denominadores
    rational_t result = { numer, denom };         // Crea el resultado
    return reduce(result);
    return reduce(a);
}
rational_t multiply(rational_t a, rational_t b) {        //Multiplicación de numeros racionales
    a.numerator *= b.numerator;                               //numeratorerador por numeratorerador
    a.denominator *= b.denominator;                               //Denominador por denominador 
    return reduce(a);                             //Reducir resultado
}
rational_t divide(rational_t a, rational_t b) {          //División de numeros racionales
    a.numerator *= b.denominator;                               //Multiplicación en cruz
    a.denominator *= b.numerator;                               //Otra vez en cruz
    //definimos el signo de la fracción racional
    if ((a.numerator < 0 && a.denominator > 0) || (a.numerator > 0 && a.denominator < 0)) {
        // Si el numerador y el denominador tienen signos opuestos, el racional es negativo
        a.numerator = -abs(a.numerator);
        a.denominator = abs(a.denominator);
    } else {
        // Si ambos tienen el mismo signo o son cero, el numero racional es positivo
        a.numerator = abs(a.numerator);
        a.denominator = abs(a.denominator);
    }
    return reduce(a);
}
rational_t absolute(rational_t a) {                      //Valor absoluto de un numero racional
    if(a.numerator < 0){                                 //Si el numerador es negativo lo hace positivo ( -1 * -1 = +1)
        a.numerator = -a.numerator;                     
    }
    if(a.denominator < 0) {                              //Y si el denominador es negativo también lo pasa a positivo
        a.denominator = -a.denominator;
    }
    return reduce(a);
}
rational_t exp_rational(rational_t a, float exponent) {           //Eleva numero racional a potencia entera
    
    int ogexp = (int)exponent;                //Guarda el exponente original como un entero que es el exponente
    if (exponent < 0) {    //Si el exponente es negativo
        //Cambia el numerador por el denominador
        int temp = a.numerator;
        a.numerator = a.denominator;
        a.denominator = temp;
        exponent = -exponent;
    }
    //Eleva numerador y denominador a dicho exponente
    a.numerator = pow(a.numerator, exponent);
    a.denominator = pow(a.denominator, exponent);
    // Si el exponente original era negativo y impar, invertimos el resultado
    if (ogexp < 0 && (ogexp % 2) != 0) {
        a.numerator = -a.numerator;
        a.denominator = -a.denominator;
    }
    //Devuelve el resultado
    return reduce(a);
} 
double exp_real(int a, rational_t b) {            //Eleva numero real a potencia racional
    
    double base = pow(a, 1.0 / b.denominator);    //Calcula la base que debe elevar al numerador
    double result = pow(base, b.numerator);       //La eleva al denominador
        // En terminos simples: A^(N/D) = (A^N)^(1/D). Esto se cumple porque "4^(3/6) = 6^√4^3"//
    return result;
}
rational_t reduce(rational_t rat) {          //Reduce numero racional a su forma mas simple
    if (rat.numerator == 0) {                //Si el numerador es 0, el denominador se puede dividir por si mismo
        rat.denominator = 1;                 //Y dar 1 como resultado
        return rat;                          //Entonces no hace falta hacer nada mas
    }

    if (rat.numerator == rat.denominator){    //Si numerador u denominador es el mismo
        rat.numerator = 1;                     //Pero si es positivo se podrá reducir como 1/1
        rat.denominator = 1;
        return rat;                            //Y la función puede terminar sin problema
    }
    //Algoritmo de Euclides//
    //Variables
    int a = rat.numerator;
    int b = rat.denominator;
    int resto;
    if(a==0) return rat;
    //Corregir numeros negativos(en mcd va a ser el mismo)
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    //Algoritmo en cuestión
    while(b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
                //Actualizar//
    //Si es negativo el denominador pero no el numerador
    if(rat.numerator > 0 && rat.denominator < 0) {
        //Cambiar el signo - del denominador al numerador
        rat.numerator = -rat.numerator;
        rat.denominator = -rat.denominator;
    }
    rat.numerator /= a;
    rat.denominator /= a;
    return rat;
}
