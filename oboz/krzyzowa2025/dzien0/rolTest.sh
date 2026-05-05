#!/bin/bash

for((i = 0; i <= 10000000; i++))
do
    ./rolGen > test.txt
    ./rol < test.txt > out1
    ./rolBrute < test.txt > out2
    if ! diff out1 out2 > /dev/null
    then
        echo "BLAD"
        exit 0
    fi
    echo OK $i
done