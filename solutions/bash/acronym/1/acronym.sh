#!/usr/bin/env bash

result=""
LEN=${#1};
PHRASE="$1"
isNewWord="true"    # Contar la primera letra 

for ((i=0; i<LEN; i++)); do
    char="${PHRASE:i:1}"  # Carácter actual
    char=$(echo "$char" | tr '[:lower:]' '[:upper:]') # Pasar a mayusculas

    if [[ $char == " " || $char == "-" ]]; then
        isNewWord="true"
        continue
    elif [[ $char == "_"  || ! "$char" =~ ^[A-Z]$ ]]; then
        continue
    fi

    if [ $isNewWord == "true" ]; then
        result+="$char"
        isNewWord="false"
    fi

    isNewWord="false"
done

echo "$result"