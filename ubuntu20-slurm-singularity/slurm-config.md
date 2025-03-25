# Installing Slurm Workload Manager (v23.02.3) from Source on Ubuntu 20.04

This guide describes how to install the Slurm Workload Manager and its authentication component Munge on Ubuntu 20.04 using a source build.

---

## Create Required System Users and Groups
```
# Slurm user and group
groupadd -g 5000 slurm
useradd -M -d /var/lib/slurm -s /sbin/nologin -u 5000 -g slurm slurm

# Munge user and group
groupadd -g 5001 munge
useradd -M -d /var/lib/munge -s /bin/bash -u 5001 -g munge munge

mkdir -p /var/lib/slurm/spool
mkdir -p /var/log/slurm

chown -R slurm:slurm /var/log/slurm
chown -R slurm:slurm /var/lib/slurm
```

## Install Required Packages
```
# Munge and headers
apt -y install munge libmunge-dev

# Build tools
apt -y install build-essential

# D-Bus (required for Slurm systemd integration)
apt -y install libdbus-1-dev
```

## Download and Build Slurm
```
wget https://download.schedmd.com/slurm/slurm-23.02.3.tar.bz2

tar -jxvf slurm-23.02.3.tar.bz2
cd slurm-23.02.3/
./configure
make
make install
```

## Configure Slurm
```
cp /root/slurm-23.02.3/etc/slurm.conf.example /usr/local/etc/slurm.conf

vi /usr/local/etc/slurm.conf
----------------------------
ClusterName=SingularityCluster
SlurmctldHost=ubuntu20
MpiDefault=pmi2
ProctrackType=proctrack/cgroup
ReturnToService=1
SlurmctldPidFile=/var/run/slurmctld.pid
SlurmctldPort=6817
SlurmdPidFile=/var/run/slurmd.pid
SlurmdPort=6818
SlurmdSpoolDir=/var/spool/slurmd
SlurmUser=slurm
StateSaveLocation=/var/spool/slurmctld
SwitchType=switch/none
TaskPlugin=task/affinity,task/cgroup
InactiveLimit=0
Waittime=0
SchedulerType=sched/backfill
SelectType=select/cons_tres
AccountingStorageType=accounting_storage/none
JobCompType=jobcomp/none
JobAcctGatherType=jobacct_gather/none
SlurmctldLogFile=/var/log/slurmctld.log
SlurmdLogFile=/var/log/slurmd.log
NodeName=ubuntu20 CPUs=4 Sockets=1 CoresPerSocket=4 ThreadsPerCore=1 State=UNKNOWN
PartitionName=debug Nodes=ALL Default=YES MaxTime=INFINITE State=UP
----------------------------

mkdir -p /var/spool/slurmctld
chmod 777 /var/spool/slurmctld/
```

## Register Slurm with systemd
```
cd slurm-23.02.3/etc
cp slurmctld.service /etc/systemd/system/
cp slurmd.service /etc/systemd/system/
```

## Enable and Start Services
```
systemctl enable --now munge
systemctl enable --now slurmctld
systemctl enable --now slurmd
```
