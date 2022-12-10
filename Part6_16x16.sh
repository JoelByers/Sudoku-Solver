#!/bin/bash

INPUT_FILE="puzzles/testPuzzle5.txt"
OUTPUT_FOLDER="results"


for size in 16
do
    for fill in 80 75 70 65 60 59 58 57 56 55 54 53 52 51 50
    do
        for i in {1..15}
        do
            OUTPUT_FILE="${OUTPUT_FOLDER}/16x16_${size}_36_${fill}.csv"
            echo Outputing to $OUTPUT_FILE

            if [ $i -eq 1 ]
            then
                # Print csv headers
                echo size,threads,percent_fill,time > $OUTPUT_FILE
            fi

            # Generate a new puzzle for each run
            rm $INPUT_FILE
            ./gen.out $size $fill >> $INPUT_FILE

            export OMP_NUM_THREADS=36
            echo -n $size,36,$fill, >> $OUTPUT_FILE

            # Set number of threads and run
            ./sudokuParallel.out $INPUT_FILE >> $OUTPUT_FILE
            echo >> $OUTPUT_FILE
        done
    done
done 