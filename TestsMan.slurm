#!/bin/bash

#SBATCH --job-name=16x16
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=36
#SBATCH --output=slurmOut/sudokuParallel-%j-%N.log
#SBATCH --partition=compute
#SBATCH --time=48:00:00

module purge
module use /cm/shared/modulefiles_local
module load shared
module load slurm
module load gcc/11.3.0
module list

echo 40
./gen.out 16 40 > puzzles/testManual1

export OMP_NUM_THREADS=36
echo Number of Threads: $OMP_NUM_THREADS
./sudokuParallel.out puzzles/16x16/testManual1.txt
