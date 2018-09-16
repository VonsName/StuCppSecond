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
 * 栈的应用 编译匹配字符串
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
		printf("参数错误\n");
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
				//判断优先级,如果栈顶的符号优先级大,则弹出栈顶元素并输出,然后将此符号压栈
				while (priority(p[i]) <= priority(((char)topLinkedStack(stack))))
				{
					output(*((char*)popLinkedStack(stack)));
				}
				//如果栈顶的符号优先级小,则直接将此符号压入栈中
		//	}
			pushLinkedStack(stack, (void *)&p[i]);
		}
		//如果是左括号,直接压入栈中
		else if(isLeft(p[i]))
		{
			pushLinkedStack(stack,(void *)&p[i]);
		}
		else if (isRight(p[i]))
		{
			//如果遍历到右括号,判断栈顶是否是左括号,如果不是输出并弹出
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
 * 中缀表达式转后缀表达式 利用后缀表达式求出值
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

//将字符数字转为int数字
int value(char c)
{
	return (c - '0');
}

//使用后缀表达式计算
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
 * 二叉树中序遍历 LDR(先遍历左子树,再遍历跟节点,最后遍历右子树)
 *		中序遍历将得到中缀表达式
 *二叉树前序遍历 DLR 先遍历根节点,再遍历左子树,最后遍历右子树 将得到前缀表达式
 *二叉树后序遍历 LRD 先遍历左子树,再遍历右子树,最后遍历根节点  将得到后缀表达式
 */
//利用后缀表达式计算值
int main06003(int argc, char *argv[])
{
	char *p = "831-5*+";
	p = "126623*7+/*";
	int ret = mycals(p);
	printf("ret = %d\n", ret);
	return 0;
}
