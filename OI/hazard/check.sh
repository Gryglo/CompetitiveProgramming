#!/bin/bash

# Kompilacja
for ((i=1; ; i++)); do
    ./gen > input.txt
    
    # Pobieramy tylko informację, czy programy wypisały NIE
    # Bo ścieżki mogą się różnić, a obie być poprawne
    BRUTE_RES=$(./brute < input.txt | grep -q "NIE" && echo "NIE" || echo "OK")
    SOL_RES=$(./haz < input.txt | grep -q "NIE" && echo "NIE" || echo "OK")

    if [ "$BRUTE_RES" != "$SOL_RES" ]; then
        echo "BŁĄD W TEŚCIE $i"
        echo "--- WEJŚCIE ---"
        cat input.txt
        echo "Brute mówi: $BRUTE_RES"
        echo "Twój mówi: $SOL_RES"
        exit 1
    fi

    if (( i % 100 == 0 )); then
        echo "Przetestowano $i próbek..."
    fi
done