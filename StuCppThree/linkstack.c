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
//����ջ,���Դ洢
LinkedStack *createLinkedStack()
{
	LinkedList* list = createLinkList();
	return (TLinkedStack*)list;
}

//����ջ Ҫ�ͷŽڵ���ڴ�
void destoryLinkedStack(LinkedStack *stack)
{
	if (stack == NULL)
	{
		return;
	}
	clearLinkedStack(stack);
	free(stack);
}

//���ջ Ҫ�ͷŽڵ���ڴ�
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

//ѹջ
void* pushLinkedStack(LinkedStack *stack, void *item)
{
	TLinkedStack *tmp = NULL;
	tmp = (TLinkedStack *)malloc(sizeof(TLinkedStack));
	tmp->item = item;
	LinkedListNode * node = insertLinkList(stack, (LinkedListNode *)tmp, 0);
	return item;
}

//��ջ
void* topLinkedStack(LinkedStack *stack)
{
	LinkedListNode * node = linlistGet(stack, 0);
	return ((TLinkedStack *)node)->item;
}

//ɾ��ջ��Ԫ��
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

//ջ��С
int linkedStackSize(LinkedStack *stack)
{
	return linkListLength(stack);
}

//ջ����
int linkedStackCapacity(LinkedStack *stack)
{
	return 0;
}