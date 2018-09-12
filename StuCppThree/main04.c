#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlinkedList.h"


typedef struct  MyTeacher
{
	DLinkedListNode node;
	int value;
}MyTeacher;
int main04001(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	MyTeacher v1, v2, v3;
	v1.value = 1;
	v2.value = 2;
	v3.value = 3;
	DLinkedList* list = createDLinkedList();
	if (list == NULL)
	{
		return 0;
	}
	DLinkedListNode* node = NULL;
	node = insertDLinkedList(list, (DLinkedListNode *)&v1, 0);
	//printf("插入Value值为:%d \n", ((MyTeacher *)node)->value);
	node = insertDLinkedList(list, (DLinkedListNode *)&v2, 0);
	//printf("插入Value值为:%d \n", ((MyTeacher *)node)->value);
	node = insertDLinkedList(list, (DLinkedListNode *)&v3, 0);
//	printf("插入Value值为:%d \n", ((MyTeacher *)node)->value);
	printf("dlist的长度为：%d\n", dLinkedListLength(list));
	for (unsigned int i = 0; i < dLinkedListLength(list); i++)
	{
		MyTeacher *pv = NULL;
		pv = (MyTeacher *)dLinkedListGet(list, i);
		if (pv != NULL)
		{
			printf("MyTeacher值为: %d\n", pv->value);
		}
	}
	MyTeacher *pv = NULL;// (MyTeacher *)dlinklist_current(list);
	printf("pre\n");
	pv = (MyTeacher *)dlinklist_pre(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_pre(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_pre(list);
	printf("MyTeacher值为: %d\n", pv->value);


	printf("next\n");
	pv = (MyTeacher *)dlinklist_next(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_next(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_next(list);
	printf("MyTeacher值为: %d\n", pv->value);


	printf("pre\n");
	pv = (MyTeacher *)dlinklist_pre(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_pre(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_pre(list);
	printf("MyTeacher值为: %d\n", pv->value);

	printf("next\n");
	pv = (MyTeacher *)dlinklist_next(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_next(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_next(list);
	printf("MyTeacher值为: %d\n", pv->value);

	printf("pre\n");
	pv = (MyTeacher *)dlinklist_pre(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_pre(list);
	printf("MyTeacher值为: %d\n", pv->value);
	pv = (MyTeacher *)dlinklist_pre(list);
	printf("MyTeacher值为: %d\n", pv->value);

	return 0;
}