#!/usr/bin/env bash

number=$1
LEN=${#number}
result=0

for (( i=0; i < LEN; i++ )); do
    digit=${number:i:1}
    result=$(( result + digit ** LEN ))
done

if [ "$result" -eq "$number" ]; then
    echo "true"
else
    echo "false"
fi