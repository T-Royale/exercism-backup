#!/usr/bin/env bash

grains=1
total=1
calc_total="false"

if [ $# -ne 1 ]; then
    exit 1
elif [[ $1 == "total" ]]; then
    squares=64
    calc_total="true"
elif (( $1 <= 0 || $1 > 64 )); then
    echo "Error: invalid input"
    exit 1
fi


if [[ -z "$squares" ]]; then
    squares=$1
fi

for ((i=1; i<squares; i++)); do
        grains=$(echo "$grains * 2" | bc)
        total=$(echo "$total + $grains" | bc)
done

if [[ $calc_total == "true" ]]; then
    echo "$total"
else
    echo "$grains"
fi