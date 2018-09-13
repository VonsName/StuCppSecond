#pragma once

/************************************************************************/
/*    栈的链式存储                                                                  */
/*线性栈 的链式存储相当于线性表的链式存储(在链表的头部插入弹出元素)    */
/************************************************************************/
typedef void LinkedStack;

//创建栈,线性存储
LinkedStack *createLinkedStack();

//销毁栈
void destoryLinkedStack(LinkedStack *stack);

//清空栈
void clearLinkedStack(LinkedStack *stack);

//压栈
void* pushLinkedStack(LinkedStack *stack, void *item);

//弹栈
void* topLinkedStack(LinkedStack *stack);

//删除栈顶元素
void* popLinkedStack(LinkedStack *stack);

//栈大小
int linkedStackSize(LinkedStack *stack);

//栈容量
int linkedStackCapacity(LinkedStack *stack);
