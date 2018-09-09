#pragma once

typedef void SeqList;
typedef void SeqListNode;

//�������Ա�
SeqList* createList( int capacity);

//����ڵ�
SeqListNode* insertListNode(SeqList* list, SeqListNode* node, unsigned int pos);

//ɾ���ڵ�
SeqListNode* deleteListNode(SeqList* list, unsigned int pos);

//������Ա�
int clearList(SeqList* list);

//�������Ա�
SeqList* destoryList(SeqList* list);

//�鿴�ڵ�
SeqListNode* showListNode(SeqList* list, int pos);

//��ȡ���Ա���
int listLength(SeqList* list);


