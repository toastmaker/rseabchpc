#include <stdio.h>
#include <omp.h>

#define N 10

int main(void) {

    int counter = 0;
    int nthreads = 0;

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();

        #pragma omp single
        nthreads = omp_get_num_threads();

        for (int i = 0; i < N; i++) {
            counter++;
        }
    }

    int expected = nthreads * N;

    printf("Expected: %ld\n", expected);
    printf("Actual:   %ld\n", counter);

    return 0;
}
