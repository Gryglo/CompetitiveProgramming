#!/bin/bash

for((i = 0; i <= 1000000; i++))
do
    ./kielbasaGen > test
    ./kielbasa < test > out1
    ./kielbasaBrute < test > out2
    if ! diff out1 out2 > /dev/null
    then
        echo "BLAD"
        exit 0
    fi
    echo OK $i
done