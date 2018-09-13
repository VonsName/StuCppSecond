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

	printf("ջ��С: %d\n", seqStackSize(stack));
	for (int i = 0; i < 10; i++)
	{
		int *tmp = (int *)topSeqStack(stack);
		popSeqStack(stack);
		printf("%d\n", *tmp);
	}
	printf("ջ��С: %d\n", seqStackSize(stack));
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
		printf("��ӵ�Ԫ��Ϊ:%d \n", *tmp);
	}
	printf("linkedStackSizeջ��С: %d\n", linkedStackSize(stack));
	for (int i = 0; i < 10; i++)
	{
		int *tmp = (int *)topLinkedStack(stack);
		printf("������ջ��Ԫ��Ϊ: %d\n", *tmp);
		tmp = (int *)popLinkedStack(stack);
		printf("������ջ��Ԫ��Ϊ: %d\n", *tmp);
	}
	printf("linkedStackSizeջ��С: %d\n", linkedStackSize(stack));

	printf("�ڶ������----------------\n");
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		int *tmp = (int *)pushLinkedStack(stack, &a[i]);
		printf("�ڶ�����ӵ�Ԫ��Ϊ:%d \n", *tmp);
	}
	printf("�ڶ������linkedStackSizeջ��С: %d\n", linkedStackSize(stack));
	clearLinkedStack(stack);
	//destoryLinkedStack(stack);
	printf("�ڶ������linkedStackSizeջ��С: %d\n", linkedStackSize(stack));
	destoryLinkedStack(stack);
	return 0;
}
