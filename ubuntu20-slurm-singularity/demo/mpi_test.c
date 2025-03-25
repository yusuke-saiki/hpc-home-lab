#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_HOSTNAME 256

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    char hostname[MAX_HOSTNAME];

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    gethostname(hostname, MAX_HOSTNAME);

    FILE *file_cont = fopen("/etc/container_identity", "r");

    if (file_cont) {
        char identity[MAX_HOSTNAME];
        fgets(identity, MAX_HOSTNAME, file_cont);
        fclose(file_cont);
        printf("Rank %d/%d running inside container! Identity: %s\n", rank, size, identity);
    } else {
        // ホスト側であると明示的にわかる
        printf("Rank %d/%d running on physical host! Hostname: %s\n", rank, size, hostname);
    }

    MPI_Finalize();
    return 0;
}
