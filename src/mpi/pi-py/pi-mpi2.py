
from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

N = 10_000_000
N = comm.bcast(N if rank == 0 else None, root=0)

comm.Barrier()
t0 = MPI.Wtime()

# Each rank computes its partial sum
local_sum = 0.0
for i in range(rank, N, size):
    x = (i + 0.5) / N
    local_sum += 4.0 / (1.0 + x*x)

# Collect partial sums manually
if rank == 0:
    total = local_sum
    for src in range(1, size):
        partial = comm.recv(source=src, tag=0)
        total += partial

    print(f"Pi = {total / N:.15f}")
    print(f"Time = {MPI.Wtime() - t0:.3f} s")
else:
    comm.send(local_sum, dest=0, tag=0)

