#include "linklist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct TLinkedList 
{
	LinkedListNode header;
	int length;
}TLinkedList;

//创建线性表(链式存储)
LinkedList* createLinkList()
{
	TLinkedList *list = NULL;
	list = (TLinkedList *)malloc(sizeof(TLinkedList));
	if (list == NULL)
	{
		printf("createLinkList error\n");
		return NULL;
	}
	memset(list, 0, sizeof(TLinkedList));
	list->length = 0;
	list->header.next = NULL;
	return (LinkedList*)list;
}

//添加节点
LinkedListNode* insertLinkList(LinkedList*  list, LinkedListNode *node, unsigned int pos)
{
	TLinkedList *tlist = NULL;
	LinkedListNode *current = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("insertLinkList 参数错误\n");
		return NULL;
	}
	
	tlist = (TLinkedList *)list;
	current = &(tlist->header);

	for (unsigned int i = 0; i < pos && (current->next!=NULL); i++)
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tlist->length++;
	return node;
}

//获取节点
LinkedListNode* linlistGet(LinkedList*  list,unsigned int pos)
{
	if (list == NULL || pos <0)
	{
		printf("linlistGet error 参数错误\n");
		return NULL;
	}
	TLinkedList *tlist = NULL;
	tlist = (TLinkedList *)list;
	LinkedListNode *current = NULL;
	current = &(tlist->header);
	if (current != NULL)
	{
		for (unsigned int i = 0; i < pos && current->next!=NULL; i++)
		{
			current = current->next;
		}
		return current->next;
	}
	return current;
}

//清除链表
int clearLinkList(LinkedList*  list)
{
	if (list == NULL)
	{
		printf("clearLinkList error 参数错误\n");
		return -1;
	}
	TLinkedList *tlist = NULL;
	tlist = (TLinkedList *)list;
	tlist->length = 0;
	tlist->header.next = NULL;
	return 0;
}

//删除节点
LinkedListNode* deleteLinkListNode(LinkedList*  list, unsigned int pos)
{
	TLinkedList *tlist = NULL;
	LinkedListNode *current = NULL;
	LinkedListNode *tmp = NULL;
	if (list == NULL || pos < 0)
	{
		printf("deleteLinkListNode  error 参数错误\n");
		return NULL;
	}
	
	tlist = (TLinkedList *)list;
	current = &(tlist->header);
	
	for (unsigned int i = 0; i < pos &&(current->next!=NULL); i++)
	{
		current = current->next;
	}
	if (current != NULL && current->next != NULL)
	{
		tmp = current->next;
		current->next = tmp->next;
		tlist->length--;
	}
	return tmp;
}

//销毁链表
int destoryLinkList(LinkedList*  list)
{
	if (list == NULL)
	{
		printf("destoryLinkList  error 参数不能为空\n");
		return -1;
	}

	TLinkedList *tlist = NULL;
	tlist = (TLinkedList *)list;

	tlist->length = 0;
	tlist->header.next = NULL;
	free(tlist);
	tlist = NULL;
	return 0;
}

//获取链表长度
int linkListLength(LinkedList*  list)
{
	if (list == NULL)
	{
		printf("linkListLength error 参数不能为空\n");
		return -1;
	}
	TLinkedList *tlist = NULL;
	tlist = (TLinkedList *)list;
	return tlist->length;
}