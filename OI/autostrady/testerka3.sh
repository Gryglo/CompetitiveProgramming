#!/bin/bash
for((i = 1; i <= 10000; i++)); do
    ./gen > test.in
    ./aut < test.in > ans.out
    ./brute < test.in > brute.out
    if ! diff ans.out brute.out > /dev/null; then
        echo "[ $i ] BLAD"
        cat test.in
        echo WZOR:
        cat ans.out
        echo
        echo BRUTE:
        cat brute.out
        exit 0
    else
        echo "[ $i ] OK"
    fi
done