#!/bin/bash

#SBATCH --job-name=pt5
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=32
#SBATCH --output=slurmOut/sudokuParallel-%j-%N.log
#SBATCH --partition=compute
#SBATCH --time=48:00:00

module purge
module use /cm/shared/modulefiles_local
module load shared
module load slurm
module load gcc/11.3.0
module list

./Part5.sh