#pragma once
typedef void SeqQueue;

//创建队列,线性存储
SeqQueue *createSeqDequeue(int capacity);

//销毁队列
void destroySeqQueue(SeqQueue *queue);

//清空队列
void clearSeqQueue(SeqQueue *queue);

//出队列
void* deleteHeader(SeqQueue *queue);

//添加数据
void* appendSeqQueue(SeqQueue *queue,void *item);

//返回队列的头
void * headerSeqQueue(SeqQueue *queue);

//队列长度
int lengthSeqQueue(SeqQueue *queue);

