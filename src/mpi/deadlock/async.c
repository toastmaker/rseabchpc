#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int send = rank;
    int recv = -1;
    int other = 1 - rank;

    MPI_Request req[2];

    MPI_Irecv(&recv, 1, MPI_INT, other, 0,
              MPI_COMM_WORLD, &req[0]);

    MPI_Isend(&send, 1, MPI_INT, other, 0,
              MPI_COMM_WORLD, &req[1]);

    MPI_Waitall(2, req, MPI_STATUSES_IGNORE);

    printf("Rank %d received %d from rank %d\n",
           rank, recv, other);

    MPI_Finalize();
    return 0;
}
