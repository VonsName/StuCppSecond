#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct BitNode
{
	int data;
	struct BitNode *lchild, *rchild;
}BitNode, *BitTree;


//���򴴽���
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
	ln=createBitTree();//�ݹ鹹��������
	rn = createBitTree();//�ݹ鹹��������
	node->lchild = ln;
	node->rchild = rn;
	return node;
}


//�������
void DLR3(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->data);

	//����������
	DLR3(root->lchild);
	//����������
	DLR3(root->rchild);
}

//��������ͷ���
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
 * ���Ĵ���
 */
int main01101(int argc,char *argv[])
{
	BitNode *root = NULL;
	root = createBitTree();
	DLR3(root);
	freeTree(root);
	return 0;
}
