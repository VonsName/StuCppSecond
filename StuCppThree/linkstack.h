#pragma once

/************************************************************************/
/*    ջ����ʽ�洢                                                                  */
/*����ջ ����ʽ�洢�൱�����Ա����ʽ�洢(�������ͷ�����뵯��Ԫ��)    */
/************************************************************************/
typedef void LinkedStack;

//����ջ,���Դ洢
LinkedStack *createLinkedStack();

//����ջ
void destoryLinkedStack(LinkedStack *stack);

//���ջ
void clearLinkedStack(LinkedStack *stack);

//ѹջ
void* pushLinkedStack(LinkedStack *stack, void *item);

//��ջ
void* topLinkedStack(LinkedStack *stack);

//ɾ��ջ��Ԫ��
void* popLinkedStack(LinkedStack *stack);

//ջ��С
int linkedStackSize(LinkedStack *stack);

//ջ����
int linkedStackCapacity(LinkedStack *stack);
