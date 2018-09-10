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

//创建循环链表(链式存储)
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

//添加节点
CircleLinkedListNode* insertCircleLinkedList(CircleLinkedList*  list, CircleLinkedListNode *node, unsigned int pos)
{
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("insertCircleLinkedList参数错误\n");
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
	//表示是头插法
//	if (current == &(tlist->header))
//	{
		CircleLinkedListNode *last = circleLinkedListGet(list, tlist->length - 1);
		last->next = tlist->header.next;
//	}
	return node;
}


//获取节点
CircleLinkedListNode* circleLinkedListGet(CircleLinkedList*  list, unsigned int pos)
{
	if (list == NULL || pos < 0)
	{
		printf("circleLinkedListGet参数错误\n");
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

//清除链表
int clearCircleLinkedList(CircleLinkedList*  list)
{
	if (list == NULL)
	{
		printf("clearCircleLinkedList参数错误\n");
		return -1;
	}
	TCircleList *tlist = (TCircleList *)list;
	tlist->length = 0;
	tlist->silder = NULL;
	tlist->header.next = NULL;
	return 0;
}

//删除节点
CircleLinkedListNode* deleteCircleLinkedListNode(CircleLinkedList*  list, unsigned int pos)
{
	if (list == NULL || pos < 0)
	{
		printf("deleteCircleLinkedListNode参数错误\n");
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


//根据节点的值删除节点
CircleLinkedListNode* deleteByNodeValue(CircleLinkedList *list, CircleLinkedListNode *node)
{
	if (list == NULL || node == NULL)
	{
		printf("deleteByNodeValue 参数错误\n");
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

//销毁链表
int destoryCircleLinkedList(CircleLinkedList*  list)
{
	if (list == NULL)
	{
		printf("destoryCircleLinkedList参数错误\n");
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

//获取链表长度
int circleLinkedListLength(CircleLinkedList*  list)
{
	if (list == NULL)
	{
		printf("circleLinkedListLength参数错误\n");
		return -1;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	return tlist->length;
}

//获取下一个元素
CircleLinkedListNode * circle_next(CircleLinkedList *list)
{
	if (list == NULL)
	{
		printf("circle_next参数错误\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	CircleLinkedListNode *node = NULL;
	node = tlist->silder;
	tlist->silder = node->next;
	return node->next;
}

//获取当前元素
CircleLinkedListNode * circle_current(CircleLinkedList *list)
{
	if (list == NULL)
	{
		printf("circle_current参数错误\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;

	return tlist->header.next;
}

//重置游标到第第一个元素
CircleLinkedListNode* circle_resize(CircleLinkedList *list)
{
	if (list == NULL)
	{
		printf("circle_resize参数错误\n");
		return NULL;
	}
	TCircleList *tlist = NULL;
	tlist = (TCircleList *)list;
	tlist->silder = tlist->header.next;
	return tlist->silder;
}