#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 10

int main(void) {

    double input[N];
    double output[N];

    // Initialize input
    for (int i = 0; i < N; i++) {
        input[i] = (i + 1) * (i + 1);
    }

    #pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

        // Each thread processes a different part of the array
        for (int i = tid; i < N; i += nthreads) {
            double x = input[i];
            double result = sqrt(x);
            output[i] = result;
            printf("Thread %d: sqrt(%.0f) = %.0f\n",
                   tid, x, result);
        }
    }

    printf("\nFinal results:\n");

    for (int i = 0; i < N; i++) {
        printf("%.0f ", output[i]);
    }

    printf("\n");

    return 0;
}
