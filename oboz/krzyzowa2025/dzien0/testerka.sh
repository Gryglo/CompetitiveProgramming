#!/bin/bash

for((i = 0; i <= 100; i++)) 
do
    ./rozniczka > test1
    echo "brut" > test2
    ./rozniczka > test3
    if ! diff test1 test3 > /dev/null; then
        echo N0
        exit 0
    fi 
    echo [$i] OK
done