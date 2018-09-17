#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//树变为二叉树:左为尊,左边的做右边的父节点

/**
 * 二叉树:是n个节点的有限集合,由一个根节点以及两棵互不相交,分别称为左子树和右子树的二叉树组成;
 * 逻辑结构:一对二
 * 节点的度:节点直接后继节点的数量
 * 基本特征:1.每个节点最多只有两棵子树(不存在度大于2的节点)
 *				  2.左子树和右子树的顺序不能颠倒
 * 二叉树的性质:1.在二叉树的第i层上面至多有2的i-1次方个节点
 *						2.深度为k的二叉树至多有2的k次方-1个节点
 *						3.对于任何一颗二叉树,若度为2的节点有n1个,则叶子树n2必定为:n1+1,即n2=n1+1;
 * 满二叉树:一棵深度为k且有2的k次方-1个节点的二叉树,每层都充满了节点
 * 完全二叉树:深度为k,有n个节点的二叉树,当且仅当其每一个节点都与深度为k的满二叉树
 *					 中编号从1至n的节点一一对应,它的特点是只有最后一层叶子不满,且全部集中在左边
 * 若具有n个节点的完全二叉树的深度k必为:log2n的绝对值+1,即深度K=log2n+1;
 *	对于完全二叉树,若从上至下,从左至右编号,则编号为i的节点,其左孩子编号必为2i,其右孩子编号必为2i+1
 *	其双亲的编号必为i/2(i=1时为根,除外);
 * 二叉树的顺序存储:按二叉树自上而下,从左至右编号,用一组连续的存储单元存储,顺序存储后,
 *	如果是完全二叉树或者满二叉树,可以复原成唯一对应的二叉树形状,若不是完全二叉树,一律转为完全二叉树
 * 将各层空缺处统统补上虚节点,其内容为空
 */

//树的二叉链表示法
typedef struct BitNode 
{
	int data;
	struct BitNode *lchild, *rchild;
}BitNode, *BitTree;


//树的三叉链表示法,有父节点
typedef struct ThBitNode
{
	int data;
	struct ThBitNode *lchild, *rchild;
	struct ThBitNode *parent;
}ThBitNode, *ThBitTree;

//树的双亲表示法

typedef struct PBitNode 
{
	int data;
	int parentPosttion;//双亲在数组中的下标位置
	char lrTag;//左右孩子标记
}PBitNode;
typedef struct PBitTree
{
	PBitNode nodes[10];//节点数组
	int nodeCount;//节点个数
	int root;//根节点的位置,存储的是父节点在数组中的下标位置
}PBitTree;



int foo(int n)
{
	int f = 1;
	if (n>1)
	{
		f = n * foo(n - 1);
	}
	else
	{
		f = 1;
	}
	return f;
}

//先序遍历
void DLR(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);

	//遍历左子树
	DLR(root->lchild);
	//遍历右子树
	DLR(root->rchild);
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

//后序遍历
void LRD(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//遍历左子树
	LRD(root->lchild);
	//遍历右子树
	LRD(root->rchild);
	printf("%d ", root->data);
}

//求叶子节点数
int sum = 0;
void countLeaf(BitNode *root)
{
	if (root)
	{
		if (!root->lchild && !root->rchild)
		{
			sum++;
		}
		if (root->lchild)
		{
			countLeaf(root->lchild);
		}
		if (root->rchild)
		{
			countLeaf(root->rchild);
		}
	}
}

//树的深度
int depth(BitNode *root)
{
	int deptv = 0;
	int ldeptv = 0;
	int rdeptv = 0;
	if (root == NULL)
	{
		return deptv;
	}
	ldeptv = depth(root->lchild);
	rdeptv = depth(root->rchild);
	deptv = 1 + (ldeptv > rdeptv ? ldeptv : rdeptv);
	return deptv;
}

//copy 二叉树
BitNode *copyTree(BitNode *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	BitNode *newNode = NULL;
	BitNode *newLp = NULL;
	BitNode *newRp = NULL;
	if (root->lchild)
	{
		newLp = copyTree(root->lchild);
	}
	else
	{
		newLp = NULL;
	}
	if (root->rchild)
	{
		newRp = copyTree(root->rchild);
	}
	else 
	{
		newRp = NULL;
	}
	newNode = (BitNode *)malloc(sizeof(BitNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->lchild = newLp;
	newNode->rchild = newRp;
	newNode->data = root->data;
	return newNode;
}
/**
 * 二叉树的遍历:1.先序遍历:DLR 根节点->左子树->右子树 前缀表达式
 *						 2.中序遍历:LDR 左子树->根节点->右子树 中缀表达式
 *						 3.后序遍历:LRD 左子树->右子树->根节点 后缀表达式
 */
int main(int argc,char *argv[])
{
	
	//printf("%d \n",foo(5));
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
	printf("先序遍历\n");
	DLR(&b1);
	printf("\n中序遍历\n");
	LDR(&b1);
	printf("\n后序遍历\n");
	LRD(&b1);
	printf("\n");
	countLeaf(&b1);
	printf("叶子节点数为:%d \n", sum);
	int dep = depth(&b1);
	printf("树的高度为:%d \n", dep);
	BitNode *newNode =  copyTree(&b1);
	printf("copy树先序遍历\n");
	DLR(newNode);
	return 0;
}
