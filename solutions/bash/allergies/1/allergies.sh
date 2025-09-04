#!/usr/bin/env bash

result=""

allergies="$1"
options="$2"

declare -A allergen
allergen_order=()

allergen[cats]=128
allergen_order+=("cats")
allergen[pollen]=64
allergen_order+=("pollen")
allergen[chocolate]=32
allergen_order+=("chocolate")
allergen[tomatoes]=16
allergen_order+=("tomatoes")
allergen[strawberries]=8
allergen_order+=("strawberries")
allergen[shellfish]=4
allergen_order+=("shellfish")
allergen[peanuts]=2
allergen_order+=("peanuts")
allergen[eggs]=1
allergen_order+=("eggs")

while [ "$allergies" -ge 256 ]; do
    (( allergies-=256 ))
done


for key in "${allergen_order[@]}"; do
    if [ "$allergies" -ge "${allergen[$key]}" ]; then
        (( allergies-="${allergen[$key]}" ))
        result="${key} ${result}"
    fi
done

result=$(echo -n "$result" | head -c -1)

if [ "$options" == "list" ]; then
    echo "$result"
elif [ "$options" == "allergic_to" ]; then
    if [[ "$result" == *"$3"* ]]; then
        echo "true"
    else 
        echo "false"
    fi
fi
