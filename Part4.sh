#!/bin/bash

INPUT_FILE="puzzles/testPuzzle4c.txt"

for i in {1..15}
do
    for size in 16
    do
        for threads in 36
        do

            OUTPUT_FILE="Part4d_${size}_${threads}_30.csv"
            echo Outputing to results/$OUTPUT_FILE

            if [ $i -eq 1 ]
            then
                # Print csv headers
                echo size,threads,percent_fill,time > $OUTPUT_FILE
            fi

            # Generate a new puzzle for each run
            ./gen.out $size 57 > $INPUT_FILE

            echo -n $size,$threads,57, >> $OUTPUT_FILE

            # Set number of threads and run
            export OMP_NUM_THREADS=$threads
            ./sudokuParallel.out $INPUT_FILE >> $OUTPUT_FILE
            echo >> $OUTPUT_FILE
        done
    done
done 