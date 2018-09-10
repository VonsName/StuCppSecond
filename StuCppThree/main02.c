#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circleLinkedList.h"
//#include "CppLinkedList.cpp"


typedef struct Stud 
{
	CircleLinkedListNode node;
	int age;
}Stud;

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Stud s1, s2, s3;
	s1.age = 23;
	s2.age = 25;
	s3.age = 27;
	CircleLinkedList *list= createCircleLinkedList();
	insertCircleLinkedList(list, (CircleLinkedListNode *)&s1, circleLinkedListLength(list));
	insertCircleLinkedList(list, (CircleLinkedListNode *)&s2, circleLinkedListLength(list));
	insertCircleLinkedList(list, (CircleLinkedListNode *)&s3, circleLinkedListLength(list));
	for ( int i = 0; i < 2 * (circleLinkedListLength(list)); i++)
	{
		Stud *stu = NULL;
		stu = (Stud *)circleLinkedListGet(list, i);
		if (stu != NULL)
		{
			printf("stu.age= %d\n", stu->age);
		}
	}
	printf("%d\n", circleLinkedListLength(list));
	return 0;
}
