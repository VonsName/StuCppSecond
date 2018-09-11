#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dlinkedList.h"

typedef struct TDLinkedList 
{
	DLinkedListNode header;
	DLinkedListNode *slider;
	int length;
}TDLinkedList;

//����˫����������(��ʽ�洢)
DLinkedList* createDLinkedList()
{
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)malloc(sizeof(TDLinkedList));
	memset(tlist, 0, sizeof(TDLinkedList));
	tlist->header.next = NULL;
	tlist->header.pre = NULL;
	tlist->slider = NULL;
	return (DLinkedList*)tlist;
}

//��ӽڵ�
DLinkedListNode* insertDLinkedList(DLinkedList*  list, DLinkedListNode *node, unsigned int pos)
{
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("insertDLinkedList ��������\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	DLinkedListNode *current = NULL;
	DLinkedListNode *next = NULL;
	
	tlist = (TDLinkedList *)list;
	current = &(tlist->header);
	for (unsigned int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	next = current->next;
	node->next = current->next;
	current->next = node;
	if (next != NULL)
	{
		next->pre = node;
	}
	node->pre = current->pre;
	tlist->length++;
	return node;
}


//��ȡ�ڵ�
DLinkedListNode* dLinkedListGet(DLinkedList*  list, unsigned int pos)
{
	if (list == NULL || pos <0)
	{
		printf("dLinkedListGet ��������\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	DLinkedListNode *current = NULL;
	current = &(tlist->header);
	for (unsigned int i = 0; i < pos ; i++);
	{
		current = current->next;
	}
	return current;
}

//�������
int clearDLinkedList(DLinkedList*  list)
{
	if (list == NULL)
	{
		printf("clearDLinkedList ��������\n");
		return -1;
	}
	TDLinkedList *tlist = NULL;
	tlist = (DLinkedList *)list;
	tlist->length = 0;
	tlist->header.next = NULL;
	tlist->slider = NULL;
	return 0;
}

//����λ��ɾ���ڵ�
DLinkedListNode* deleteDLinkedListNode(DLinkedList*  list, unsigned int pos)
{
	if (list == NULL || pos)
	{
		printf("deleteDLinkedListNode ��������\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (DLinkedList *)list;
	DLinkedListNode *current = NULL;
	DLinkedListNode *ret = NULL;
	DLinkedListNode *next = NULL;
	current = &(tlist->header);
	for (unsigned int i = 0; i < pos && (current->next != NULL); i++);
	{
		current = current->next;
	}
	ret = current->next;
	current->next = ret->next;
	next = ret->next;
	if (next != NULL)
	{
		next->pre = ret->pre;
	}
	tlist->length--;
	if (tlist->length == 0)
	{
		tlist->header.next = NULL;
		tlist->slider = NULL;
	}
	return ret;
}

//���ݽڵ��ֵɾ���ڵ�
DLinkedListNode* deleteDlistByNodeValue(DLinkedList *list, DLinkedListNode *node)
{
	if (list == NULL || node == NULL)
	{
		printf("deleteDlistByNodeValue ��������\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	DLinkedListNode *current = NULL;
	DLinkedListNode *ret = NULL;
	DLinkedListNode *next = NULL;
	current = &(tlist->header);
	unsigned int i = 0;
	for ( i = 0; i < tlist->length; i++)
	{
		if (node == current->next)
		{
			ret = current->next;
			break;
		}
		current = current->next;
	}
	if (ret != NULL)
	{
		deleteDLinkedListNode(list, i);
		/*next = ret->next;
		current->next = ret->next;
		if (next != NULL)
		{
			next->pre = ret->pre;
		}
		return ret;*/
	}
	return NULL;
}


//��������
int destoryDLinkedList(DLinkedList*  list)
{
	if (list == NULL)
	{
		printf("destoryDLinkedList��������\n");
		return -1;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	tlist->length = 0;
	tlist->slider = NULL;
	tlist->header.next = NULL;
	free(tlist);
	tlist = NULL;
	return 0;
}

//��ȡ������
int dLinkedListLength(DLinkedList*  list)
{
	if (list == NULL)
	{
		printf("dLinkedListLength ��������\n");
		return -1;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	return tlist->length;
}

//��ȡ��һ��Ԫ��
DLinkedListNode * dlinklist_next(DLinkedList *list)
{
	if (list == NULL)
	{
		printf("dlinklist_next��������\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	DLinkedListNode *ret = NULL;
	ret = tlist->slider;
	tlist->slider = ret->next;
	return ret;
}

//��ȡǰһ��Ԫ��
DLinkedListNode * dlinklist_pre(DLinkedList *list)
{
	if (list == NULL)
	{
		printf("dlinklist_pre��������\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	DLinkedListNode *ret = NULL;
	ret = tlist->slider;
	tlist->slider = ret->pre;
	return ret;
}

//��ȡ��ǰԪ��
DLinkedListNode * dlinklist_current(DLinkedList *list)
{
	if (list == NULL)
	{
		printf("dlinklist_current��������\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	if (tlist == NULL)
	{
		return NULL;
	}
	return tlist->slider;
}

//�����α굽�ڵ�һ��Ԫ��
DLinkedListNode* dlinklist_resize(DLinkedList *list)
{
	if (list == NULL)
	{
		printf("dlinklist_resize��������\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	tlist->slider = tlist->header.next;
	return tlist->slider;
}