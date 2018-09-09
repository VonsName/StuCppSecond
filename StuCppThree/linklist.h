#pragma once

typedef void LinkedList;
typedef struct  LinkedListNode
{
	struct LinkedListNode *next;
}LinkedListNode;

//�������Ա�(��ʽ�洢)
LinkedList* createLinkList();

//��ӽڵ�
LinkedListNode* insertLinkList(LinkedList*  list,LinkedListNode *node, unsigned int pos);


//��ȡ�ڵ�
LinkedListNode* linlistGet(LinkedList*  list,unsigned int pos);

//�������
int clearLinkList(LinkedList*  list);

//ɾ���ڵ�
LinkedListNode* deleteLinkListNode(LinkedList*  list,unsigned int pos);

//��������
int destoryLinkList(LinkedList*  list);

//��ȡ������
int linkListLength(LinkedList*  list);


