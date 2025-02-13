#include <linux/module.h>
#include <linux/init.h>

int my_init(void) {
    // This writes to the kernel log, since there is no stdout
    printk("Hello kernel\n");
    return 0;
}

void my_exit(void) {
    printk("Goodbye kernel\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
