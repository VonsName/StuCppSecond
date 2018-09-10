#pragma once
/************************************************************************/
/* 循环链表                                                                     */
/************************************************************************/
typedef void CircleLinkedList;
typedef struct  CircleLinkedListNode
{
	struct CircleLinkedListNode *next;
}CircleLinkedListNode;


//创建循环链表(链式存储)
CircleLinkedList* createCircleLinkedList();

//添加节点
CircleLinkedListNode* insertCircleLinkedList(CircleLinkedList*  list, CircleLinkedListNode *node, unsigned int pos);


//获取节点
CircleLinkedListNode* circleLinkedListGet(CircleLinkedList*  list, unsigned int pos);

//清除链表
int clearCircleLinkedList(CircleLinkedList*  list);

//根据位置删除节点
CircleLinkedListNode* deleteCircleLinkedListNode(CircleLinkedList*  list, unsigned int pos);

//根据节点的值删除节点
CircleLinkedListNode* deleteByNodeValue(CircleLinkedList *list, CircleLinkedListNode *node);


//销毁链表
int destoryCircleLinkedList(CircleLinkedList*  list);

//获取链表长度
int circleLinkedListLength(CircleLinkedList*  list);

//获取下一个元素
CircleLinkedListNode * circle_next(CircleLinkedList *list);

//获取当前元素
CircleLinkedListNode * circle_current(CircleLinkedList *list);

//重置游标到第第一个元素
CircleLinkedListNode* circle_resize(CircleLinkedList *list);
