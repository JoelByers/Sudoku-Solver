#!/bin/bash

INPUT_FILE="puzzles/testPuzzleSweepSerial.txt"
OUTPUT_FOLDER="results"


for size in 16
do
    for fill in 33
    do
        for i in {1..15}
        do
            OUTPUT_FILE="${OUTPUT_FOLDER}/16x16MinSerial_${size}_1_${fill}.csv"
            echo Outputing to $OUTPUT_FILE

            if [ $i -eq 1 ]
            then
                # Print csv headers
                echo size,threads,percent_fill,time >> $OUTPUT_FILE
            fi

            # Generate a new puzzle for each run
            rm $INPUT_FILE
            ./gen.out $size $fill >> $INPUT_FILE

            export OMP_NUM_THREADS=32
            echo -n $size,1,$fill, >> $OUTPUT_FILE

            # Set number of threads and run
            ./sudokuSerial.out $INPUT_FILE >> $OUTPUT_FILE
            echo >> $OUTPUT_FILE
        done
    done
done 