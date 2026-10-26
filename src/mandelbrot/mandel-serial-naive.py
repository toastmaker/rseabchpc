import matplotlib.pyplot as plt
import time

WIDTH = 1200
HEIGHT = 800
MAX_ITER = 500

xmin, xmax = -2.0, 1.0
ymin, ymax = -1.0, 1.0


def mandelbrot(cr, ci):
    zr, zi = 0.0, 0.0

    for n in range(MAX_ITER):
        zr2 = zr * zr
        zi2 = zi * zi

        if zr2 + zi2 > 4.0:
            return n

        zi = 2.0 * zr * zi + ci
        zr = zr2 - zi2 + cr

    return MAX_ITER


# Allocate 2D image
image = [[0] * WIDTH for _ in range(HEIGHT)]

t0 = time.perf_counter()

# Serial calculation
for j in range(HEIGHT):
    ci = ymin + (ymax - ymin) * j / (HEIGHT - 1)

    for i in range(WIDTH):
        cr = xmin + (xmax - xmin) * i / (WIDTH - 1)

        image[j][i] = mandelbrot(cr, ci)

print(f"Elapsed: {time.perf_counter() - t0:.3f} s")

import numpy as np
# Plot
plt.figure(figsize=(12, 8))

plt.imshow(
    np.log10(np.array(image)),
    extent=[xmin, xmax, ymin, ymax],
    origin="lower",
    cmap="inferno"
)

plt.colorbar(label="Escape iterations")
plt.xlabel("Real(c)")
plt.ylabel("Imag(c)")
plt.title("Mandelbrot Set - Serial Python")

plt.tight_layout()
plt.show()
