#!/bin/bash
#SBATCH --job-name=calc_pi
#SBATCH --partition=ffa
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --time=00:05:00
#SBATCH --output=pi_%j.out
python calc_pi.py "$1" "$2"
