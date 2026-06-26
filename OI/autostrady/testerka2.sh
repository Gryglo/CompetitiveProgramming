#!/bin/bash
x=1
for((i = 1; i <= 1000000; i++)); do
    ./gen > test.in
    ./brute < test.in > brute.out
    #echo "[ $i ] Szukanie testu..."
    if diff brute.out nie > /dev/null; then
        #echo "[ $i ] Test znaleziony..."
        ./aut < test.in > ans.out
        if ! diff ans.out brute.out > /dev/null; then
            echo "[ $i ] BLAD"
            cat test.in
            exit 0
        else
            echo "[ $x ] OK"
        fi
        ((x++))
    fi
done