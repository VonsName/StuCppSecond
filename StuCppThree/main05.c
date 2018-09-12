#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqStack.h"



int main(int argc, char *argv[])
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
