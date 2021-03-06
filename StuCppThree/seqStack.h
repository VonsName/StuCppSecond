#pragma once


/************************************************************************/
/*  线性栈 的顺序存储相当于线性表的顺序存储(在线性表的数组的尾部插入弹出元素)                                                                  */
/*                                                              */
/************************************************************************/
typedef void SeqStack;

//创建栈,线性存储
SeqStack *createSeqStack(int capacity);

//销毁栈
void destorySeqStack(SeqStack *stack);

//清空栈
void clearSeqStack(SeqStack *stack);

//压栈
void* pushSeqStack(SeqStack *stack, void *item);

//弹栈
void* topSeqStack(SeqStack *stack);

//删除栈顶元素
void* popSeqStack(SeqStack *stack);

//栈大小
int seqStackSize(SeqStack *stack);

//栈容量
int seqStackCapacity(SeqStack *stack);
