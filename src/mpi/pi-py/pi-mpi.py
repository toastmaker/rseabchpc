from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

N = 100_000_000
dx = 1.0 / N

# MAP: each process calculates its own samples
i = np.arange(rank, N, size)
x = (i + 0.5) * dx
local_pi = np.sum(4.0 / (1.0 + x*x)) * dx

if rank == 0:
    # Master collects and sums
    pi = local_pi

    for source in range(1, size):
        received = comm.recv(source=source, tag=0)
        pi += received

    print(f"Pi = {pi:.12f}")

else:
    # Workers send partial results
    comm.send(local_pi, dest=0, tag=0)
