#pragma once

typedef void SeqList;
typedef void SeqListNode;

//创建线性表
SeqList* createList( int capacity);

//插入节点
SeqListNode* insertListNode(SeqList* list, SeqListNode* node, unsigned int pos);

//删除节点
SeqListNode* deleteListNode(SeqList* list, unsigned int pos);

//清空线性表
int clearList(SeqList* list);

//销毁线性表
SeqList* destoryList(SeqList* list);

//查看节点
SeqListNode* showListNode(SeqList* list, int pos);

//获取线性表长度
int listLength(SeqList* list);


