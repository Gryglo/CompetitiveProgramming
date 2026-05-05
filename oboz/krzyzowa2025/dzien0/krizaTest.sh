#!/bin/bash

for((i = 0; i <= 10000; i++))
do
    ./krizaGen > test
    ./kriza < test > out1
    ./krizaBrute < test > out2
    if ! diff out1 out2 > /dev/null
    then
        echo "BLAD"
        exit 0
    fi
    echo OK $i
done