import numpy as np
import sys

n_samples = int(sys.argv[1])
seed = int(sys.argv[2])
rng = np.random.default_rng(seed)

x = rng.random(n_samples)
y = rng.random(n_samples)
n_inside = np.count_nonzero(x*x + y*y <= 1)

result = 4*n_inside/n_samples
print(result)
