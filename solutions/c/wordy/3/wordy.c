#include "wordy.h"
#include <stdio.h>

bool answer(const char *question, int *result){
	int a;
	int chars_read;
	if(sscanf(question, "What is %d%n", &a, &chars_read) == 1) *result = a;
	else return false;
	const char* pos = question+chars_read;
	while(*pos++ != '?'){
		if(sscanf(pos, "plus %d%n", &a, &chars_read) == 1){
			*result += a;
		} else if(sscanf(pos, "minus %d%n", &a, &chars_read) == 1){
			*result -= a;
		} else if(sscanf(pos, "multiplied by %d%n", &a, &chars_read) == 1){
			*result *= a;
		} else if(sscanf(pos, "divided by %d%n", &a, &chars_read) == 1){
			*result /= a;
		}
		else return false;
		pos+=chars_read;
	}
	return true;
}