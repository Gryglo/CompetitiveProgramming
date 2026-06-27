#!/bin/bash
for((i = 1; i <= 10000; i++)); do
    ./gen > test
    ./zap_pareto < test > out1
    ./zap < test > out2
    if ! diff out1 out2 > /dev/null; then
        echo "BLAD [ $i ]"
        cat test
        exit 0
    else
        echo "OK [ $i ]"
    fi


done