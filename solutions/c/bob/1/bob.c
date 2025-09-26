#include "bob.h"

/*
    Question?           -> Sure.
    YELLING             -> Whoa, chill out!
    YELL A QUESTION?    -> Calm down, I know what I'm doing!
    silence             -> Fine. Be that way!
    anything else       -> Whatever.
*/

char *hey_bob(char *greeting){
    int len = strlen(greeting);
    // Are you yelling
    bool isYelling = false;
    for(int i = 0; i < len; i++) if(isupper(greeting[i])) isYelling = true; // Find at least 1 uppercase
    bool isSilence = true;
    // Are you asking a question?
    bool isaQuestion = false;
    char *questionMark = strchr(greeting, '?');
    if(questionMark) {
        isaQuestion = true;
        while(*questionMark != '\0'){
            // If it finds a character after the ? it is not a question
            if(isalnum((unsigned char)*questionMark)) {
                isaQuestion = false;
                break;
            }
            questionMark++;
        }
    }
    for(int i = 0; i < len-1; i++){
        if(greeting[i] != ' ' && greeting[i] != '\t' && greeting[i] != '\r' && greeting[i] != '\n'){
            isSilence = false; // Not silence if it is any character other than ' ', '\t', '\r', '\n'
            if(islower(greeting[i])){
                isYelling = false; // Not yelling if there is a lowercase
            }
        }
    }
    if(isSilence)
        return "Fine. Be that way!";
    if(isYelling && isaQuestion)
        return "Calm down, I know what I'm doing!";
    else if(isYelling)
        return "Whoa, chill out!";
    else if(isaQuestion)
        return "Sure.";
    else return "Whatever.";
    return NULL;
}