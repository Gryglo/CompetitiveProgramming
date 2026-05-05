#!/bin/bash

for((i = 0; i <= 1000000; i++))
do
    ./zlotybananGen > test
    ./zlotybanan < test > out1
    ./zlotybananBrute < test > out2
    if ! diff out1 out2 > /dev/null
    then
        echo "BLAD"
        exit 0
    fi
    echo OK $i
done