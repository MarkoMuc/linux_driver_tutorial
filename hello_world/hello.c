#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void) {
    // This writes to the kernel log, since there is no stdout
    printk("Hello kernel\n");
    return 0;
}

static void __exit my_exit(void) {
    printk("Goodbye kernel\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MZM");
MODULE_DESCRIPTION("HELLO WORLD");
