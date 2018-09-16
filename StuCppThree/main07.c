#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqQueue.h"
#include "linkedQueue.h"
/************************************************************************/
/* 队列的顺序存储,线性表的尾部入队,头部出队                                                                     */
/************************************************************************/


int main07001(int argc,char *argv[])
{

	SeqQueue *queue = createSeqDequeue(10);
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		appendSeqQueue(queue, &a[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		int *tmp = (int *)headerSeqQueue(queue);
		if (tmp != NULL)
		{
			printf("tmp= %d \n", *tmp);
		}
		deleteHeader(queue);
	}
	
	return 0;
}


/**
 * 队列的链式存储
 */
int main07002(int argc, char *argv[])
{
	LinkedQueue* queue =  createLinkedQueue();
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		insertLinkedQueue(queue, &a[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		int *tmp = (int *)leftLinkedQueue(queue);
		if (tmp != NULL)
		{
			printf("队列的链式存储->tmp= %d \n", *tmp);
		}
		popLinkedQueue(queue);
	}
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		insertLinkedQueue(queue, &a[i]);
	}
	clearLinkedQueue(queue);
	return 0;
}
