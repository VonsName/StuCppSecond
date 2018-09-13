#pragma once


/************************************************************************/
/*  ����ջ ��˳��洢�൱�����Ա��˳��洢(�����Ա�������β�����뵯��Ԫ��)                                                                  */
/*                                                              */
/************************************************************************/
typedef void SeqStack;

//����ջ,���Դ洢
SeqStack *createSeqStack(int capacity);

//����ջ
void destorySeqStack(SeqStack *stack);

//���ջ
void clearSeqStack(SeqStack *stack);

//ѹջ
void* pushSeqStack(SeqStack *stack, void *item);

//��ջ
void* topSeqStack(SeqStack *stack);

//ɾ��ջ��Ԫ��
void* popSeqStack(SeqStack *stack);

//ջ��С
int seqStackSize(SeqStack *stack);

//ջ����
int seqStackCapacity(SeqStack *stack);
