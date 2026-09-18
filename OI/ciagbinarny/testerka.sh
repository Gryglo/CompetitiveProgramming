#!/bin/bash
for((i = 1; i <= 10000; i++)); do
    ./gen > test.in
    ./cia < test.in > out1
    ./brute < test.in > out2
    if diff out1 out2 > /dev/null; then
        echo "[ $i ] OK"
    else
        echo "BLAD"
        exit 0
    fi
done