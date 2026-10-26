from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

N = 100_000_000
dx = 1.0 / N

i = np.arange(rank, N, size)
x = (i + 0.5) * dx
local_pi = np.sum(4.0 / (1.0 + x*x)) * dx

# REDUCE: sum partial results on rank 0
pi = comm.reduce(local_pi, op=MPI.SUM, root=0)

if rank == 0:
    print(f"Pi = {pi:.12f}")
