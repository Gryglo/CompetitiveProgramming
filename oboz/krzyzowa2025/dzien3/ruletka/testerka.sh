#!/bin/bash

for((i = 1; i <= 256; i++))
do
    echo $i > test
    echo $i
    ./interaktor test ./ruletka
done