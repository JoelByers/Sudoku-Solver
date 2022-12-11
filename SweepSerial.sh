#!/bin/bash

INPUT_FILE="puzzles/testPuzzleSweepSerial.txt"
OUTPUT_FOLDER="results"


for size in 4 9 16
do
    for fill in 80 75 70 65 60 65 55 50 45 40 35 30
    do
        for i in {1..15}
        do
            OUTPUT_FILE="${OUTPUT_FOLDER}/SerialSweep_${size}_1_${fill}.csv"
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
            ./sudokuSerial.out $INPUT_FILE >> $OUTPUT_FILE
            echo >> $OUTPUT_FILE
        done
    done
done 