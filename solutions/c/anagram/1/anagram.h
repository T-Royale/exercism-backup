#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STR_LEN 20

enum anagram_status { UNCHECKED = -1, NOT_ANAGRAM, IS_ANAGRAM };

struct candidate {
   enum anagram_status is_anagram;
   const char *word;
};

struct candidates {
   struct candidate *candidate;
   size_t count;
};

/**
 * @description - determines if any of the words in candidate are anagrams
 *                for subject. Contents of candidate structures may be modified.
 */
void find_anagrams(const char *subject, struct candidates *candidates);

int get_ch(const char* word, int* ch);

bool check_ch(int* ch_1, int* ch_2);

bool anagram_of_itself(const char* word_1, const char* word_2);

#endif
