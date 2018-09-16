#include "seqQueue.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqList.h"



//创建队列,线性存储
SeqQueue *createSeqDequeue(int capacity)
{
	return (SeqQueue*)createList(capacity);
}

//销毁队列
void destroySeqQueue(SeqQueue *queue)
{
	destoryList((SeqList *)queue);
}

//清空队列
void clearSeqQueue(SeqQueue *queue)
{
	clearList((SeqList *)queue);
}

//删除头部元素
void* deleteHeader(SeqQueue *queue)
{
	return deleteListNode((SeqList *)queue, 0);
}

//添加数据
void* appendSeqQueue(SeqQueue *queue, void *item)
{
	insertListNode((SeqList *)queue, item, listLength((SeqList *)queue));
	return item;
}

//返回队列的头
void * headerSeqQueue(SeqQueue *queue)
{
	return showListNode((SeqList *)queue,0);
}

//队列长度
int lengthSeqQueue(SeqQueue *queue)
{
	return listLength((SeqList *)queue);
}