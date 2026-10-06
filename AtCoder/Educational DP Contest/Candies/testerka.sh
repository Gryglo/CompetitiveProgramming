#!/bin/bash
for((i = 1; i <= 10000; i++)); do
    ./gen > test
    ./M < test > out1
    ./brute < test > out2
    if diff out1 out2 > /dev/null; then
        echo "OK [ $i ]"
    else
        echo "BLAD!"
        exit 0
    fi
done