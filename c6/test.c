#include <linux/module.h>
#include <linux/init.h>

#include "common.h"
#include "test_list.h"



static int __init test_init(void)
{
	LOG("Called\n");
	test_list();
	return 0;
}

static void __exit test_exit(void)
{
	LOG("called\n");
}

module_init(test_init);
module_exit(test_exit);
MODULE_AUTHOR("tong");
MODULE_LICENSE("GPL");