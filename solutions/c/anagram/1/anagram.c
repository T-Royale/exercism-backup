#include "anagram.h"

void find_anagrams(const char *subject, struct candidates *candidates){
    int subject_ch['z' - 'a'+1] = {0};
    get_ch(subject, subject_ch);
    for(size_t i = 0; i < candidates->count; i++){
        candidates->candidate[i].is_anagram = IS_ANAGRAM;
        if(anagram_of_itself(subject, candidates->candidate[i].word)){
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        }
        int candidate_ch['z'-'a'+1] = {0};
        get_ch(candidates->candidate[i].word, candidate_ch);
        if(!check_ch(subject_ch, candidate_ch)){
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        }
    }
}

int get_ch(const char* word, int* ch){
    int len = strlen(word);
    if(len <= 0) return -1;
    for(int i = 0; i < len; i++){
        if(!isalpha(word[i]))
            return -1;
        char c = tolower(word[i]);
        ch[c - 'a']++;
    }
    return 0;
}

bool check_ch(int* ch_1, int* ch_2){
    for(int i = 0; i < 'z'-'a'; i++){
        if(ch_1[i] != ch_2[i]) return false;
    }
    return true;
}

bool anagram_of_itself(const char* word_1, const char* word_2){
    size_t len = strlen(word_1);
    if(len != strlen(word_2)) return false;
    for(size_t i = 0; i < len; i++){
        if(tolower(word_1[i]) != tolower(word_2[i])) 
            return false;
    }
    return true;
}