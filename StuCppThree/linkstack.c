#include "linkstack.h"
#include "linklist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TLinkedStack 
{
	LinkedListNode node;
	void *item;
}TLinkedStack;
//创建栈,线性存储
LinkedStack *createLinkedStack()
{
	LinkedList* list = createLinkList();
	return (TLinkedStack*)list;
}

//销毁栈 要释放节点的内存
void destoryLinkedStack(LinkedStack *stack)
{
	if (stack == NULL)
	{
		return;
	}
	clearLinkedStack(stack);
	free(stack);
}

//清空栈 要释放节点的内存
void clearLinkedStack(LinkedStack *stack)
{
	if (stack==NULL)
	{
		return;
	}
	while (linkedStackSize(stack)>0)
	{
		popLinkedStack(stack);
	}
}

//压栈
void* pushLinkedStack(LinkedStack *stack, void *item)
{
	TLinkedStack *tmp = NULL;
	tmp = (TLinkedStack *)malloc(sizeof(TLinkedStack));
	tmp->item = item;
	LinkedListNode * node = insertLinkList(stack, (LinkedListNode *)tmp, 0);
	return item;
}

//弹栈
void* topLinkedStack(LinkedStack *stack)
{
	LinkedListNode * node = linlistGet(stack, 0);
	return ((TLinkedStack *)node)->item;
}

//删除栈顶元素
void* popLinkedStack(LinkedStack *stack)
{
	LinkedListNode * node = deleteLinkListNode(stack, 0);
	TLinkedStack *tmp = NULL;
	tmp = (TLinkedStack *)node;
	void *item = NULL;
	item = tmp->item;
	if (tmp!=NULL)
	{
		free(tmp);
		tmp = NULL;
	}
	return item;
}

//栈大小
int linkedStackSize(LinkedStack *stack)
{
	return linkListLength(stack);
}

//栈容量
int linkedStackCapacity(LinkedStack *stack)
{
	return 0;
}