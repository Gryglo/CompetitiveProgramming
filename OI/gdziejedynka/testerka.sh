#!/bin/bash
for((i = 1; i <= 10000; i++)); do
    ./gen > test.in
    ./gdz < test.in > ans.out
    if diff ans.out wa.out > /dev/null; then
        echo BŁĄD
        cat test.in
        exit 0
    else
        echo OK [$i]
    fi
done