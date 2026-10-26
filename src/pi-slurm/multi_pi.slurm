#!/bin/bash

#SBATCH --job-name=multi_calc_pi
#SBATCH --partition=ffa
#SBATCH --nodes=1
#SBATCH --ntasks=8
##SBATCH --ntasks-per-node=4
#SBATCH --cpus-per-task=1
#SBATCH --mem=1G
#SBATCH --time=00:05:00
#SBATCH --output=multi_pi_%j.out

# Run 8 independent calculations, each with a unique seed
srun bash -c 'python calc_pi.py 100000 "$SLURM_PROCID"'
