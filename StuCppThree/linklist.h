#pragma once

typedef void LinkedList;
typedef struct  LinkedListNode
{
	struct LinkedListNode *next;
}LinkedListNode;

//创建线性表(链式存储)
LinkedList* createLinkList();

//添加节点
LinkedListNode* insertLinkList(LinkedList*  list,LinkedListNode *node, unsigned int pos);


//获取节点
LinkedListNode* linlistGet(LinkedList*  list,unsigned int pos);

//清除链表
int clearLinkList(LinkedList*  list);

//删除节点
LinkedListNode* deleteLinkListNode(LinkedList*  list,unsigned int pos);

//销毁链表
int destoryLinkList(LinkedList*  list);

//获取链表长度
int linkListLength(LinkedList*  list);


