#include <linux/module.h>
#include <linux/init.h>

#include "common.h"

static int __init test_init(void)
{
	LOG("Called\n");
	return 0;
}

static void __init test_exit(void)
{
	LOG("called\n");
}

module_init(test_init);
module_exit(test_exit);
MODULE_AUTHOR("tong");
MODULE_LICENSE("GPLv2");