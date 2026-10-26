#!/bin/bash

#SBATCH --job-name=my_first_hello
#SBATCH --partition=ffa
#SBATCH --nodes=1
#SBATCH --ntasks=2
#SBATCH --cpus-per-task=4
#SBATCH --time=01:00:00
#SBATCH --mem=8G
#SBATCH --output=%x_%j.out
#SBATCH --error=%x_%j.err
#SBATCH --open-mode=append

echo "Job $SLURM_JOB_NAME with $SLURM_JOB_ID"
echo "Task ID: $SLURM_PROCID"
echo "SLURM_JOB_NUM_NODES node(s): $SLURM_JOB_NODELIST"
echo "Num tasks: $SLURM_NTASKS"
echo "CPU/task: $SLURM_CPUS_PER_TASK"

srun echo "Hello world"
