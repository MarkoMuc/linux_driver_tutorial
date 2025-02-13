# Kernel drivers

- `modinfo` - see kernel module info.
- `lsmod` - see all loaded kernel modules.
- `insmod` - load the kernel module.
- `rmmod` - remove the kernel module.
- `dmseg` - see the kernel log.
    - `dmseg -W` only prints new incoming logs, also possible to use `-w`.
- `modprobe` - loads module with all its dependencies.
    - Kernel module needs to be in `/lib/modules` to be loaded.
