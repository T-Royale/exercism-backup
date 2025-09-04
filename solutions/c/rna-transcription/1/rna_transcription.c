#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>
char *to_rna(const char *dna){
    int size = strlen(dna);
    char *rna = malloc(size + 1);
    for(int i = 0; i < size; i++){
        rna[i] = dna[i];
    }
    for(int i = 0; i < size; i++){
        switch(rna[i]){
            case 'G':
                rna[i] = 'C';
                break;
            case 'C':
                rna[i] = 'G';
                break;
            case 'A':
                rna[i] = 'U';
                break;
            case 'T':
                rna[i] = 'A';
                break;
            default:
                break;
        }
    }
    rna[size] = '\0';
    return rna;
}