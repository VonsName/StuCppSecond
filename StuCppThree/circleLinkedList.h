#pragma once
/************************************************************************/
/* ѭ������                                                                     */
/************************************************************************/
typedef void CircleLinkedList;
typedef struct  CircleLinkedListNode
{
	struct CircleLinkedListNode *next;
}CircleLinkedListNode;


//����ѭ������(��ʽ�洢)
CircleLinkedList* createCircleLinkedList();

//��ӽڵ�
CircleLinkedListNode* insertCircleLinkedList(CircleLinkedList*  list, CircleLinkedListNode *node, unsigned int pos);


//��ȡ�ڵ�
CircleLinkedListNode* circleLinkedListGet(CircleLinkedList*  list, unsigned int pos);

//�������
int clearCircleLinkedList(CircleLinkedList*  list);

//����λ��ɾ���ڵ�
CircleLinkedListNode* deleteCircleLinkedListNode(CircleLinkedList*  list, unsigned int pos);

//���ݽڵ��ֵɾ���ڵ�
CircleLinkedListNode* deleteByNodeValue(CircleLinkedList *list, CircleLinkedListNode *node);


//��������
int destoryCircleLinkedList(CircleLinkedList*  list);

//��ȡ������
int circleLinkedListLength(CircleLinkedList*  list);

//��ȡ��һ��Ԫ��
CircleLinkedListNode * circle_next(CircleLinkedList *list);

//��ȡ��ǰԪ��
CircleLinkedListNode * circle_current(CircleLinkedList *list);

//�����α굽�ڵ�һ��Ԫ��
CircleLinkedListNode* circle_resize(CircleLinkedList *list);
