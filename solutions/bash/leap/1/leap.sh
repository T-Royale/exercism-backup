#!/usr/bin/env bash

year="$1"

if [[ "$#" != 1 || "$year" =~ ^-?[0-9]+\.[0-9]+$ || "$year" =~ ^[a-zA-Z]+$ ]]; then
    echo "Usage: leap.sh <year>"
    exit 1
fi


(( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )) && echo "true" || echo "false"