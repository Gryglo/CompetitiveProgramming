#!/bin/bash
for((i = 1; i <= 10000; i++)); do
    ./gen > test
    ./meteory_persistentSegTree < test > out1
    ./meteory < test > out2
    if diff out1 out2 > /dev/null; then
        echo "[ $i ] OK"
    else
        echo "BLAD"
        exit 0
    fi
done