#!/bin/bash
for((i = 1; i <= 100000; i++)); do
    ./gen > test.in
    ./pio < test.in > 1.out
    ./pio_2 < test.in > 2.out
    if ! diff 1.out 2.out > /dev/null; then
        echo "[ $i ] BLAD"
        exit 0
    else
        echo "[ $i ] OK"
    fi

done