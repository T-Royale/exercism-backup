#include "grade_school.h"
//roster_t {size_t count; student_t students[MAX_STUDENTS]}

//función que ordenará los estudiantes por curso y por nombre

void ordenar(roster_t *actual) {
    char buffer[MAX_NAME_LENGTH];
    for(size_t i = 0; i < actual->count; i++) {
        for(size_t j = i + 1; j < actual->count; j++) {
            // Si el curso de un estudiante es mayor al que va delante suyo (está mal ordenado)
            if(actual->students[i].grade > actual->students[j].grade || (actual->students[i].grade == actual->students[j].grade && actual->students[i].name[0] > actual->students[j].name[0])) {
                // Intercambiar nombres
                strcpy(buffer, actual->students[i].name);
                strcpy(actual->students[i].name, actual->students[j].name);
                strcpy(actual->students[j].name, buffer);
                // Intercambiar cursos
                uint8_t temp_grade = actual->students[i].grade;
                actual->students[i].grade = actual->students[j].grade;
                actual->students[j].grade = temp_grade;
            }
        }
    }
}
void init_roster(roster_t *actual){ //prepara el roster_t para su uso
    actual->count = 0;
}
bool add_student(roster_t *actual, char name[], uint8_t grade){//Añade un estudiante, si se añade con exito devuelve true
    if (actual->count >= MAX_STUDENTS) {
            return false; // No hay espacio disponible en la lista
        } 
    for (size_t i = 0; i < actual->count; i++) {
        if (strcmp(name, actual->students[i].name) == 0) {
            return false; // El nombre ya existe en la lista
        }
    }
    strcpy(actual->students[actual->count].name, name);       //Asigna el nombre a la lista si no se repite
    actual->students[actual->count].grade = grade;            //Le asigna a ese estudiante el curso al que va
    actual->count++;
    ordenar(actual);
    return true;
}
roster_t get_grade(roster_t *actual, uint8_t wanted_grade){    //Debería devolver un roster_t con los estudiantes de un curso
    roster_t wanted;        
    init_roster(&wanted);        //crea e inicializa una variable roster_t
    for(size_t i=0; i<actual->count;i++){
        if(actual->students[i].grade == wanted_grade){
            add_student(&wanted, actual->students[i].name, actual->students[i].grade);
        }
    }
    return wanted;
}