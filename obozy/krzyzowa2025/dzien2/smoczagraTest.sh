#!/bin/bash

for((i = 0; i <= 1000000; i++))
do
    ./smoczagraGen > test
    ./smoczagra < test > out1
    ./smoczagraBrute < test > out2
    if ! diff out1 out2 > /dev/null
    then
        echo "BLAD"
        exit 0
    fi
    echo OK $i
done