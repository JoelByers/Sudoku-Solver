#!/bin/bash

INPUT_FILE="puzzles/testPuzzle7.txt"
OUTPUT_FOLDER="results"

for i in {1..100}
do
    for size in 4 9
    do
        for fill in 4 21 
        do
            OUTPUT_FILE="${OUTPUT_FOLDER}/Part1b_${size}_1_${fill}.csv"
            echo Outputing to $OUTPUT_FILE

            if [ $i -eq 1 ]
            then
                # Print csv headers
                echo size,threads,percent_fill,time > $OUTPUT_FILE
            fi

            # Generate a new puzzle for each run
            rm $INPUT_FILE
            ./gen.out $size $fill >> $INPUT_FILE

            echo -n $size,1,$fill, >> $OUTPUT_FILE

            # Set number of threads and run
            ./sudokuParallel.out $INPUT_FILE >> $OUTPUT_FILE
            echo >> $OUTPUT_FILE
        done
    done
done 