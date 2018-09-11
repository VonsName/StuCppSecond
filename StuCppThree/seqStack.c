#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqStack.h"


typedef struct TSeqStack 
{
	int size;
	int *node;
}TSeqStack;

//´´½¨Õ»,ÏßÐÔ´æ´¢
SeqStack *createSeqStack(int capacity)
{
	return NULL;
}

//Ïú»ÙÕ»
void destorySeqStack(SeqStack *stack)
{

}

//Çå¿ÕÕ»
void clearSeqStack(SeqStack *stack)
{

}

//Ñ¹Õ»
void* pushSeqStack(SeqStack *stack, void *item)
{
	return NULL;
}

//µ¯Õ»
void* topSeqStack(SeqStack *stack)
{
	return NULL;
}


//É¾³ýÕ»¶¥ÔªËØ
void* popSeqStack(SeqStack *stack)
{
	return NULL;
}

//Õ»´óÐ¡
int seqStackSize(SeqStack *stack)
{
	return 0;
}


//Õ»ÈÝÁ¿
int seqStackCapacity(SeqStack *stack)
{
	return 0;
}
