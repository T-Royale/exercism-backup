#!/usr/bin/env bash

question=0
yell=0
characters=0
letters=0

if [ "$#" -eq 0 ]; then
    echo "Fine. Be that way!"
    exit
fi

sentence="$@"
len=${#sentence}

for(( i=0; i < len; i++ )); do
    char=${sentence:$i:1}

    case "$char" in
        [a-z])
            yell="false"
            ((letters++))
            ;;
        [A-Z])
            ((letters++))
            ;;
        [[:space:]] | [0-9] | "!" | "?" | "," | "." | "-" | "*" | "%" | "^" | "@" | "#" | "$" | "(" | ")" | "'")
            ;;
        *)
            yell=false
            silence="false"
            ;;
    esac
done

lastChar=0

for (( i=1; i < $len; i++ )); do
    lastChar="${sentence:$((len-i)):1}"
    case "$lastChar" in
        "?" | "!" | [a-z] | [A-Z])
            break
            ;;
        *)
            continue
            ;;
    esac
done


if [[ "$lastChar" == "?" ]]; then
    question="true"
fi
if [[ "$yell" == 0 && "$letters" -gt 0 ]]; then
    yell="true"
fi

if [[ -z "${sentence//[[:space:]]/}" ]]; then
    echo "Fine. Be that way!"
    exit
fi

if [[ "$yell" == "true" && "$question" == "true" ]]; then
    echo "Calm down, I know what I'm doing!"
elif [[ "$yell" == "true" ]]; then
    echo "Whoa, chill out!"
elif [[ "$question" == "true" ]]; then
    echo "Sure."
else 
    echo "Whatever."
fi