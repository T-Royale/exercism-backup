#include "protein_translation.h"
#include <string.h>

proteins_t proteins(const char *const rna){
    proteins_t result;
    result.count = 0;
    result.valid = true;
    int len = strlen(rna);
    if(len == 0) return result;
    int nCodons = len/3;
    if(nCodons <= 0){
        result.valid = false;
        return result;
    }
    for(int i = 0; i < nCodons; i++){
        char codon[4];
        codon[0] = rna[(i*3)];
        codon[1] = rna[(i*3)+1];
        codon[2] = rna[(i*3)+2];
        codon[3] = '\0';
        if(strcmp(codon, "AUG") == 0){
            result.proteins[i] = Methionine;
        }else if(strcmp(codon, "UUU") == 0 || strcmp(codon, "UUC") == 0){
            result.proteins[i] = Phenylalanine;
        }else if(strcmp(codon, "UUA") == 0 || strcmp(codon, "UUG") == 0){
            result.proteins[i] = Leucine;
        }else if(strcmp(codon, "UCU") == 0 || strcmp(codon, "UCC") == 0 || strcmp(codon, "UCA") == 0 || strcmp(codon, "UCG") == 0){
            result.proteins[i] = Serine;
        }else if(strcmp(codon, "UAU") == 0 || strcmp(codon, "UAC") == 0){
            result.proteins[i] = Tyrosine;
        }else if(strcmp(codon, "UGU") == 0 || strcmp(codon, "UGC") == 0){
            result.proteins[i] = Cysteine;
        }else if(strcmp(codon, "UGG") == 0){
            result.proteins[i] = Tryptophan;
        }else if(strcmp(codon, "UAA") == 0 || strcmp(codon, "UAG") == 0 || strcmp(codon, "UGA") == 0){
            return result;
        }
        else result.valid = false;
        result.count++;
    }
    if(rna[nCodons*3] != '\0') result.valid = false;
    return result;
}

/*
ERRORES:
    NO HAY ERRORES
*/