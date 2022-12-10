#!/bin/bash

INPUT_FILE="puzzles/testPuzzle3.txt"
OUTPUT_FOLDER="results"

for i in {1..15}
do
    for size in 4 9
    do
        for threads in 2 4 8 16 32
        do
            PERCENT="0"

            if [ $size -eq 4 ]
            then
                PERCENT="4"
            elif [ $size -eq 9 ]
            then
                PERCENT="21"
            fi

                OUTPUT_FILE="${OUTPUT_FOLDER}/Part3b_${size}_${threads}_${PERCENT}.csv"
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