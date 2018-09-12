#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqStack.h"
#include "seqList.h"


typedef struct TSeqStack 
{
	int size;
	int *node;
}TSeqStack;

//����ջ,���Դ洢
SeqStack *createSeqStack(int capacity)
{
	return createList(capacity);
}

//����ջ
void destorySeqStack(SeqStack *stack)
{
	destoryList(stack);
}

//���ջ
void clearSeqStack(SeqStack *stack)
{
	clearList(stack);
}

//ѹջ,,�൱�������Ա�β������Ԫ��
void* pushSeqStack(SeqStack *stack, void *item)
{
	return insertListNode(stack,item,listLength(stack));
}

//��ջ,�൱�ڻ�ȡ���Ա�β��Ԫ��
void* topSeqStack(SeqStack *stack)
{
	return showListNode(stack,listLength(stack)-1);
}


//ɾ��ջ��Ԫ��,�൱��ɾ�����Ա�β��Ԫ��
void* popSeqStack(SeqStack *stack)
{
	return deleteListNode(stack,listLength(stack)-1);
}

//ջ��С
int seqStackSize(SeqStack *stack)
{
	return listLength(stack);
}


//ջ����
int seqStackCapacity(SeqStack *stack)
{
	return 0;
}
