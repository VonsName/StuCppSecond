#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqStack.h"
#include "seqList.h"


typedef struct TSeqStack 
{
	int size;
	int *node;
}TSeqStack;

//创建栈,线性存储
SeqStack *createSeqStack(int capacity)
{
	return createList(capacity);
}

//销毁栈
void destorySeqStack(SeqStack *stack)
{
	destoryList(stack);
}

//清空栈
void clearSeqStack(SeqStack *stack)
{
	clearList(stack);
}

//压栈,,相当于在线性表尾部插入元素
void* pushSeqStack(SeqStack *stack, void *item)
{
	return insertListNode(stack,item,listLength(stack));
}

//弹栈,相当于获取线性表尾部元素
void* topSeqStack(SeqStack *stack)
{
	return showListNode(stack,listLength(stack)-1);
}


//删除栈顶元素,相当于删除线性表尾部元素
void* popSeqStack(SeqStack *stack)
{
	return deleteListNode(stack,listLength(stack)-1);
}

//栈大小
int seqStackSize(SeqStack *stack)
{
	return listLength(stack);
}


//栈容量
int seqStackCapacity(SeqStack *stack)
{
	return 0;
}
