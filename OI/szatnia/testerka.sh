#!/bin/bash
for((i = 1; i <= 100000; i++)); do
    ./gen > test.in
    ./brute < test.in > brute.out
    ./szatnia < test.in > wzor.out
    if diff brute.out wzor.out > /dev/null; then
        echo "OK [ $i ]"
    else
        echo "BLAD [ $i ]"
        exit 0
    fi
done