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

//�������е���ʽ�洢
LinkedQueue* createLinkedQueue()
{
	LinkedQueue*  queue = (LinkedQueue* )createLinkList();
	return queue;
}


//���ٶ���
void destroyLinkedQueue(LinkedQueue* queue)
{
	destoryLinkList((LinkedList *)queue);
}

//��ն���
void clearLinkedQueue(LinkedQueue* queue)
{
	//��Ҫ�ͷŶ�����ÿ��Ԫ�ص��ڴ�
	while (lenLinkedQueue(queue)>0)
	{
		popLinkedQueue(queue);
	}
	clearLinkList((LinkedList *)queue);
}

//�����
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

//������
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

//���ض���ͷ��Ԫ��
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

//���г���
int lenLinkedQueue(LinkedQueue* queue)
{
	return linkListLength((LinkedList*)queue);
}