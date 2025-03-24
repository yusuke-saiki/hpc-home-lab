## Environment

### Hardware Specifications
- **Model**: Dell EMC PowerEdge T340
- **CPU**: Intel Xeon E-2124 @ 3.30GHz (4 cores / 4 threads)
- **Memory**: 16 GB DDR4 DIMM (Single-bit ECC)
- **Storage**: 3 x 1TB SATA HDD
- **RAID Controller**: PERC H330
- **RAID Configuration**: RAID-1 (mirrored disks)
- **Remote Management**: iDRAC 9 Enterprise

### Network Configuration
- **IPv4 Address**: 172.16.1.10/24
- **Default Gateway**: 172.16.1.224
- **DNS Servers**: 8.8.8.8, 8.8.4.4

### Patition
- **/boot/efi**: 600MiB
- **/boot**: 1024MiB
- **swap**: 8192MiB
- **/**: All the rest

### OS
```
NAME="Ubuntu"
VERSION="20.04.6 LTS (Focal Fossa)"
ID=ubuntu
ID_LIKE=debian
PRETTY_NAME="Ubuntu 20.04.6 LTS"
VERSION_ID="20.04"
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
VERSION_CODENAME=focal
UBUNTU_CODENAME=focal
```

### Kernel
5.4.0-208-generic
