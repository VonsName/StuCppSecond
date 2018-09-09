#include "linklist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct TLinkedList 
{
	LinkedListNode header;
	int length;
}TLinkedList;

//�������Ա�(��ʽ�洢)
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

//��ӽڵ�
LinkedListNode* insertLinkList(LinkedList*  list, LinkedListNode *node, unsigned int pos)
{
	TLinkedList *tlist = NULL;
	LinkedListNode *current = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("insertLinkList ��������\n");
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

//��ȡ�ڵ�
LinkedListNode* linlistGet(LinkedList*  list,unsigned int pos)
{
	if (list == NULL || pos <0)
	{
		printf("linlistGet error ��������\n");
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

//�������
int clearLinkList(LinkedList*  list)
{
	if (list == NULL)
	{
		printf("clearLinkList error ��������\n");
		return -1;
	}
	TLinkedList *tlist = NULL;
	tlist = (TLinkedList *)list;
	tlist->length = 0;
	tlist->header.next = NULL;
	return 0;
}

//ɾ���ڵ�
LinkedListNode* deleteLinkListNode(LinkedList*  list, unsigned int pos)
{
	TLinkedList *tlist = NULL;
	LinkedListNode *current = NULL;
	LinkedListNode *tmp = NULL;
	if (list == NULL || pos < 0)
	{
		printf("deleteLinkListNode  error ��������\n");
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

//��������
int destoryLinkList(LinkedList*  list)
{
	if (list == NULL)
	{
		printf("destoryLinkList  error ��������Ϊ��\n");
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

//��ȡ������
int linkListLength(LinkedList*  list)
{
	if (list == NULL)
	{
		printf("linkListLength error ��������Ϊ��\n");
		return -1;
	}
	TLinkedList *tlist = NULL;
	tlist = (TLinkedList *)list;
	return tlist->length;
}