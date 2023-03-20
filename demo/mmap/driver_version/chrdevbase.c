#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
 
char readbuf[100] = "Hello App\n";
char writebuf[100];
 
int chrdevbase_open(struct inode* inode, struct file* filp) {
    printk("chrdevbase_open\n");
    return 0;
}
 
int chrdevbase_release(struct inode *inode, struct file *filp) {
    printk("chrdevbase_release\n");
    return 0;
}
 
ssize_t chrdevbase_read(struct file* file, char __user* buf, size_t count, loff_t* ppos) {
    printk("chrdevbase_read: cnt = %d, %s\n", count, readbuf);
    int ret = -1;
    ret = copy_to_user(buf, readbuf, count <= sizeof(readbuf) ? count : sizeof(readbuf));
    if (ret)    printk("copy_to_user error\n");

    //printk("chrdevbase_read X\n");
    return 0;
}
 
ssize_t chrdevbase_write(struct file* file, const char __user* buf, size_t count, loff_t* ppos) {
    int ret = -1;
    ret = copy_from_user(writebuf, buf, count <= sizeof(writebuf) ? count : sizeof(writebuf));
    if (ret)    printk("copy_from_user error\n");
    else        printk("%s", writebuf);
 
    return 0;
}
 
const struct file_operations chrdevbase_fops = {
    .owner = THIS_MODULE,
    .open = chrdevbase_open,
    .release = chrdevbase_release,
    .read = chrdevbase_read,
    .write = chrdevbase_write,
};
 
static int __init chrdevbase_init(void) {
    int ret = -1;
    ret = register_chrdev(200, "chrdevbase", &chrdevbase_fops);
    if (ret < 0)    printk("register_chrdev failed\n");
 
    printk("chrdevbase_init\n");
    return 0;
}
 
static void __exit chrdevbase_exit(void) {
    unregister_chrdev(200, "chrdevbase");
    printk("chrdevbase_exit\n");
}
 
module_init(chrdevbase_init);
module_exit(chrdevbase_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("shawn");