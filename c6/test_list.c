#include <linux/slab.h>   // for kmalloc 
#include <linux/kernel.h>  // for sprintf 
#include "test_list.h"


void stack_init(struct stack *stack)
{
	INIT_LIST_HEAD(&stack->in.list);
	INIT_LIST_HEAD(&stack->out.list);
}

int stack_pop(struct stack *stack)
{
	struct node * node;
	int v;
	if(list_empty(&stack->out.list)){
		// copy from in
		list_splice_init(&stack->in.list, &stack->out.list);
	}
	node = list_next_entry(&stack->out, list);
	list_del(&node->list);
	v = node->val;
	kfree(node);
	return v;
}


void stack_push(struct stack *stack, int val)
{
	struct node *node = kmalloc(sizeof(*node), GFP_KERNEL);
	if(!node){
		LOG("kmalloc failed\n");
		return;
	}
	node->val = val;
	list_add(&node->list, &stack->in.list);
}

void stack_destroy(struct stack *stack) 
{
	struct node * node, *n;
	list_for_each_entry_safe(node, n, &stack->in.list, list){
		list_del(&node->list);
		kfree(node);
	}
	list_for_each_entry_safe(node, n, &stack->out.list, list){
		list_del(&node->list);
		kfree(node);
	}
}


int stack_empty(struct stack *stack)
{
	return list_empty(&stack->in.list) && list_empty(&stack->out.list);
}
void stack_dump(struct stack *stack)
{
	char buf[128];  // FIX ME WON'T enough space.
	int n = 0;
	struct node* node;
	LOG("stack internal status\n");
	n += sprintf(buf+n, "in list: ");
	list_for_each_entry(node, &stack->in.list, list){
		n += sprintf(buf + n, "%d ", node->val);
	}
	LOG("in: %s\n", buf);
	n = 0;
	n += sprintf(buf+n, "out list: ");
	list_for_each_entry(node, &stack->out.list, list){
		n += sprintf(buf + n, "%d ", node->val);
	}
	LOG("out: %s\n", buf);
	
}


void test_list(void)
{
	int i = 0;
	struct stack stack;
	stack_init(&stack);
	
	for(i=0; i<10; i++){
		stack_push(&stack, i);
		stack_dump(&stack);
	}
	while(!stack_empty(&stack)){
		stack_pop(&stack);
		stack_dump(&stack);
	}
	stack_destroy(&stack);
}