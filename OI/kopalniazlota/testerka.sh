#!/bin/bash
for((i = 1;; i++))
do
    ./kopGen > test
    ./kopBrute < test > out1
    ./kop < test > out2
    if ! diff out1 out2 > /dev/null; then
        echo BLAD $i
        exit 0
    else
        echo OK $i
    fi
done