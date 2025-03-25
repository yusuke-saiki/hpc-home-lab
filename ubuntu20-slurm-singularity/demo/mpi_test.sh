#!/bin/bash
#SBATCH --job-name=mpi_container_test
#SBATCH --partition=debug
#SBATCH --nodes=1
#SBATCH --ntasks=4
#SBATCH --cpus-per-task=1

export I_MPI_PMI_LIBRARY=/usr/local/lib/libpmi2.so
export I_MPI_FABRICS=shm:ofi
export I_MPI_OFI_PROVIDER=tcp
export I_MPI_HYDRA_BOOTSTRAP=slurm

# 明確にホストとコンテナに2プロセスずつ割り当てる
srun -n 2 /root/bin/mpi_test &

srun -n 2 singularity exec \
    -B /usr/local/lib:/usr/local/lib \
    -B /var/spool/slurmd:/var/spool/slurmd \
    /opt/singularity/containers/oneapi-mpi.sif /root/bin/mpi_test &

wait
