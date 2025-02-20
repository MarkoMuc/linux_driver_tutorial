#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

const char* label = "chardev";
static ssize_t my_read(struct file *f, char __user *u, size_t l, loff_t *o) {
    printk("Read was called");
    return 0;
}
static int major;
// What file operations are supported
static struct file_operations fops = {
    .read = my_read
};

static int __init my_init(void) {
    // label appears in proc devices
    major = register_chrdev(0, label, &fops);
    if (major<0) {
        printk("Error registering chrdev.\n");
        return major;
    }
    printk("hello_cdev number : %d\n", major);
    return 0;
}

static void __exit my_exit(void) {
    unregister_chrdev(major, label);
    printk("Goodbye kernel\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MZM");
MODULE_DESCRIPTION("Sample driver for registering a character device.");
