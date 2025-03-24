# Installing and Using Singularity with Intel oneAPI (Ubuntu 20.04)

This guide documents the installation of Singularity CE v3.10.4 and the creation of a container that includes Intel oneAPI tools for HPC workloads.

---

## Install Required Packages

```
apt update && apt install -y \
    squashfs-tools \
    cryptsetup \
    wget \
    git \
    build-essential \
    libseccomp-dev \
    pkg-config
```

## Install Singularity CE from Prebuilt .deb Package
```
wget https://github.com/sylabs/singularity/releases/download/v3.10.4/singularity-ce_3.10.4-focal_amd64.deb

mkdir singularity
mv *.deb singularity
cd singularity

apt-get install ./singularity-ce_3.10.4-focal_amd64.deb
```

## Create Base Image Definition File
```
mkdir -p /opt/singularity/containers
cd /opt/singularity/containers
vi oneapi-mpi.def
-----------------
Bootstrap: docker
From: ubuntu:20.04

%post
    apt update && apt install -y --no-install-recommends \
        wget gnupg lsb-release build-essential ca-certificates bash

    wget -O- https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB \
        | gpg --dearmor | tee /usr/share/keyrings/oneapi-archive-keyring.gpg > /dev/null
    echo "deb [signed-by=/usr/share/keyrings/oneapi-archive-keyring.gpg] https://apt.repos.intel.com/oneapi all main" \
        | tee /etc/apt/sources.list.d/oneAPI.list

    apt update
    apt install -y --no-install-recommends \
        intel-oneapi-compiler-dpcpp-cpp-2023.1.0 \
        intel-oneapi-ipp-devel \
        intel-oneapi-compiler-fortran-2023.1.0 \
        intel-oneapi-mkl-devel-2023.1.0 \
        intel-oneapi-mpi \
        intel-oneapi-mpi-devel

    echo 'export PATH=/opt/intel/oneapi/compiler/2023.1.0/linux/bin:$PATH' >> /etc/profile
    echo 'export LD_LIBRARY_PATH=/opt/intel/oneapi/compiler/2023.1.0/linux/compiler/lib/intel64_lin:$LD_LIBRARY_PATH' >> /etc/profile
    echo 'export PATH=/opt/intel/oneapi/mpi/2021.14/bin:$PATH' >> /etc/profile
    echo 'export LD_LIBRARY_PATH=/opt/intel/oneapi/mpi/2021.14/opt/mpi/libfabric/lib:$LD_LIBRARY_PATH' >> /etc/profile
    echo 'export MPI_HOME=/opt/intel/oneapi/mpi/2021.14' >> /etc/profile
    echo 'export OMPI_HOME=/opt/intel/oneapi/mpi/2021.14' >> /etc/profile
    echo 'export OPAL_PREFIX=/opt/intel/oneapi/mpi/2021.14' >> /etc/profile
    echo 'export I_MPI_FABRICS=shm:ofi' >> /etc/profile
    echo 'export I_MPI_OFI_PROVIDER=tcp' >> /etc/profile

    echo "sif20" > /etc/container_identity

%environment
    export PATH=/opt/intel/oneapi/compiler/2023.1.0/linux/bin:$PATH
    export LD_LIBRARY_PATH=/opt/intel/oneapi/compiler/2023.1.0/linux/compiler/lib/intel64_lin:$LD_LIBRARY_PATH
    export PATH=/opt/intel/oneapi/mpi/2021.14/bin:$PATH
    export LD_LIBRARY_PATH=/opt/intel/oneapi/mpi/2021.14/opt/mpi/libfabric/lib:$LD_LIBRARY_PATH
    export MPI_HOME=/opt/intel/oneapi/mpi/2021.14
    export OMPI_HOME=/opt/intel/oneapi/mpi/2021.14
    export OPAL_PREFIX=/opt/intel/oneapi/mpi/2021.14
    export I_MPI_FABRICS=shm:ofi
    export I_MPI_OFI_PROVIDER=tcp

%runscript
    exec /bin/bash
-----------------
```

## Build the Container
```
singularity build oneapi-mpi.sif oneapi-mpi.def
```

## Test the Container
```
singularity shell oneapi-mpi.sif
icx --version
mpirun --version
mpiicx --version
exit
```
