#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqStack.h"
#include "linkstack.h"



int main05001(int argc, char *argv[])
{
	
	SeqStack *stack = createSeqStack(10);
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		pushSeqStack(stack, &a[i]);
	}

	printf("栈大小: %d\n", seqStackSize(stack));
	for (int i = 0; i < 10; i++)
	{
		int *tmp = (int *)topSeqStack(stack);
		popSeqStack(stack);
		printf("%d\n", *tmp);
	}
	printf("栈大小: %d\n", seqStackSize(stack));
	return 0;
}

int main05002(int argc, char *argv[])
{
	LinkedStack *stack = createLinkedStack();

	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		int *tmp = (int *)pushLinkedStack(stack, &a[i]);
		printf("添加的元素为:%d \n", *tmp);
	}
	printf("linkedStackSize栈大小: %d\n", linkedStackSize(stack));
	for (int i = 0; i < 10; i++)
	{
		int *tmp = (int *)topLinkedStack(stack);
		printf("遍历的栈顶元素为: %d\n", *tmp);
		tmp = (int *)popLinkedStack(stack);
		printf("弹出的栈顶元素为: %d\n", *tmp);
	}
	printf("linkedStackSize栈大小: %d\n", linkedStackSize(stack));

	printf("第二次添加----------------\n");
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		int *tmp = (int *)pushLinkedStack(stack, &a[i]);
		printf("第二次添加的元素为:%d \n", *tmp);
	}
	printf("第二次添加linkedStackSize栈大小: %d\n", linkedStackSize(stack));
	clearLinkedStack(stack);
	//destoryLinkedStack(stack);
	printf("第二次添加linkedStackSize栈大小: %d\n", linkedStackSize(stack));
	destoryLinkedStack(stack);
	return 0;
}
