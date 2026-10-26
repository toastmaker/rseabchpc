#!/bin/bash

#SBATCH --partition ffa-preempt
#SBATCH --job-name "preemptable job"
#SBATCH --cpus-per-task 1
#SBATCH --mem-per-cpu 100m
#SBATCH --time 0:10:00
#SBATCH --array 1-32 # duplicate the job 32 times - slurm sets SLURM_ARRAY_TASK_ID environment variable which corresponds to the index each job in the array
#SBATCH --error=error_preempt_%a.txt         # redirects stderr to error_${SLURM_ARRAY_TASK_ID}.txt
#SBATCH --output=output_preempt_%a.txt       # redirects stdout to output_${SLURM_ARRAY_TASK_ID}.txt

name=$(hostname)
echo "Hello from" $name "I am job " $SLURM_ARRAY_TASK_ID

sleep 300s

