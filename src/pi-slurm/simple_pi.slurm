#!/bin/bash
#SBATCH --job-name=calc_pi
#SBATCH --partition=ffa
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem=1G
#SBATCH --time=00:05:00
#SBATCH --output=simple_pi_%j.out

python calc_pi.py 1000000 42

