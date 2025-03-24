## Installing Intel oneAPI on Ubuntu 20.04

These are the steps I followed to install Intel oneAPI components on Ubuntu 20.04.  
This method may evolve as I revisit and refine the setup.

> Note: This is a practical installation log, not an official guide.

### Add Intel GPG key

```
wget -O- https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB \
  | gpg --dearmor \
  | sudo tee /usr/share/keyrings/oneapi-archive-keyring.gpg > /dev/null
```
```
echo "deb [signed-by=/usr/share/keyrings/oneapi-archive-keyring.gpg] https://apt.repos.intel.com/oneapi all main" \
  | sudo tee /etc/apt/sources.list.d/oneAPI.list
apt -y update
```
### Install core compilers and libraries
```
apt -y install intel-oneapi-compiler-dpcpp-cpp-2023.1.0
apt -y install intel-oneapi-ipp-devel
apt -y install intel-oneapi-compiler-fortran-2023.1.0
apt -y install intel-oneapi-mkl-devel-2023.1.0
apt -y install intel-oneapi-mpi
apt -y install intel-oneapi-mpi-devel
```

### Confirm installation size (optional)
```
du -hs /opt/intel/oneapi
du -hs /opt/intel/oneapi/*
```

### Install environment-modules for modulefile management
```
apt -y install environment-modules
```

### Setup Intel modulefiles
```
mkdir -p /home/modulefiles
/opt/intel/oneapi/modulefiles-setup.sh --ignore-latest --output-dir=/home/modulefiles/intel
source /etc/profile.d/modules.sh
module use /home/modulefiles/intel
module avail
```

### Symlink latest versions (optional but useful)
```
ln -s /opt/intel/oneapi/compiler/2023.1.0/modulefiles/compiler /home/modulefiles/intel/compiler/latest
ln -s /opt/intel/oneapi/mpi/2021.14/etc/modulefiles/mpi /home/modulefiles/intel/mpi/latest
```

### Add module loads to .bashrc
```
echo 'module use /home/modulefiles/intel' >> ~/.bashrc
echo 'module load compiler/latest' >> ~/.bashrc
echo 'module load mpi/latest' >> ~/.bashrc
echo 'export PATH=/opt/intel/oneapi/compiler/2023.1.0/linux/bin:$PATH' >> ~/.bashrc
. .bashrc
```
