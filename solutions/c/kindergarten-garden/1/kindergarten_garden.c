#include "kindergarten_garden.h"
#include <stdio.h>
#include <string.h>

#define cups_per_child 4        //How many cups has each kid
#define row_count 2             //Number of rows at each window
#define MAX_STUDENTS 12         //Max number of students
#define MAX_CUPS_PER_ROW 24     //Each student has four cups, two per row
#define ERROR (plants_t){{0}}   //Result to return if error (debugging purposes)


// Nombres de los estudiantes.
char *names[] = {
    "Alice", "Bob", "Charlie", "David", "Eve", 
    "Fred", "Ginny", "Harriet", "Ileana", "Joseph", 
    "Kincaid", "Larry"
};

plants_t plants(const char* diagram, const char* student){
    int diagram_len = strlen(diagram) - (row_count-1);          //Diagram length removing every'\n'
    if(diagram_len > MAX_CUPS_PER_ROW * row_count) return ERROR;

    int number_of_children = diagram_len/cups_per_child;        //Number of children in the class
    if(number_of_children > MAX_STUDENTS) return ERROR;
    
    char rows[row_count][(diagram_len/row_count)+1];            //Values of each row as a string
    char cup[cups_per_child];                                   //Array with the content of each cup       
    if (sscanf(diagram, "%s\n%s", rows[0], rows[1]) != 2) {     //Valid when row_count = 2
        return ERROR;
    }

    //Calculate he position of the student's first cup on each row
    int student_cup_pos;
    for(student_cup_pos = 0; student_cup_pos < MAX_STUDENTS; student_cup_pos++){
        if(strcmp(names[student_cup_pos], student) == 0){
            break;
        }
    }   //Now it contains the student's alphabetical position
    student_cup_pos *= 2;

    //Prepare array with the plants
    int current_cup = 0;
    for(int i = 0; i < row_count; i++){
        for(int j = 0; j < cups_per_child/row_count; j++){
            cup[current_cup] = rows[i][student_cup_pos + j];
            current_cup++;
        }
    }
    //Generate result
    plants_t result;
    for(int i = 0; i < cups_per_child; i++){
        switch(cup[i]){
            case 'G':   //GRASS
                result.plants[i] = GRASS;
                break;
            case 'C':   //CLOVER
                result.plants[i] = CLOVER;
                break;
            case 'R':   //RADISH
                result.plants[i] = RADISHES;
                break;
            case 'V':   //VIOLET
                result.plants[i] = VIOLETS;
                break;
            default:
                //The code shouldn't get here
                return ERROR;
                break;
            
        }
    }
    return result;
}