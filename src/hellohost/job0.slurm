#!/bin/bash

#SBATCH --partition ffa
#SBATCH --job-name helloworld0
#SBATCH --cpus-per-task 4
#SBATCH --mem-per-cpu 2g
#SBATCH --time 0:10:00
#SBATCH --error=error.txt         # redirects stderr to error.txt
#SBATCH --output=output.txt       # redirects stdout to output.txt

name=$(hostname)
echo "Hello from" $name

sleep 30s

