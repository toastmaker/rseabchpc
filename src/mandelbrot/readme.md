# Mandelbrot set

For each point in complex plain $z_{n+1} = z_n^2 + c$, where $z_0 = 0$.

For each point we stop iterations if $|z|^2 > 4 $ or if $k > k_{max}$ max. number of iterations.

```
WIDTH    = 1200
HEIGHT   = 800
MAX_ITER = 500

x_min = -2.0
x_max =  1.0
y_min = -1.0
y_max =  1.0
```


