#!/usr/bin/env bash

result=0
n=0
case $1 in
    "square_of_sum")
        for (( n=0; n<=$2; n++ )); do
            result=$(( result + n ))
        done
        result=$(( result*result ))
        ;;
    "sum_of_squares")
        for (( n=0; n<=$2; n++ )); do
            result=$(( result + n*n ))
        done        
        ;;
    "difference")
        square="$(./$0 square_of_sum $2)"
        sum="$(./$0 sum_of_squares $2)"
        result=$(( square - sum ))
        ;;
    *)
        echo not found
        ;;
esac


echo "$result"