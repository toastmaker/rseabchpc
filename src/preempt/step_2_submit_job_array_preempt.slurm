#!/bin/bash

#SBATCH --partition auuk #this partition has a higher priority than ffa-preempt
#SBATCH --job-name "job array with a higher priority"
#SBATCH --cpus-per-task 1
#SBATCH --mem-per-cpu 100m
#SBATCH --time 0:10:00
#SBATCH --array 1-16 # duplicate the job 16 times - slurm sets SLURM_ARRAY_TASK_ID environment variable which corresponds to the index each job in the array
#SBATCH --error=error_%a.txt         # redirects stderr to error_${SLURM_ARRAY_TASK_ID}.txt
#SBATCH --output=output_%a.txt       # redirects stdout to output_${SLURM_ARRAY_TASK_ID}.txt

name=$(hostname)
echo "Hello from" $name "I am job " $SLURM_ARRAY_TASK_ID

sleep 300s

