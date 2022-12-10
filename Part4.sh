#!/bin/bash

INPUT_FILE="puzzles/testPuzzle.txt"

for i in {1..15}
do
    for size in 25
    do
        for threads in 32 16 8 4 2 1
        do

            OUTPUT_FILE="Part3_${size}_${threads}_30.csv"
            echo Outputing to $OUTPUT_FILE

            if [ $i -eq 1 ]
            then
                # Print csv headers
                echo size,threads,percent_fill,time > $OUTPUT_FILE
            fi

            # Generate a new puzzle for each run
            rm $INPUT_FILE
            ./gen.out $size 30 >> $INPUT_FILE

            echo -n $size,$threads,30, >> $OUTPUT_FILE

            # Set number of threads and run
            export OMP_NUM_THREADS=$threads
            ./sudokuParallel.out $INPUT_FILE >> $OUTPUT_FILE
            echo >> $OUTPUT_FILE
        done
    done
done 