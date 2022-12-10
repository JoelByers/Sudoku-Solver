#!/bin/bash

#SBATCH --job-name=sudokuParallel
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=36
#SBATCH --output=slurmOut/sudokuParallel-%j-%N.log
#SBATCH --partition=quickq
#SBATCH --time=1:00:00

module purge
module use /cm/shared/modulefiles_local
module load shared
module load slurm
module load gcc/11.3.0
module list

export OMP_NUM_THREADS=36
echo Number of Threads: $OMP_NUM_THREADS

export TEST_FILE=puzzles/25x25/25x25_1.txt
#echo -n Serial: 
#./sudokuSerial.out $TEST_FILE
#echo
echo -n Parallel: 
./sudokuParallel.out $TEST_FILE