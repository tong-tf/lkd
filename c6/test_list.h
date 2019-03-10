#ifndef TEST_LIST_H
#define TEST_LIST_H 

#include <linux/list.h>

#include "common.h"

struct node {
	struct list_head list;
	int val;
};

/**
 * 用两个链表来实现栈的功能
 */
struct stack {
	struct node in;   // 用作插入数据
	struct node out;  // 输出数据
};


extern void stack_init(struct stack *stack);
extern int stack_pop(struct stack *stack);
extern void stack_push(struct stack *stack, int val);
extern void test_list(void);
#endif