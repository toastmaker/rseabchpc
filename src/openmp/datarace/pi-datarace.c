#include <stdio.h>
#include <omp.h>

#define N 1000000

int main(void) {

    double sum = 0.0;
    double dx = 1.0 / N;

    double start = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {

        double x = (i + 0.5) * dx;

        sum += 4.0 / (1.0 + x*x);
    }

    double pi = sum * dx;
    double elapsed = omp_get_wtime() - start;

    printf("Pi = %.15f\n", pi);
    printf("Time = %.4f s\n", elapsed);

    return 0;
}
