#!/bin/bash

INPUT_FILE="puzzles/testPuzzle.txt"

for i in {1..15}
do
    for size in 4 9
    do
        for fill in 30 40 50 
        do
            for threads in 2 4 8 16 32
            do
                OUTPUT_FILE="Part2b_${size}_${threads}_${fill}.csv"
                echo Outputing to $OUTPUT_FILE

                if [ $i -eq 1 ]
                then
                    # Print csv headers
                    echo size,threads,percent_fill,time > $OUTPUT_FILE
                fi

                # Generate a new puzzle for each run
                rm $INPUT_FILE
                ./gen.out $size $fill >> $INPUT_FILE

                echo -n $size,$threads,$fill, >> $OUTPUT_FILE

                # Set number of threads and run
                export OMP_NUM_THREADS=$threads
                ./sudokuParallel.out $INPUT_FILE >> $OUTPUT_FILE
                echo >> $OUTPUT_FILE
            done
        done
    done
done 