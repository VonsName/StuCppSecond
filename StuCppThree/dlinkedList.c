#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dlinkedList.h"

typedef struct TDLinkedList 
{
	DLinkedListNode header;
	DLinkedListNode *slider;
	unsigned int length;
}TDLinkedList;

//创建双向链表链表(链式存储)
DLinkedList* createDLinkedList()
{
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)malloc(sizeof(TDLinkedList));
	memset(tlist, 0, sizeof(TDLinkedList));
	tlist->header.next = NULL;
	tlist->header.pre = NULL;
	tlist->slider = NULL;
	tlist->length = 0;
	return (DLinkedList*)tlist;
}

//添加节点
DLinkedListNode* insertDLinkedList(DLinkedList*  list, DLinkedListNode *node, unsigned int pos)
{
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("insertDLinkedList 参数错误\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	DLinkedListNode *current = NULL;
	DLinkedListNode *mynext = NULL;
	
	tlist = (TDLinkedList *)list;
	current = &(tlist->header);

	for (unsigned int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	mynext = current->next;
	node->next = current->next;
	current->next = node;
	if (tlist->length == 0)
	{
		tlist->slider = node;
	}

	if (mynext != NULL)
	{
		mynext->pre = node;
	}
	node->pre = current->pre;
	tlist->length++;
	return node;
}


//获取节点
DLinkedListNode* dLinkedListGet(DLinkedList*  list, unsigned  int pos)
{
	if (list == NULL || pos <0)
	{
		printf("dLinkedListGet 参数错误\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	DLinkedListNode *current = NULL;
	current = &(tlist->header);
	unsigned int a = 0;
	for ( a = 0; a < pos  ; a++)
	{
		current = current->next;
	}
	return current->next;
}

//清除链表
int clearDLinkedList(DLinkedList*  list)
{
	if (list == NULL)
	{
		printf("clearDLinkedList 参数错误\n");
		return -1;
	}
	TDLinkedList *tlist = NULL;
	tlist = (DLinkedList *)list;
	tlist->length = 0;
	tlist->header.next = NULL;
	tlist->slider = NULL;
	return 0;
}

//根据位置删除节点
DLinkedListNode* deleteDLinkedListNode(DLinkedList*  list, unsigned int pos)
{
	if (list == NULL || pos)
	{
		printf("deleteDLinkedListNode 参数错误\n");
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

//根据节点的值删除节点
DLinkedListNode* deleteDlistByNodeValue(DLinkedList *list, DLinkedListNode *node)
{
	if (list == NULL || node == NULL)
	{
		printf("deleteDlistByNodeValue 参数错误\n");
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


//销毁链表
int destoryDLinkedList(DLinkedList*  list)
{
	if (list == NULL)
	{
		printf("destoryDLinkedList参数错误\n");
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

//获取链表长度
int dLinkedListLength(DLinkedList*  list)
{
	if (list == NULL)
	{
		printf("dLinkedListLength 参数错误\n");
		return -1;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	return tlist->length;
}

//获取下一个元素
DLinkedListNode * dlinklist_next(DLinkedList *list)
{
	if (list == NULL)
	{
		printf("dlinklist_next参数错误\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	DLinkedListNode *ret = NULL;
	ret = tlist->slider;
	tlist->slider = ret->next;
	return ret;
}

//获取前一个元素
DLinkedListNode * dlinklist_pre(DLinkedList *list)
{
	if (list == NULL)
	{
		printf("dlinklist_pre参数错误\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	DLinkedListNode *ret = NULL;
	ret = tlist->slider;
	tlist->slider = ret->pre;
	return ret;
}

//获取当前元素
DLinkedListNode * dlinklist_current(DLinkedList *list)
{
	if (list == NULL)
	{
		printf("dlinklist_current参数错误\n");
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

//重置游标到第第一个元素
DLinkedListNode* dlinklist_resize(DLinkedList *list)
{
	if (list == NULL)
	{
		printf("dlinklist_resize参数错误\n");
		return NULL;
	}
	TDLinkedList *tlist = NULL;
	tlist = (TDLinkedList *)list;
	tlist->slider = tlist->header.next;
	return tlist->slider;
}