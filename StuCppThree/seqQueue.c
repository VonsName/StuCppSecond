#include "seqQueue.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqList.h"



//��������,���Դ洢
SeqQueue *createSeqDequeue(int capacity)
{
	return (SeqQueue*)createList(capacity);
}

//���ٶ���
void destroySeqQueue(SeqQueue *queue)
{
	destoryList((SeqList *)queue);
}

//��ն���
void clearSeqQueue(SeqQueue *queue)
{
	clearList((SeqList *)queue);
}

//ɾ��ͷ��Ԫ��
void* deleteHeader(SeqQueue *queue)
{
	return deleteListNode((SeqList *)queue, 0);
}

//�������
void* appendSeqQueue(SeqQueue *queue, void *item)
{
	insertListNode((SeqList *)queue, item, listLength((SeqList *)queue));
	return item;
}

//���ض��е�ͷ
void * headerSeqQueue(SeqQueue *queue)
{
	return showListNode((SeqList *)queue,0);
}

//���г���
int lengthSeqQueue(SeqQueue *queue)
{
	return listLength((SeqList *)queue);
}