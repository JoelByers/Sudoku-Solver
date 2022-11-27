#!/bin/bash

for i in {1..6}
do
    ./sudokuSerial.out puzzles/9x9/9x9_$i.txt >> 9x9.csv
    echo >> 9x9.csv
done