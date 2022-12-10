#!/bin/bash

INPUT_FILE="puzzles/testPuzzle.txt"
OUTPUT_FOLDER="results"

for i in {1..15}
do
    for size in 9 16
    do
        for threads in 2 4 8 16 32
        do
            PERCENT="0"

            if [ $size -eq 9 ]
            then
                PERCENT="21"
            elif [ $size -eq 16 ]
            then
                PERCENT="34"
            fi

                OUTPUT_FILE="${OUTPUT_FOLDER}/Part3_${size}_${threads}_${PERCENT}.csv"
                echo Outputing to $OUTPUT_FILE

            if [ $i -eq 1 ]
            then
                # Print csv headers
                echo size,threads,percent_fill,time > $OUTPUT_FILE
            fi

            # Generate a new puzzle for each run
            rm $INPUT_FILE
            ./gen.out $size $PERCENT >> $INPUT_FILE

            echo -n $size,$threads,$PERCENT, >> $OUTPUT_FILE

            # Set number of threads and run
            export OMP_NUM_THREADS=$threads
            ./sudokuParallel.out $INPUT_FILE >> $OUTPUT_FILE
            echo >> $OUTPUT_FILE
        done
    done
done 