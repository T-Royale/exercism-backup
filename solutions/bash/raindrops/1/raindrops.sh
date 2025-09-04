#!/usr/bin/env bash

#   - is divisible by 3, add "Pling" to the result.
#   - is divisible by 5, add "Plang" to the result.
#   - is divisible by 7, add "Plong" to the result.

if [ $# -ne 1 ]; then
    echo "ERROR MESSAGE"
    exit 1
fi

result=""
divisible="false"

if (( $1 % 3 == 0 ));then
    result="Pling"
    divisible="true"
fi

if (( $1 % 5 == 0 ));then
    result="${result}Plang"
    divisible="true"
fi

if (( $1 % 7 == 0 ));then
    result="${result}Plong"
    divisible="true"
fi

if [ $divisible = "false" ]; then
    result=$1
fi

echo "$result"