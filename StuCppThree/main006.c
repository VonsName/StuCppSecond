#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"


int ifLeft(char c);
int ifRight(char c);
int match(char left, char right);
int myscanf( char *p)
{
	int ret = 0;
	LinkedStack *stack = createLinkedStack();
	int len = strlen(p);
	int i = 0;
	for ( i= 0; i < len; i++)
	{
		if (ifLeft(p[i]))
		{
			pushLinkedStack(stack, (void *)&p[i]);
		}
		if (ifRight(p[i]))
		{
			char *c = (char *)popLinkedStack(stack);
			if ((c == NULL) || !match(*c, p[i]))
			{
				printf("match error\n");
				ret = 0;
				break;
			}
		}
	}
	if (linkedStackSize(stack)==0 && p[i]=='\0')
	{
		ret = 1;
		printf("match success\n");
	}
	else
	{
		printf("match valid\n");
	}
	return ret;
}

int ifLeft(char c)
{
	int ret = 0;
	switch (c)
	{
	case '<':
	case '{':
	case '(':
	case '[':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

int ifRight(char c)
{
	int ret = 0;
	switch (c)
	{
	case '>':
	case '}':
	case ')':
	case ']':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

int match(char left, char right)
{
	int ret = 0;
	switch (left)
	{
	case '<':
		ret = (right == '>');
		break;
	case '{':
		ret = (right == '}');
		break;
	case '(':
		ret = (right == ')');
		break;
	case '[':
		ret = (right == ']');
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

/**
 * ջ��Ӧ�� ����ƥ���ַ���
 */
int main06001(int argc,char *argv[])
{
	char *p = "#include<stdio.h>#include<stdlib.h>#include<string.h>intmain(intargc,char*argv[]){}";
	int ret = myscanf(p);
	return 0;
}


int isLeft(char c)
{
	return (c == '(');
}
int isRight(char c)
{
	return (c == ')');
}
int isNumber(char c)
{
	return (c >= '0' && c <= '9');
}
int isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

void output(char c)
{
	printf("%c ", c);
}

int priority(char c)
{
	int ret = 0;
	switch (c)
	{
	case '+':
	case '-':
		ret = 1;
		break;
	case '*':
	case '/':
		ret = 2;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

void mytransform(char *p,LinkedStack *tmp)
{
	if (p == NULL)
	{
		printf("��������\n");
		return;
	}
	int len = strlen(p);
	int i = 0;
	LinkedStack *stack= createLinkedStack();
	
	//"8+(3-1)*5";
	for (i = 0; i < len; i++)
	{
		if (isNumber(p[i]))
		{
			output(p[i]);
		}
		else if (isOperator(p[i]))
		{
		//	if ((char*)topLinkedStack(stack)!=NULL)
		//	{
				//�ж����ȼ�,���ջ���ķ������ȼ���,�򵯳�ջ��Ԫ�ز����,Ȼ�󽫴˷���ѹջ
				while (priority(p[i]) <= priority(((char)topLinkedStack(stack))))
				{
					output(*((char*)popLinkedStack(stack)));
				}
				//���ջ���ķ������ȼ�С,��ֱ�ӽ��˷���ѹ��ջ��
		//	}
			pushLinkedStack(stack, (void *)&p[i]);
		}
		//�����������,ֱ��ѹ��ջ��
		else if(isLeft(p[i]))
		{
			pushLinkedStack(stack,(void *)&p[i]);
		}
		else if (isRight(p[i]))
		{
			//���������������,�ж�ջ���Ƿ���������,����������������
			while (!isLeft(*((char*)topLinkedStack(stack))))
			{
				output(*((char*)popLinkedStack(stack)));
			}
			popLinkedStack(stack);
		}
	}
	for (int k = 0; k < linkedStackSize(stack); k++)
	{
		output(*((char*)popLinkedStack(stack)));
	}
	destoryLinkedStack(stack);
}


/**
 * ��׺���ʽת��׺���ʽ ���ú�׺���ʽ���ֵ
 */
int main06002(int argc, char *argv[])
{
	char *p = "8+(3-1)*5";
	p = "1+2*(66/(2*3)+7)";
	LinkedStack *tmp = createLinkedStack();
	mytransform(p,tmp);
	return 0;
}


int express(int left, int right, char op)
{
	int res = 0;
	switch (op)
	{
	case '+':
		res = left + right;
		break;
	case '-':
		res = left - right;
		break;
	case '*':
		res = left * right;
		break;
	case '/':
		res = left / right;
		break;
	default:
		res = 0;
		break;
	}
	return res;
}

//���ַ�����תΪint����
int value(char c)
{
	return (c - '0');
}

//ʹ�ú�׺���ʽ����
int mycals(char *p)
{
	LinkedStack *stack= createLinkedStack();
	int len = strlen(p);
	for (int i = 0; i < len; i++)
	{
		if (isNumber(p[i]))
		{
			pushLinkedStack(stack, (void *)value(p[i]));
		}
		else if (isOperator(p[i]))
		{
			int right = ((int)popLinkedStack(stack));
			int left = ((int)popLinkedStack(stack));
			int result = express(left, right, p[i]);
			pushLinkedStack(stack, (void *)result);
		}
		else
		{
			printf("error\n");
			break;
		}
	}
	int ret = ((int)popLinkedStack(stack));
	destoryLinkedStack(stack);
	return ret;
}


/**
 * ������������� LDR(�ȱ���������,�ٱ������ڵ�,������������)
 *		����������õ���׺���ʽ
 *������ǰ����� DLR �ȱ������ڵ�,�ٱ���������,������������ ���õ�ǰ׺���ʽ
 *������������� LRD �ȱ���������,�ٱ���������,���������ڵ�  ���õ���׺���ʽ
 */
//���ú�׺���ʽ����ֵ
int main06003(int argc, char *argv[])
{
	char *p = "831-5*+";
	p = "126623*7+/*";
	int ret = mycals(p);
	printf("ret = %d\n", ret);
	return 0;
}
