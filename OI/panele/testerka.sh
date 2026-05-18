#!/bin/bash
for((i = 1; i <= 10000; i++)); do
    ./gen > test.in
    ./brute < test.in > brute.out
    ./pan < test.in > wzor.out
    if ! diff wzor.out brute.out > /dev/null; then
        echo BLAD
        exit 0
    else
        echo "OK [ $i ]"
    fi
done