#!/bin/bash

#SBATCH --partition ffa
#SBATCH --job-name helloworld0
#SBATCH --ntasks 4
#SBATCH --cpus-per-task 1
#SBATCH --mem-per-cpu 2g
#SBATCH --time 0:10:00
#SBATCH --error=error.txt         # redirects stderr to error.txt
#SBATCH --output=output.txt       # redirects stdout to output.txt

name=$(hostname)
srun --label echo "Hello from" $name

sleep 30s

