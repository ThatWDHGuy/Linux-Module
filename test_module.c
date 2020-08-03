#include <linux/init.h>
#include <linux/module.h>

#include <linux/fs.h> // for character device driver

int test_open (struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	return 0;
}

ssize_t test_read (struct file *pfile, char __user *buffere, size_t length, loff_t *offset){
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	return 0;
}

ssize_t test_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset){
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	return length;
}

int test_close (struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	return 0;
}

struct file_operations test_module_operations = {
	.owner = THIS_MODULE,
	.open = test_open,
	.read = test_read,
	.write = test_write,
	.release = test_close,
};

int test_module_init(void){
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	
	register_chrdev(222/* major num */,
			"Test Char Dev" /* name */,
			&test_module_operations /* file operations */);

	return 0;
}

void test_module_exit(void){
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	unregister_chrdev(222,"Test Char Dev");
}

module_init(test_module_init);
module_exit(test_module_exit);

