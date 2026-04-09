#include "rail_fence_cipher.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *rail_fence_cipher(char* text, size_t rails, operations_e op){
	size_t len = strlen(text);
	char* result = calloc(len+1, sizeof(char));
	if(rails == 1) return (char*)text;
	int counter = 0;

	for(size_t k = 0; k < rails; k++){
		size_t jump_a = (rails - 1 - k)*2;
		size_t jump_b = k*2;
		bool use_jump_a = true;

		size_t pos = k;
		while(pos < len){
			if(op == ENCODE){
				result[counter++] = text[pos];
			} else if (op == DECODE){
				result[pos] = text[counter++];
			} else return NULL;
			
			if(!jump_a){
				pos+=jump_b;
			} else if(!jump_b){
				pos+=jump_a;
			} else {	// Ni a ni b son 0
				if(use_jump_a) pos+=jump_a;
				else pos+=jump_b;
				use_jump_a = !use_jump_a;
			}
		}
	}
	return result;
}

char *encode(char *text, size_t rails){
	return rail_fence_cipher(text, rails, ENCODE);
}

char *decode(char *ciphertext, size_t rails){
	return rail_fence_cipher(ciphertext, rails, DECODE);
}
