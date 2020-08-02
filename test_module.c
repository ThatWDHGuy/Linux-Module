#include <linux/init.h>
#include <linux/module.h>

int test_module_init(void){
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	return 0;
}

void test_module_exit(void){
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}

module_init(test_module_init);
module_exit(test_module_exit);

