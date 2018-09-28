//qudong
#include
#include
#include
MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
	printk("<1> hello world!\n");
	return 0;
}

static int hello_exit(void)
{
	printk("<1> bye,cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

