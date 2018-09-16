#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedQueue.h"
#include "linklist.h"


typedef struct TLinkedQueue 
{
	struct LinkedListNode node;
	void* item;
}TLinkedQueue;

//创建队列的链式存储
LinkedQueue* createLinkedQueue()
{
	LinkedQueue*  queue = (LinkedQueue* )createLinkList();
	return queue;
}


//销毁队列
void destroyLinkedQueue(LinkedQueue* queue)
{
	destoryLinkList((LinkedList *)queue);
}

//清空队列
void clearLinkedQueue(LinkedQueue* queue)
{
	//先要释放队列里每个元素的内存
	while (lenLinkedQueue(queue)>0)
	{
		popLinkedQueue(queue);
	}
	clearLinkList((LinkedList *)queue);
}

//入队列
void* insertLinkedQueue(LinkedQueue* queue, void *item)
{
	TLinkedQueue *tmp = NULL;
	tmp = (TLinkedQueue *)malloc(sizeof(TLinkedQueue));
	if (tmp ==NULL)
	{
		return NULL;
	}
	memset(tmp, 0, sizeof(TLinkedQueue));
	tmp->item = item;
	insertLinkList((LinkedList *)queue, (LinkedListNode*)tmp, lenLinkedQueue(queue));
	//if (tmp != NULL)
	//{
	//	free(tmp);
	//	tmp = NULL;
	//}
	return tmp;
}

//出队列
void* popLinkedQueue(LinkedQueue* queue)
{
	TLinkedQueue *tmp = NULL;
	tmp =	(TLinkedQueue *)deleteLinkListNode((LinkedList*)queue, 0);
	void* item = NULL;
	if (tmp != NULL)
	{
		item = tmp->item;
		free(tmp);
	}
	return item;
}

//返回队列头部元素
void* leftLinkedQueue(LinkedQueue* queue)
{

	TLinkedQueue *tmp = NULL;
	tmp = (TLinkedQueue *)linlistGet((LinkedList*)queue, 0);
	void* item = NULL;
	if (tmp != NULL)
	{
		item = tmp->item;
	}
	return item;
}

//队列长度
int lenLinkedQueue(LinkedQueue* queue)
{
	return linkListLength((LinkedList*)queue);
}