#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const long N = 100000000;
    double dx = 1.0 / N;
    double local_pi = 0.0;

    // MAP: each process calculates its part
    for (long i = rank; i < N; i += size) {
        double x = (i + 0.5) * dx;
        local_pi += 4.0 / (1.0 + x*x) * dx;
    }

    if (rank == 0) {
        // Master collects and sums results
        double pi = local_pi;

        for (int source = 1; source < size; source++) {
            double received;
            MPI_Recv(&received, 1, MPI_DOUBLE,
                     source, 0, MPI_COMM_WORLD,
                     MPI_STATUS_IGNORE);

            pi += received;
        }

        printf("Pi = %.12f\n", pi);

    } else {
        // Workers send their results to master
        MPI_Send(&local_pi, 1, MPI_DOUBLE,
                 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

