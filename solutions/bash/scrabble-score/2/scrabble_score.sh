#!/usr/bin/env bash

word="$1"
len=${#word}
score=0

for ((i=0; i<len; i++)); do
    c="${word:i:1}"
    c="${c,,}"
    case $c in
        "a"|"e"|"i"|"o"|"u"|"l"|"n"|"r"|"s"|"t")
            ((score += 1))
            ;;
        "d"|"g")
            ((score += 2))
            ;;
        "b"|"c"|"m"|"p")
            ((score += 3))
            ;;
        "f"|"h"|"v"|"w"|"y")
            ((score += 4))
            ;;
        "k")
            ((score += 5))
            ;;
        "j"|"x")
            ((score += 8))
            ;;
        "q"|"z")
            ((score += 10))
            ;;
        *)
            ;;
    esac
done

echo "$score"
