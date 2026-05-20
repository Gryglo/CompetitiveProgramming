#!/bin/bash
for((i = 1; i <= 100000; i++)); do
    ./gen > test.in
    ./brute < test.in > brute.out
    ./kor < test.in > kor.out
    if ! diff kor.out brute.out > /dev/null; then
        echo BLAD [ $i ]
        cat test.in
        exit 0
    else
        echo "OK [ $i ]"
    fi
done