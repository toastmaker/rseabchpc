#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define WIDTH 1200
#define HEIGHT 800
#define MAX_ITER 500

int mandelbrot(double cr, double ci)
{
    double zr = 0.0;
    double zi = 0.0;

    for (int n = 0; n < MAX_ITER; n++) {

        double zr2 = zr * zr;
        double zi2 = zi * zi;

        if (zr2 + zi2 > 4.0)
            return n;

        zi = 2.0 * zr * zi + ci;
        zr = zr2 - zi2 + cr;
    }

    return MAX_ITER;
}

int main(void)
{
    const double xmin = -2.0;
    const double xmax =  1.0;
    const double ymin = -1.0;
    const double ymax =  1.0;

    int32_t *image = malloc(
        (size_t)WIDTH * HEIGHT * sizeof(int32_t)
    );

    if (!image) {
        perror("malloc");
        return 1;
    }

    clock_t start = clock();

    for (int j = 0; j < HEIGHT; j++) {

        double ci = ymin +
            (ymax - ymin) * j / (HEIGHT - 1);

        for (int i = 0; i < WIDTH; i++) {

            double cr = xmin +
                (xmax - xmin) * i / (WIDTH - 1);

            image[j * WIDTH + i] = mandelbrot(cr, ci);
        }
    }

    double elapsed =
        (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("Calculation time: %.3f s\n", elapsed);

    FILE *fp = fopen("mandelbrot.bin", "wb");

    if (!fp) {
        perror("fopen");
        free(image);
        return 1;
    }

    size_t written = fwrite(
        image,
        sizeof(int32_t),
        (size_t)WIDTH * HEIGHT,
        fp
    );

    if (written != (size_t)WIDTH * HEIGHT) {
        fprintf(stderr, "Error writing output\n");
        fclose(fp);
        free(image);
        return 1;
    }

    fclose(fp);
    free(image);

    printf("Saved mandelbrot.bin\n");

    return 0;
}

