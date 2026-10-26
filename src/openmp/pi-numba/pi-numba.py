import numpy as np
from numba import njit, prange, set_num_threads, get_num_threads
import time

@njit(parallel=True)
def calc_pi(N):
    dx = 1.0 / N
    total = 0.0

    for i in prange(N):
        x = (i + 0.5) * dx
        total += 4.0 / (1.0 + x*x)

    return total * dx


N = 100_000_000

set_num_threads(4)

# Warm-up: trigger JIT compilation
calc_pi(1000)

start = time.perf_counter()
pi = calc_pi(N)
elapsed = time.perf_counter() - start

print(f"Threads: {get_num_threads()}")
print(f"Pi:      {pi:.15f}")
print(f"NumPy π: {np.pi:.15f}")
print(f"Time:    {elapsed:.4f} s")
