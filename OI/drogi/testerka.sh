#!/bin/bash
for((i = 1; i <= 10000; i++)); do
    ./gen > test
    ./brute < test > out1
    ./dro < test > out2
    if ! diff out1 out2 > /dev/null; then
        echo BLAD
        exit 0
    else
        echo OK [$i]
    fi  
done