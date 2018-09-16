#pragma once
typedef void SeqQueue;

//��������,���Դ洢
SeqQueue *createSeqDequeue(int capacity);

//���ٶ���
void destroySeqQueue(SeqQueue *queue);

//��ն���
void clearSeqQueue(SeqQueue *queue);

//������
void* deleteHeader(SeqQueue *queue);

//�������
void* appendSeqQueue(SeqQueue *queue,void *item);

//���ض��е�ͷ
void * headerSeqQueue(SeqQueue *queue);

//���г���
int lengthSeqQueue(SeqQueue *queue);

