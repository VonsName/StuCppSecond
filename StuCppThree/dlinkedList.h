#pragma once

/************************************************************************/
/*     双向链表                                                                 */
/************************************************************************/
typedef void DLinkedList;
typedef struct  DLinkedListNode
{
	struct DLinkedListNode *next;
	struct DLinkedListNode *pre;
}DLinkedListNode;


//创建双向链表链表(链式存储)
DLinkedList* createDLinkedList();

//添加节点
DLinkedListNode* insertDLinkedList(DLinkedList*  list, DLinkedListNode *node, unsigned int pos);


//获取节点
DLinkedListNode* dLinkedListGet(DLinkedList*  list, unsigned int pos);

//清除链表
int clearDLinkedList(DLinkedList*  list);

//根据位置删除节点
DLinkedListNode* deleteDLinkedListNode(DLinkedList*  list, unsigned int pos);

//根据节点的值删除节点
DLinkedListNode* deleteDlistByNodeValue(DLinkedList *list, DLinkedListNode *node);


//销毁链表
int destoryDLinkedList(DLinkedList*  list);

//获取链表长度
int dLinkedListLength(DLinkedList*  list);

//获取下一个元素
DLinkedListNode * dlinklist_next(DLinkedList *list);

//获取前一个元素
DLinkedListNode * dlinklist_pre(DLinkedList *list);

//获取当前元素
DLinkedListNode * dlinklist_current(DLinkedList *list);

//重置游标到第第一个元素
DLinkedListNode* dlinklist_resize(DLinkedList *list);
