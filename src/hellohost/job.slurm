#!/usr/bin/env bash

#SBATCH --job-name=hostname
#SBATCH --partition=ffa
#SBATCH --nodes=1
#SBATCH --ntasks=4
#SBATCH --time=00:01:00

# hostname
srun hostname
