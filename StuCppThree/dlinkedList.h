#pragma once

/************************************************************************/
/*     ˫������                                                                 */
/************************************************************************/
typedef void DLinkedList;
typedef struct  DLinkedListNode
{
	struct DLinkedListNode *next;
	struct DLinkedListNode *pre;
}DLinkedListNode;


//����˫����������(��ʽ�洢)
DLinkedList* createDLinkedList();

//��ӽڵ�
DLinkedListNode* insertDLinkedList(DLinkedList*  list, DLinkedListNode *node, unsigned int pos);


//��ȡ�ڵ�
DLinkedListNode* dLinkedListGet(DLinkedList*  list, unsigned int pos);

//�������
int clearDLinkedList(DLinkedList*  list);

//����λ��ɾ���ڵ�
DLinkedListNode* deleteDLinkedListNode(DLinkedList*  list, unsigned int pos);

//���ݽڵ��ֵɾ���ڵ�
DLinkedListNode* deleteDlistByNodeValue(DLinkedList *list, DLinkedListNode *node);


//��������
int destoryDLinkedList(DLinkedList*  list);

//��ȡ������
int dLinkedListLength(DLinkedList*  list);

//��ȡ��һ��Ԫ��
DLinkedListNode * dlinklist_next(DLinkedList *list);

//��ȡǰһ��Ԫ��
DLinkedListNode * dlinklist_pre(DLinkedList *list);

//��ȡ��ǰԪ��
DLinkedListNode * dlinklist_current(DLinkedList *list);

//�����α굽�ڵ�һ��Ԫ��
DLinkedListNode* dlinklist_resize(DLinkedList *list);
