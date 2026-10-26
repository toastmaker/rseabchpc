#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int send = rank;
    int recv = -1;
    int other = 1 - rank;

    MPI_Sendrecv(
        &send, 1, MPI_INT, other, 0,
        &recv, 1, MPI_INT, other, 0,
        MPI_COMM_WORLD, MPI_STATUS_IGNORE
    );

    printf("Rank %d received %d from rank %d\n",
           rank, recv, other);

    MPI_Finalize();
    return 0;
}
