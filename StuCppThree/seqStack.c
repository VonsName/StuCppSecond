#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqStack.h"


typedef struct TSeqStack 
{
	int size;
	int *node;
}TSeqStack;

//����ջ,���Դ洢
SeqStack *createSeqStack(int capacity)
{
	return NULL;
}

//����ջ
void destorySeqStack(SeqStack *stack)
{

}

//���ջ
void clearSeqStack(SeqStack *stack)
{

}

//ѹջ
void* pushSeqStack(SeqStack *stack, void *item)
{
	return NULL;
}

//��ջ
void* topSeqStack(SeqStack *stack)
{
	return NULL;
}


//ɾ��ջ��Ԫ��
void* popSeqStack(SeqStack *stack)
{
	return NULL;
}

//ջ��С
int seqStackSize(SeqStack *stack)
{
	return 0;
}


//ջ����
int seqStackCapacity(SeqStack *stack)
{
	return 0;
}
