#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include "CppSeqList.cpp"

using namespace std;


typedef struct BitNode
{
	int data;
	struct BitNode *lchild, *rchild;
}BitNode, *BitTree;



BitNode *goLeft(BitNode *root, stack<BitNode *>&s)
{
	if (root == NULL)
	{
		return NULL;
	}
	while (root->lchild != NULL)
	{
		s.push(root);
		root = root->lchild;
	}
	return root;
}

void LDR2(BitNode *root)
{
	BitNode *tmp = NULL;
	stack<BitNode *> s;
	tmp = goLeft(root, s);
	while (tmp)
	{
		printf("%d ", tmp->data);
		if (tmp->rchild != NULL)
		{
			tmp = goLeft(tmp->rchild, s);
		}
		else if(!s.empty())
		{
			tmp = s.top();
			s.pop();
		}
		else
		{
			tmp = NULL;
		}
	}
}

//中序遍历
void LDR(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//遍历左子树
	LDR(root->lchild);
	printf("%d ", root->data);
	//遍历右子树
	LDR(root->rchild);
}

/**
 * 树的非递归遍历
 */
int main09001(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	
	BitNode b1, b2, b3, b4, b5;
	memset(&b1, 0, sizeof(BitNode));
	memset(&b2, 0, sizeof(BitNode));
	memset(&b3, 0, sizeof(BitNode));
	memset(&b4, 0, sizeof(BitNode));
	memset(&b5, 0, sizeof(BitNode));
	b1.data = 1;
	b2.data = 2;
	b3.data = 3;
	b4.data = 4;
	b5.data = 5;
	b1.lchild = &b2;
	b1.rchild = &b3;
	b2.lchild = &b4;
	b3.lchild = &b5;
	LDR2(&b1);
	return 0;
}
typedef struct Day 
{
	int no;
}Day;

int main09002(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	CppSeqList<int> c1;
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		c1.insert(a[i]);
	}
	for (int i = 0; i < c1.len; i++)
	{
		printf("%d ", c1.getData(i));
	}
	return 0;
}

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Day d1, d2, d3;
	Day *p1=nullptr, *p2=nullptr, *p3=nullptr;
	d1.no = 1;
	d2.no = 2;
	d3.no = 3;
	p1 = &d1; p2 = &d2; p3 = &d3;
	CppSeqList<Day *> c1(3);
	c1.insert(p1); c1.insert(p2); c1.insert(p3);
	for (int i = 0; i < c1.len; i++)
	{
		printf("%d ", c1.getData(i)->no);
	}
	return 0;
}