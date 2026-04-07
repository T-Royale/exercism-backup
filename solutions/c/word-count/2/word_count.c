#include "word_count.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int register_word(const char* word, int len, word_count_word_t* words, int* word_count){
	char* word_ci = calloc(len+1, sizeof(char));	// case-insensitive
	if(!word_ci) return -1;
	for(int i = 0; i < len; i++){
		word_ci[i] = tolower(word[i]);
	}
	for(int i = 0; i < *word_count; i++){
		if(strcmp(word_ci, words[i].text) == 0){
			words[i].count++;
			printf("registrada %.*s - existia\n", len, word);
			return 0;
		}
	}
	strcpy(words[*word_count].text, word_ci);
	words[*word_count].count = 1;
	(*word_count)++;
	printf("registrada %.*s - no existia\n", len, word);
	free(word_ci);
	return 0;
}

int count_words(const char *sentence, word_count_word_t *words){
	int word_count = 0;
	const char* current_word = sentence;
	int current_word_len = 0;
	int len = strlen(sentence);
	for(int i = 0; i < len; i++){
		if(isalnum(sentence[i])){
			if(current_word_len == 0)
				current_word = &sentence[i];
			current_word_len++;
		} else if( sentence[i] == '\'' && current_word_len > 0 && i + 1 < len && isalnum(sentence[i - 1]) && isalnum(sentence[i + 1])) {
            current_word_len++;
		} else if(isspace(sentence[i]) || sentence[i] == '?' || sentence[i] == '!' || sentence[i] == ':' || sentence[i] == ','){
			if(current_word_len > 0){
				printf("to register %.*s\n", current_word_len, current_word);
				register_word(current_word, current_word_len, words, &word_count);
				current_word_len = 0;
			}
		}
	}
	if(current_word_len > 0)
		register_word(current_word, current_word_len, words, &word_count);
	return word_count;
}