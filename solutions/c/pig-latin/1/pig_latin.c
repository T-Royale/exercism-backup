#include "pig_latin.h"

#define is_vowel(c) (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? true : false
#define is_consonant(c) !is_vowel(c)

int translate_word(char word[MAX_WORD_LEN]){
	size_t len = strlen(word);
	char result[MAX_WORD_LEN*2];
	char tmp[MAX_WORD_LEN+1];
	strcpy(tmp, word);
	if(len == 0 || len + 2 + 1 > MAX_WORD_LEN) return 1;

	// RULE: 1
	if(is_vowel(word[0]) || strncmp(word, "xr", 2) == 0 || strncmp(word, "yt", 2) == 0){
		if(strlen(tmp) + strlen("ay") + 1 > MAX_WORD_LEN) return 1;
		snprintf(result, MAX_WORD_LEN, "%say", tmp);
		printf("translated (1): %s\n", word);
	} else {
		char* pos = tmp; 	// pos to maintain rest of the str
		bool has_qu = false;
		bool has_y	= false;
		while(*pos && is_consonant(*pos)){
			if(strncmp(pos, "qu", 2) == 0){
				pos+=2;
				has_qu = true;
				break;
			} else if (*pos == 'y' && pos != tmp){
				pos++;
				has_y = true;
				break;
			} else {
				pos++;
			}
		}
		unsigned int prefix_len = pos - tmp; 
		if(has_qu){
			snprintf(result, MAX_WORD_LEN, "%s%.*squay", pos, prefix_len-2, tmp);
			printf("translated (3): %s\n", word);
		} else if(has_y){
			snprintf(result, MAX_WORD_LEN, "y%s%.*say", pos, prefix_len-1, tmp);
			printf("translated (4): %s\n", word);
		} else {
			snprintf(result, MAX_WORD_LEN, "%s%.*say", pos, prefix_len, tmp);
			printf("translated (2): %s\n", word);
		}
	}
	strncpy(word, result, MAX_WORD_LEN);
	return 0;
}

char *translate(const char *phrase){
	size_t len = strlen(phrase);
	char* result = calloc(len*2, sizeof(char));
	strcpy(result, phrase);

	char word[MAX_WORD_LEN] = {0};
	char *c = word;
	int pos = 0;
	for(size_t i = 0; i <= len; i++){
		if(!isspace(phrase[i]) && i != len){
			*c++ = phrase[i];
		} else {
			*c = 0;
			translate_word(word);
			int word_len = strlen(word);
			strncpy(&result[pos], word, word_len);
			result[pos+word_len] = 0;
			pos+=word_len;
			result[pos++] = ' ';
			memset(word, 0, MAX_WORD_LEN);
			c = word;
		}
	}
	result[pos-1] = 0;
	return result;
}