#!/usr/bin/env bash

string=$@
result=""
len=${#string}

for (( i="$len"; i >= 0; i-- )); do
    result+=${string:$i:1}
done

echo "$result"