#include "circleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TCircleList 
{
	CircleLinkedListNode header;
	CircleLinkedListNode *silder;
	int length;
}TCircleList;

//����ѭ������(��ʽ�洢)
CircleLinkedList* createCircleLinkedList()
{
	TCircleList *list = NULL;
	list = (TCircleList *)malloc(sizeof(TCircleList));
	memset(list, 0, sizeof(TCircleList));
	list->length = 0;
	list->silder = NULL;
	list->header.next = NULL;
	return (CircleLinkedList*)list;
}

//��ӽڵ�
CircleLinkedListNode* insertCircleLinkedList(CircleLinkedList*  list, CircleLinkedListNode *node, unsigned int pos)
{
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("insertCircleLinkedList��������\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	CircleLinkedListNode *current = &(tlist->header);
	for (unsigned int i = 0; i < pos &&(current->next!=NULL); i++)
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	if (tlist->length == 0)
	{
		tlist->silder = node;
	}
	tlist->length++;
	//��ʾ��ͷ�巨
//	if (current == &(tlist->header))
//	{
		CircleLinkedListNode *last = circleLinkedListGet(list, tlist->length - 1);
		last->next = tlist->header.next;
//	}
	return node;
}


//��ȡ�ڵ�
CircleLinkedListNode* circleLinkedListGet(CircleLinkedList*  list, unsigned int pos)
{
	if (list == NULL || pos < 0)
	{
		printf("circleLinkedListGet��������\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	CircleLinkedListNode *current = NULL;
	current = &(tlist->header);
	for (unsigned int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	return current->next;
}

//�������
int clearCircleLinkedList(CircleLinkedList*  list)
{
	if (list == NULL)
	{
		printf("clearCircleLinkedList��������\n");
		return -1;
	}
	TCircleList *tlist = (TCircleList *)list;
	tlist->length = 0;
	tlist->silder = NULL;
	tlist->header.next = NULL;
	return 0;
}

//ɾ���ڵ�
CircleLinkedListNode* deleteCircleLinkedListNode(CircleLinkedList*  list, unsigned int pos)
{
	if (list == NULL || pos < 0)
	{
		printf("deleteCircleLinkedListNode��������\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	CircleLinkedListNode *ret = NULL;
	tlist = (TCircleList *)list;
	CircleLinkedListNode *current = &(tlist->header);
	for (unsigned int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	ret = current->next;
	current->next = ret->next;
	tlist->length--;
	return ret;
}


//���ݽڵ��ֵɾ���ڵ�
CircleLinkedListNode* deleteByNodeValue(CircleLinkedList *list, CircleLinkedListNode *node)
{
	if (list == NULL || node == NULL)
	{
		printf("deleteByNodeValue ��������\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	CircleLinkedListNode *current = NULL;
	current = &(tlist->header);
	for (unsigned int i = 0; i < tlist->length; i++)
	{
		if (current == node)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

//��������
int destoryCircleLinkedList(CircleLinkedList*  list)
{
	if (list == NULL)
	{
		printf("destoryCircleLinkedList��������\n");
		return -1;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	tlist->length = 0;
	tlist->silder = NULL;
	tlist->header.next = NULL;
	free(tlist);
	tlist = NULL;
	return 0;
}

//��ȡ������
int circleLinkedListLength(CircleLinkedList*  list)
{
	if (list == NULL)
	{
		printf("circleLinkedListLength��������\n");
		return -1;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	return tlist->length;
}

//��ȡ��һ��Ԫ��
CircleLinkedListNode * circle_next(CircleLinkedList *list)
{
	if (list == NULL)
	{
		printf("circle_next��������\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	CircleLinkedListNode *node = NULL;
	node = tlist->silder;
	tlist->silder = node->next;
	return node->next;
}

//��ȡ��ǰԪ��
CircleLinkedListNode * circle_current(CircleLinkedList *list)
{
	if (list == NULL)
	{
		printf("circle_current��������\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;

	return tlist->header.next;
}

//�����α굽�ڵ�һ��Ԫ��
CircleLinkedListNode* circle_resize(CircleLinkedList *list)
{
	if (list == NULL)
	{
		printf("circle_resize��������\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	tlist->silder = tlist->header.next;
	return tlist->silder;
}