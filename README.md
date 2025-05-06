# hpc-home-lab
HPC cluster setup guides and configurations for a home lab environment.

## Overview
This repository describes the setup and configuration of a home lab HPC cluster using RHEL and Ubuntu-based systems. 
Included are practical deployment examples including CUDA, Intel oneAPI, OpenMPI, InfiniBand networking, and job schedulers such as Slurm. 
The goal of this book is to provide infrastructure-level guidance to engineers and researchers experimenting with HPC in non-production environments.

## Features / Highlights
- 2-node HPC cluster on Rocky Linux 9 using Intel oneAPI, OpenMPI, Slurm, and InfiniBand
- Container-based HPC environment on Rocky Linux 9 using Intel oneAPI, OpenMPI, Slurm, Singularity
- Single node on Ubuntu 24 with NVIDIA proprietary drivers, CUDA Toolkit, and Slurm

## Target Environment
- OS:
  - Rocky Linux 9 (for 2-node cluster)
  - Rocky Linux 9 (for container-based setup)
  - Ubuntu 24.04.2 (for CUDA setup)
- HPC Stack:
  - Intel oneAPI (DPC++/MPI)
  - Job Schedulers: Slurm
  - Container: Singularity
  - Network: InfiniBand (Mellanox)
  - NVIDIA proprietary drivers
  - CUDA Toolkit

## Directory Structure
```
hpc-home-lab/
├── rocky9-slurm/                         # 2-node HPC cluster on Rocky Linux 9 with Slurm
│   ├── setup-guide.md                    # Overall procedure for building the cluster
│   ├── os-setup.md                       # Base OS configuration and tuning
│   ├── intel-oneapi-install.md           # Intel oneAPI installation (Base + HPC)
│   ├── slurm-config.md                   # Slurm configuration and examples
│   ├── infiniband-usage.md               # InfiniBand setup and usage on Rocky 8
│   ├── demo/                             # Slurm job submission examples (WIP)
│   │   ├── 
│   │   └── 
│   └── sample-configs/                   # Slurm configuration files (WIP)
│       ├── slurm.conf
│       ├── slurmdbd.conf
│       └── cgroup.conf
├── rocky 9-slurm-singularity/            # Container-based HPC node with Slurm on Rocky Linux 9
│   ├── setup-guide.md                    # Overview and full setup flow
│   ├── intel-oneapi-install.md           # Intel oneAPI installation steps
│   ├── slurm-install.md                  # Slurm workload manager installation from source
│   ├── slurm-config.md                   # slurm.conf configuration examples
│   ├── singularity-usage.md              # Singularity container build & usage with oneAPI
│   ├── demo/                             # Slurm job submission examples (WIP)
│   │   ├── 
│   │   └── 
│   └── sample-configs/                   # Slurm configuration files (WIP)
│       ├── slurm.conf
│       ├── slurmdbd.conf
│       ├── cgroup.conf
│       └── oneapi-mpi.def                
├── ubuntu 24-CUDA-Slurm/                 # Single node on Ubuntu 24 with NVIDIA proprietary drivers, CUDA Toolkit, and Slurm
│   ├── setup-guide.md                    # Overview and full setup flow
│   ├── nvidia-drivers-install.md         # NVIDIA proprietary drivers installation steps
│   ├── cuda-install.md                   # CUDA Toolkit installation steps
│   ├── slurm-install.md                  # Slurm workload manager installation from source
│   ├── slurm-config.md                   # slurm.conf configuration examples
│   ├── demo/                             # Slurm job submission examples (WIP)
│   │   ├── 
│   │   └── 
│   └── sample-configs/                   # Slurm configuration files (WIP)
│       ├── slurm.conf
│       ├── slurmdbd.conf
│       ├── gres.conf
│       └── cgroup.conf
├── common/                               # Shared tuning notes and reusable configs
│   └── tuning-notes.md
└── LICENSE
```

## How to Use
Each subdirectory provides step-by-step setup guides (setup-guide.md) and configuration files.
This repository is intended for learning, experimentation, and reference in home or lab environments.
Please adapt configurations based on your own hardware and software environment.

## License
Apache 2.0

## Author
[yusuke-saiki](https://github.com/yusuke-saiki)
