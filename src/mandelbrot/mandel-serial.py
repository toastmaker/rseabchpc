import numpy as np
import matplotlib.pyplot as plt
import time

WIDTH = 1200
HEIGHT = 800
MAX_ITER = 500

# Complex plane
x = np.linspace(-2.0, 1.0, WIDTH)
y = np.linspace(-1.0, 1.0, HEIGHT)

X, Y = np.meshgrid(x, y)
C = X + 1j * Y

Z = np.zeros_like(C)

# Escape iteration count
image = np.full(C.shape, MAX_ITER, dtype=np.int32)

# Pixels that have not escaped
active = np.ones(C.shape, dtype=bool)

t0 = time.perf_counter()

for n in range(MAX_ITER):

    # Update only active pixels
    Z[active] = Z[active]**2 + C[active]

    # Find newly escaped pixels
    escaped = active & (np.abs(Z) > 2)

    image[escaped] = n + 1

    active[escaped] = False

    if not np.any(active):
        break

print(f"Elapsed: {time.perf_counter() - t0:.3f} s")

# Plot
plt.figure(figsize=(12, 8))

plt.imshow(
    np.log10(image),
    extent=[-2, 1, -1, 1],
    origin="lower",
    cmap="inferno",
    interpolation="nearest"
)

plt.colorbar(label="Escape iterations")
plt.xlabel("Real(c)")
plt.ylabel("Imag(c)")
plt.title("Mandelbrot Set")

plt.tight_layout()
plt.show()
