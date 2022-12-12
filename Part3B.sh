#!/bin/bash

OUTPUT_FOLDER="results2"

for size in 9
do
    for fill in 80 75 70 65 60 55 50 45 40 35 30
    do
        for threads in 16
        do
            for i in {1..15}
            do
                INPUT_FILE="puzzles/Part3B_${size}_${threads}_${fill}.txt"
                OUTPUT_FILE="${OUTPUT_FOLDER}/Part3B_${size}_${threads}_${fill}.csv"
                echo Outputing to $OUTPUT_FILE

                if [ $i -eq 1 ]
                then
                    # Print csv headers
                    echo size,threads,percent_fill,time > $OUTPUT_FILE
                fi

                # Generate a new puzzle for each run
                ./gen.out $size $fill > $INPUT_FILE

                export OMP_NUM_THREADS=$threads
                echo -n $size,$threads,$fill, >> $OUTPUT_FILE

                # Set number of threads and run
                export OMP_NUM_THREADS=$threads
                ./sudokuParallel.out $INPUT_FILE >> $OUTPUT_FILE
                echo >> $OUTPUT_FILE
            done
        done
    done
done 