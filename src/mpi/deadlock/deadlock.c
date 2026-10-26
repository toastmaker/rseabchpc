#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int send = rank;
    int recv;

    int other = 1 - rank;

    MPI_Ssend(&send, 1, MPI_INT, other, 0, MPI_COMM_WORLD);
    MPI_Recv(&recv, 1, MPI_INT, other, 0,
             MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    printf("Rank %d received %d\n", rank, recv);

    MPI_Finalize();
    return 0;
}

