# hpc-home-lab
HPC cluster setup guides and configurations for a home lab environment.

## Overview
This repository documents the setup and configuration of home lab HPC clusters using RHEL and Ubuntu-based systems.  
It includes practical deployment examples involving Intel oneAPI, OpenMPI, InfiniBand networking, and job schedulers such as UGE and Slurm.  
The goal is to provide infrastructure-level guidance for engineers and researchers experimenting with HPC in non-production environments.

## Features / Highlights
- 2-node HPC cluster on RHEL 8 using Intel oneAPI, OpenMPI, UGE, and InfiniBand
- Container-based HPC environment on Ubuntu 20.04 using Intel oneAPI, Slurm, and Singularity
- Includes installation procedures, OS-level tuning, scheduler configs, and usage examples

## Target Environment
- OS:
  - RHEL 8 / Rocky Linux 8 (for 2-node cluster)
  - Ubuntu Server 20.04 (for container-based setup)
- HPC Stack:
  - Intel oneAPI (DPC++/MPI)
  - OpenMPI
  - Job Schedulers: UGE / Slurm
  - Container: Singularity
  - Network: InfiniBand (Mellanox)

## Directory Structure
```
## Directory Structure
```bash
## Directory Structure
```bash
hpc-home-lab/
├── rocky8-uge/                           # 2-node HPC cluster on Rocky Linux 8 with UGE
│   ├── setup-guide.md                    # Overall procedure for building the cluster
│   ├── os-setup.md                       # Base OS configuration and tuning
│   ├── intel-oneapi-install.md           # Intel oneAPI installation (Base + HPC)
│   ├── openmpi-install.md                # OpenMPI build instructions using oneAPI compilers
│   ├── uge-config.md                     # UGE (Univa Grid Engine) configuration and examples
│   ├── infiniband-usage.md               # InfiniBand setup and usage on Rocky 8
│   ├── demo/                             # UGE job submission examples (WIP)
│   │   └── .gitkeep
│   └── sample-configs/                   # UGE configuration files (WIP)
│       └── .gitkeep
├── ubuntu20-slurm-singularity/           # Container-based HPC node with Slurm on Ubuntu 20.04
│   ├── setup-guide.md                    # Overview and full setup flow
│   ├── intel-oneapi-install.md           # Intel oneAPI installation steps
│   ├── openmpi-install.md                # OpenMPI build instructions using icx/ifx
│   ├── slurm-install.md                  # Slurm workload manager installation from source
│   ├── slurm-config.md                   # slurm.conf configuration examples
│   ├── singularity-usage.md              # Singularity container build & usage with oneAPI
│   ├── demo/                             # MPI program + Slurm batch script for test runs
│   │   ├── mpi_test.c
│   │   └── mpi_test.sh
│   └── sample-configs/                   # Real config files used in actual deployment
│       ├── slurm.conf
│       ├── oneapi-mpi.def
│       └── 4.1.5_icx-2023.1              # OpenMPI modulefile for icx (plain text)
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
