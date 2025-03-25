# Installing OpenMPI 4.1.5 with Intel oneAPI Compilers

This document outlines the process of building and installing OpenMPI from source using Intel oneAPI compilers (icx, ifx) on Ubuntu 20.04.

> Version: OpenMPI 4.1.5  
> Compiler: Intel oneAPI 2023.1 (icx, ifx)

---

## Download OpenMPI Source
```
wget https://download.open-mpi.org/release/open-mpi/v4.1/openmpi-4.1.5.tar.bz2
```

## Extract and Build
```
apt -y install lbzip2
tar xf openmpi-4.1.5.tar.bz2
cd openmpi-4.1.5/
```

# Configure with Intel compilers
```
CC=icx CXX=icpx FC=ifx ./configure --without-verbs --prefix=/opt/openmpi-4.1.5_icx-2023.1
```

# Build and install
```
make -j 20
make check
sudo make install
```

## Create a Modulefile for OpenMPI
```
mkdir -p /home/modulefiles/openmpi
cat << EOF > /home/modulefiles/openmpi/4.1.5_icx-2023.1
#%Module1.0
##
## OpenMPI 4.1.5 (Intel oneAPI Compiler 2023.1)
##

# Set paths
prepend-path PATH /opt/openmpi-4.1.5_icx-2023.1/bin
prepend-path LD_LIBRARY_PATH /opt/openmpi-4.1.5_icx-2023.1/lib
prepend-path MANPATH /opt/openmpi-4.1.5_icx-2023.1/share/man

# Set environment variables
setenv OMPI_HOME /opt/openmpi-4.1.5_icx-2023.1
setenv MPI_HOME /opt/openmpi-4.1.5_icx-2023.1
setenv OPAL_PREFIX /opt/openmpi-4.1.5_icx-2023.1
EOF
```

## Load the Module
```
module use /home/modulefiles/openmpi
module load openmpi/4.1.5_icx-2023.1
```

## Final .bashrc (Excerpt)
```
module use /home/modulefiles/intel
module load compiler/latest
module load mpi/latest
# module load openmpi/4.1.5_icx-2023.1

export PATH=/opt/intel/oneapi/compiler/2023.1.0/linux/bin:$PATH
export LD_LIBRARY_PATH=/opt/intel/oneapi/compiler/2023.1.0/linux/compiler/lib/intel64_lin:$LD_LIBRARY_PATH
```
