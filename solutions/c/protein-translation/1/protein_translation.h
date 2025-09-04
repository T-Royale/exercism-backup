#ifndef PROTEIN_TRANSLATION_H
#define PROTEIN_TRANSLATION_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_PROTEINS 10

typedef enum {
   Methionine,    // AUG
   Phenylalanine, // UUU, UUC
   Leucine,       // UUA, UUG
   Serine,        // UCU, UCC, UCA, UCG
   Tyrosine,      // UAU, UAC
   Cysteine,      // UGU, UGC
   Tryptophan,    // UGG
} protein_t;// STOP: UAA, UAG, UGA

typedef struct {
   bool valid;
   size_t count;
   protein_t proteins[MAX_PROTEINS];
} proteins_t;

proteins_t proteins(const char *const rna);

#endif
