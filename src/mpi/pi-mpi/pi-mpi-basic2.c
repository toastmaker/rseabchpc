#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long N = 10000000;
    double local_sum = 0.0, total_sum = 0.0;

    MPI_Bcast(&N, 1, MPI_LONG, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    double t0 = MPI_Wtime();

    // MAP: each rank computes part of the sum
    for (long i = rank; i < N; i += size) {
        double x = (i + 0.5) / (double)N;
        local_sum += 4.0 / (1.0 + x*x);
    }

    // REDUCE: sum partial results on rank 0
    MPI_Reduce(&local_sum, &total_sum, 1,
               MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        double pi = total_sum / N;
        printf("Pi = %.15f\n", pi);
        printf("Time = %.6f s\n", MPI_Wtime() - t0);
    }

    MPI_Finalize();
    return 0;
}
