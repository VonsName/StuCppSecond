#pragma once
typedef void LinkedQueue;


//创建队列的链式存储
LinkedQueue* createLinkedQueue();


//销毁队列
void destroyLinkedQueue(LinkedQueue* queue);

//清空队列
void clearLinkedQueue(LinkedQueue* queue);

//入队列
void* insertLinkedQueue(LinkedQueue* queue, void *item);

//出队列
void* popLinkedQueue(LinkedQueue* queue);

//返回队列头部元素
void* leftLinkedQueue(LinkedQueue* queue);

//队列长度
int lenLinkedQueue(LinkedQueue* queue);

