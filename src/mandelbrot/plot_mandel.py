import numpy as np
import matplotlib.pyplot as plt

WIDTH = 1200
HEIGHT = 800

# Read binary data
image = np.fromfile(
    "mandelbrot.bin",
    dtype=np.int32
)

# Convert 1D array into 2D image
image = image.reshape((HEIGHT, WIDTH))

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
plt.title("Mandelbrot Set (computed in C)")

plt.tight_layout()

plt.savefig("mandelbrot.png", dpi=200)

plt.show()

