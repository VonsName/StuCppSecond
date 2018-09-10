#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqList.h"
#include "linklist.h"

int times_count(int *arr,int len,int *outarray)
{
	for (int i = 0; i < len; i++)
	{
		int num = 0;
		for (int j = i; j < len-1; j++)
		{
			if ((arr[i]) !=( arr[j+1]));
			{
				continue;
			}
			outarray[i] =num++;
		}
	}
	printf("\n");
	return 0;
}

void main01_test()
{
	int arr[] = {1,11,1,2,5,1,3,2,6,9,10,1};
	int len = sizeof(arr) / sizeof(*arr);
	int outarray[11] = {0};
//	int countnum = times_count(arr,len,outarray);
	for (int i = 0; i < len; i++)
	{
		int num = 0;
		for (int j = i; j < len - 1; j++)
		{
			if ((arr[i]) != (arr[j + 1]));
			{
				continue;
			}
			outarray[i] = num++;
		}
	}
}

int main0101(int argc,char *argv[])
{
	//main01_test();
	int arr[] = { 1,11,1,2,5,1,3,2,6,9,10,1 };
	int len = sizeof(arr) / sizeof(*arr);
	int outarray[11] = { 0 };
	//	int countnum = times_count(arr,len,outarray);
	for (int i = 0; i < len; i++)
	{
		int num = 0;
		for (int j = i; j < len - 1; j++)
		{
			if ((arr[i]) != (arr[j + 1]));
			{
				continue;
			}
			outarray[i] = num++;
		}
	}
	return 0;
}


typedef struct Teacher
{
	LinkedListNode node;
	int age;
}Teacher;

//线性表顺序存储
int main01seqlist(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Teacher t1;
	t1.age = 23;
	Teacher t2;
	t2.age = 25;
	Teacher t3;
	t3.age = 18;
	SeqList* list = createList(10);
	if (list == NULL)
	{
		printf("创建线性表error\n");
		return 0;
	}
	insertListNode(list, (SeqListNode*)&t1, 0);
	insertListNode(list, (SeqListNode*)&t2, 0);
	insertListNode(list, (SeqListNode*)&t3, 0);
	for (int i = 0; i < listLength(list); i++)
	{
		Teacher *tmp = (Teacher *)showListNode(list, i);
		printf("Teacher.age=%d\n", tmp->age);
	}
	printf("链表长度:%d\n", listLength(list));

	printf("清空线性表\n");
	clearList(list);
	t1.age = 33;
	t2.age = 32;
	t3.age = 39;
	insertListNode(list, (SeqListNode*)&t1, 0);
	insertListNode(list, (SeqListNode*)&t2, 0);
	insertListNode(list, (SeqListNode*)&t3, 0);
	for (int i = 0; i < listLength(list); i++)
	{
		Teacher *tmp = (Teacher *)showListNode(list, i);
		if (tmp == NULL)
		{
			return 0;
		}
		printf("Teacher.age=%d\n", tmp->age);
	}
	printf("删除线性表节点\n");
	while (listLength(list) > 0)
	{
		deleteListNode(list, 0);
	}
	printf("链表长度:%d\n", listLength(list));
	printf("销毁线性表\n");
	destoryList(list);
	return 0;
}


//线性表链式存储
int main0102(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Teacher t1,t2, t3, t4, t5;
	t1.age = 23;
	t2.age = 25;
	t3.age = 26;
	t4.age = 18;
	t5.age = 29;
	LinkedList* list=createLinkList();
	if (list == NULL)
	{
		printf("list error\n");
		return 0;
	}
	LinkedListNode* newNode = NULL;
	newNode = insertLinkList(list, (LinkedListNode *)&t1, 0);
	printf("新增的数据为teacher.age= %d\n", t1.age);
	newNode = insertLinkList(list, (LinkedListNode *)&t2, 0);
	printf("新增的数据为teacher.age= %d\n", t2.age);
	newNode = insertLinkList(list, (LinkedListNode *)&t3, 0);
	printf("新增的数据为teacher.age= %d\n", t3.age);
	newNode = insertLinkList(list, (LinkedListNode *)&t4, 0);
	printf("新增的数据为teacher.age= %d\n", t4.age);
	newNode = insertLinkList(list, (LinkedListNode *)&t5, 0);
	printf("新增的数据为teacher.age= %d\n", t5.age);
	for (int i = 0; i < linkListLength(list); i++)
	{
		Teacher *tmp = NULL;
		tmp = (Teacher *)linlistGet(list, i);
		if (tmp != NULL)
		{
			printf("teacher.age= %d\n", tmp->age);
		}
	}
	printf("LinkedList长度:%d\n", linkListLength(list));
	LinkedListNode *node=deleteLinkListNode(list, 3);
	if (node != NULL)
	{
		Teacher *t = (Teacher *)node;
		printf("删除节点的数据为teacher.age=%d \n", t->age);
	}
	for (int i = 0; i < linkListLength(list); i++)
	{
		Teacher *tmp = NULL;
		tmp = (Teacher *)linlistGet(list, i);
		if (tmp != NULL)
		{
			printf("teacher.age= %d\n", tmp->age);
		}
	}
	printf("LinkedList长度:%d\n", linkListLength(list));
	clearLinkList(list);
	for (int i = 0; i < linkListLength(list); i++)
	{
		Teacher *tmp = NULL;
		tmp = (Teacher *)linlistGet(list, i);
		if (tmp != NULL)
		{
			printf("teacher.age= %d\n", tmp->age);
		}
	}
	printf("LinkedList长度:%d\n", linkListLength(list));

	destoryLinkList(list);
	return 0;
}
