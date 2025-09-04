#!/usr/bin/env bash

word="$1"
len=${#word}
score=0

for ((i=0; i<len; i++)); do
    c="${word:i:1}"
    c="${c,,}"
    case $c in
        "a"|"e"|"i"|"o"|"u"|"l"|"n"|"r"|"s"|"t")
            ((score = score + 1))
            ;;
        "d"|"g")
            ((score = score + 2))
            ;;
        "b"|"c"|"m"|"p")
            ((score = score + 3))
            ;;
        "f"|"h"|"v"|"w"|"y")
            ((score = score + 4))
            ;;
        "k")
            ((score = score + 5))
            ;;
        "j"|"x")
            ((score = score + 8))
            ;;
        "q"|"z")
            ((score = score + 10))
            ;;
        *)
            ;;
    esac
done

echo "$score"
