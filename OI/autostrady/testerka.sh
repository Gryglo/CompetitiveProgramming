#!/bin/bash
for((i = 1; i <= 10000; i++)); do
    ./gen > test.in
    ./aut < test.in >> test.in
    ./checker < test.in > ans.out
    if ! diff ans.out ok > /dev/null; then
        echo "[ $i ] BLAD"
        cat test.in
        cat ans.out
        exit 0
    else
        echo "[ $i ] OK"
    fi
done