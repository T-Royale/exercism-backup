#include "matching_brackets.h"

bool is_paired(const char *input){
    int len = strlen(input);
    int count = 0;      // Cuenta los que abren
    int tmp = 0;        // Cuenta los que cierran
    int seen[len];
    int seen_count = 0; // última posición de seen

    for(int i = 0; i < len; i++) {
        if(input[i] == '(' || input[i] == '[' || input[i] == '{') {
            count++;
        }
        if(input[i] == ')' || input[i] == ']' || input[i] == '}') {
            tmp++;
        }
    }

    if(tmp != count) return false; //Tienen que abrir los mismos que cierran

    abierto_t abiertos[count];
    int j = 0;

    for(int i = 0; i < len; i++){
        if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
            abiertos[j].value = input[i];
            abiertos[j].pos = i; 
            j++;
        }
    }

    for(int i = count - 1; i >= 0; i--) {
        for(int j = abiertos[i].pos; j < len; j++){
            switch(abiertos[i].value){
                case '(':
                    if(input[j] == ')'){
                        seen[seen_count++] = abiertos[i].pos;
                        seen[seen_count++] = j;
                        j = len + 1;      //Para que salga del for
                    } else if(input[j] == '[' || input[j] == '{' || input[j] == ']' || input[j] == '}'){
                        bool alreadySeen = false;
                        for(int k = 0; k < len; k++){
                            if(seen[k] == j) alreadySeen = true;
                        }
                        if(!alreadySeen) return false;
                    }
                    break;
                case '[':
                    if(input[j] == ']'){
                        seen[seen_count++] = abiertos[i].pos;
                        seen[seen_count++] = j;
                        j = len + 1;      //Para que salga del for
                    } else if(input[j] == '(' || input[j] == '{' || input[j] == ']' || input[j] == ')'){    
                        bool alreadySeen = false;
                        for(int k = 0; k < len; k++){
                            if(seen[k] == j) alreadySeen = true;
                        }
                        if(!alreadySeen) return false;
                    }
                    break;
                case '{':
                    if(input[j] == '}'){
                        seen[seen_count++] = abiertos[i].pos;
                        seen[seen_count++] = j;
                        j = len + 1;      //Para que salga del for
                    } else if(input[j] == '[' || input[j] == '(' || input[j] == ']' || input[j] == ')'){
                        bool alreadySeen = false;
                        for(int k = 0; k < len; k++){
                            if(seen[k] == j) alreadySeen = true;
                        }
                        if(!alreadySeen) return false;
                    }
                    break;
                default:
                    continue;
                    break;
            }
        }
        if(seen[seen_count - 2] != abiertos[i].pos){
            return false;
        }
    }
    return true;
}