// SPDX-License-Identifier: GPL-2.0
/*
 * hello_driver.c - Hello World Kernel Module
 * For Xiaomi Pad 5 Pro (kaldi) - Android Kernel 4.19.x
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Hello World Driver for Xiaomi Pad 5 Pro");
MODULE_VERSION("1.0");

static int __init hello_init(void)
{
    printk(KERN_INFO "hello_driver: Hello World! Module loaded.\n");
    printk(KERN_INFO "hello_driver: Xiaomi Pad 5 Pro kernel module initialized.\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "hello_driver: Goodbye! Module unloaded.\n");
}

module_init(hello_init);
module_exit(hello_exit);
