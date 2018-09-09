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

//创建线性表
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

//插入节点
SeqListNode* insertListNode(SeqList* list, SeqListNode* node,unsigned int pos)
{
	if (list == NULL)
	{
		printf("insertListNode参数不能为空\n");
		return NULL;
	}
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;


	if (node == NULL)
	{
		printf("insertListNode 节点参数不能为空\n");
		return NULL;
	}

	if (tlist->length == tlist->capacity)
	{
		printf("insertListNode 容量已满\n");
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


//删除节点
SeqListNode* deleteListNode(SeqList* list, unsigned int pos)
{
	if (list == NULL)
	{
		printf("deleteListNode参数不能为空\n");
		return NULL;
	}
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;
	if (pos >= tlist->length)
	{
		printf("deleteListNode pos 位置参数错误\n");
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


//清空线性表
int clearList(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		printf("clearList参数不能为空\n");
		return -1;
	}
	tlist = (TSeqList *)list;
	tlist->length = 0;
	return 0;
}

//销毁线性表
SeqList* destoryList(SeqList* list)
{
	if (list == NULL)
	{
		printf("destoryList参数不能为空\n");
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

//查看节点
SeqListNode* showListNode(SeqList* list, int pos)
{
	TSeqList *tlist = NULL;
	if (list == NULL || pos < 0)
	{
		printf("showListNode参数错误\n");
		return NULL;
	}
	tlist = (TSeqList *)list;
	return (SeqListNode *)tlist->node[pos];
}

//获取线性表长度
int listLength(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		printf("listLength参数不能为空\n");
		return -1;
	}
	tlist = (TSeqList *)list;
	return tlist->length;
}