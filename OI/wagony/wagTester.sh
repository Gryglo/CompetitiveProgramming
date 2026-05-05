#!/bin/bash
for((i = 1; i <= 1000; i++))
do
    ./wagGen > test
    ./wag1 < test > out1
    ./wag < test > out2
    if ! diff out1 out2 > trash; then
        echo BLAD
        exit 0
    fi
    echo "OK " $i 
done