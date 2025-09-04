#ifndef ALLERGIES_H
#define ALLERGIES_H

#include <stdbool.h>

typedef enum {                        //Define un tipo de enumeración que guardará todos los alergenos posibles//
   ALLERGEN_EGGS = 0,
   ALLERGEN_PEANUTS,
   ALLERGEN_SHELLFISH,
   ALLERGEN_STRAWBERRIES,
   ALLERGEN_TOMATOES,
   ALLERGEN_CHOCOLATE,
   ALLERGEN_POLLEN,
   ALLERGEN_CATS,
   ALLERGEN_COUNT,                  //Numero de alergenos(8)//
} allergen_t;

typedef struct {
   int count;                      //Entero que devuelve la cantidad de cosas a las cuales es alergico//
   bool allergens[ALLERGEN_COUNT];         //Array booleana que dirá a qué es alergico Tom//
} allergen_list_t;
//Codigo que creo yo:
allergen_list_t get_allergens(const int score);
bool is_allergic_to (allergen_t ALLERGEN, int score);
//Codigo creado por mí//
#endif