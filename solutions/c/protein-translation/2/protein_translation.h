#ifndef PROTEIN_TRANSLATION_H
#define PROTEIN_TRANSLATION_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_AMINO_ACIDS 10

typedef enum {
   Methionine,    // AUG
   Phenylalanine, // UUU, UUC
   Leucine,       // UUA, UUG
   Serine,        // UCU, UCC, UCA, UCG
   Tyrosine,      // UAU, UAC
   Cysteine,      // UGU, UGC
   Tryptophan,    // UGG
   Stop,
} amino_acid_t;

typedef struct {
   bool valid;
   size_t count;
   amino_acid_t amino_acids[MAX_AMINO_ACIDS];
} protein_t;

protein_t protein(const char *const rna);

#endif
