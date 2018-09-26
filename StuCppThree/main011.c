#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct BitNode
{
	int data;
	struct BitNode *lchild, *rchild;
}BitNode, *BitTree;


//先序创建树
BitNode* createBitTree()
{
	BitNode *node = NULL;
	BitNode *ln = NULL;
	BitNode *rn = NULL;
	char ch;
	scanf("%c", &ch);
	if (ch=='#')
	{
		return NULL;
	}
	
	node = (BitNode *)malloc(sizeof(BitNode));
	memset(node, 0, sizeof(BitNode));
	node->data = ch;
	ln=createBitTree();//递归构造左子树
	rn = createBitTree();//递归构造右子树
	node->lchild = ln;
	node->rchild = rn;
	return node;
}


//先序遍历
void DLR3(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->data);

	//遍历左子树
	DLR3(root->lchild);
	//遍历右子树
	DLR3(root->rchild);
}

//后序遍历释放树
void freeTree(BitNode *root)
{
	if (root==NULL)
	{
		return;
	}
	if (root->lchild)
	{
		freeTree(root->lchild);
		root->lchild = NULL;
	}
	if (root->rchild)
	{
		freeTree(root->rchild);
		root->rchild = NULL;
	}
	if (root)
	{
		free(root);
		root = NULL;
	}
}

/**
 * 树的创建
 */
int main01101(int argc,char *argv[])
{
	BitNode *root = NULL;
	root = createBitTree();
	DLR3(root);
	freeTree(root);
	return 0;
}
