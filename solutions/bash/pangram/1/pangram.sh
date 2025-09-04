#!/usr/bin/env bash

sentence=$@
len=${#sentence}
alphabet="abcdefghijklmnopqrstuvwxyz"

for i in {0..25}; do              #Recorrer todas las letras
    letra="${alphabet:i:1}"
    encontrada=false
    for (( j=0; j<len; j++ )); do    #Recorrer toda la frase
        c="${sentence:j:1}"
        c="${c,,}"
        if [[ "$c" == "$letra" ]]; then
            encontrada=true
        elif [[ ! "$char" =~ ^[A-Z]$ ]]; then
            continue #Pasar al siguiente caracter de la frase 
        fi
    done
    # Si hay alguna letra que no se ha encontrado
    if [[ "$encontrada" == false ]]; then
        echo "false"
        exit
    fi
done
echo "true"