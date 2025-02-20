# Kernel drivers

- `modinfo` - see kernel module info.
- `lsmod` - see all loaded kernel modules.
- `insmod` - load the kernel module.
- `rmmod` - remove the kernel module.
- `dmseg` - see the kernel log.
    - `dmseg -W` only prints new incoming logs, also possible to use `-w`.
- `modprobe` - loads module with all its dependencies.
    - Kernel module needs to be in `/lib/modules` to be loaded.

## Character Device

Registering a device driver consists of:

1. Allocate a device number, consists of a major and minor device number.
2. Create character device.
3. Bind the device number to the character device.

We need to implement the file operations like read, write, etc. This is done by adding function pointers,
that realise this functions, into the `struct file_operations` that is passed when registering a device.

When we register a device with a certain `major` device number, we also register/create all the 256 `minor` device numbers.
This numbers are also useable, and call the same kernel module. We need to handle this case, if we wish to use `minor` device numbers.
