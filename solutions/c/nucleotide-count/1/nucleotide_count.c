#include "nucleotide_count.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *count(const char *dna_strand){
    int adenine = 0, cytosine = 0, guanine = 0, thymine = 0;
    int len = strlen(dna_strand);
    for(int i = 0; i < len; i++){
        char nucleotide = dna_strand[i];
        switch(nucleotide){
            case 'A':
                adenine++;
                break;
            case 'C':
                cytosine++;
                break;
            case 'G':
                guanine++;
                break;
            case 'T':
                thymine++;
                break;
            default:{
                char* error = malloc(sizeof(char));
                error[0] = '\0';
                return error;
            }
        }
    }
    char* result = malloc(strlen("A:00 C:00 G:00 T:00")*sizeof(char));
    sprintf(result, "A:%d C:%d G:%d T:%d", adenine, cytosine, guanine, thymine);
    return result;
}