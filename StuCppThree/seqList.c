#include "seqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TSeqList 
{
	unsigned int length;
	int capacity;
	unsigned int *node;
}TSeqList;

//�������Ա�
SeqList* createList( int capacity)
{
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)malloc(sizeof(TSeqList));
	if (tlist == NULL)
	{
		printf("createList-> malloc tlist error \n");
		return NULL;
	}

	memset(tlist, 0, sizeof(TSeqList));

	if (capacity <= 0)
	{
		capacity = 10;
	}

	tlist->node = (unsigned int *)malloc(sizeof(unsigned int )*capacity);
	if (tlist->node == NULL)
	{
		printf("createList-> malloc tlist->node error \n");
		return NULL;
	}
	tlist->capacity = capacity;
	tlist->length = 0;
	return  tlist;
}

//����ڵ�
SeqListNode* insertListNode(SeqList* list, SeqListNode* node,unsigned int pos)
{
	if (list == NULL)
	{
		printf("insertListNode��������Ϊ��\n");
		return NULL;
	}
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;


	if (node == NULL)
	{
		printf("insertListNode �ڵ��������Ϊ��\n");
		return NULL;
	}

	if (tlist->length == tlist->capacity)
	{
		printf("insertListNode ��������\n");
		return NULL;
	}
	if (pos >= tlist->length)
	{
		pos = 0;
	}
	for (unsigned int i = tlist->length; i > pos; i--)
	{
		tlist->node[i] = tlist->node[i-1];
	}
	tlist->node[pos] = (unsigned int)node;
	tlist->length++;
	return node;
}


//ɾ���ڵ�
SeqListNode* deleteListNode(SeqList* list, unsigned int pos)
{
	if (list == NULL)
	{
		printf("deleteListNode��������Ϊ��\n");
		return NULL;
	}
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;
	if (pos >= tlist->length)
	{
		printf("deleteListNode pos λ�ò�������\n");
		return NULL;
	}

	SeqListNode* tmp = (SeqListNode *)tlist->node[pos];
	for (unsigned int i = pos; i < tlist->length-1; i++)
	{
		tlist->node[i] = tlist->node[i + 1];
	}
	tlist->length--;
	return tmp;
}


//������Ա�
int clearList(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		printf("clearList��������Ϊ��\n");
		return -1;
	}
	tlist = (TSeqList *)list;
	tlist->length = 0;
	return 0;
}

//�������Ա�
SeqList* destoryList(SeqList* list)
{
	if (list == NULL)
	{
		printf("destoryList��������Ϊ��\n");
		return NULL;
	}
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;
	if (tlist->node != NULL)
	{
		free(tlist->node);
	}
	free(tlist);
	return list;
}

//�鿴�ڵ�
SeqListNode* showListNode(SeqList* list, int pos)
{
	TSeqList *tlist = NULL;
	if (list == NULL || pos < 0)
	{
		printf("showListNode��������\n");
		return NULL;
	}
	tlist = (TSeqList *)list;
	return (SeqListNode *)tlist->node[pos];
}

//��ȡ���Ա���
int listLength(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		printf("listLength��������Ϊ��\n");
		return -1;
	}
	tlist = (TSeqList *)list;
	return tlist->length;
}