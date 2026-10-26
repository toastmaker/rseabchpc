#!/bin/bash
#SBATCH --job-name=array_calc_pi
#SBATCH --partition=ffa
#SBATCH --array=0-7
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem=1G
#SBATCH --time=00:05:00
#SBATCH --output=pi_%A_%a.out

python calc_pi.py 100000 "$SLURM_ARRAY_TASK_ID"

