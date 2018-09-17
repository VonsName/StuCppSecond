#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//����Ϊ������:��Ϊ��,��ߵ����ұߵĸ��ڵ�

/**
 * ������:��n���ڵ�����޼���,��һ�����ڵ��Լ����û����ཻ,�ֱ��Ϊ���������������Ķ��������;
 * �߼��ṹ:һ�Զ�
 * �ڵ�Ķ�:�ڵ�ֱ�Ӻ�̽ڵ������
 * ��������:1.ÿ���ڵ����ֻ����������(�����ڶȴ���2�Ľڵ�)
 *				  2.����������������˳���ܵߵ�
 * ������������:1.�ڶ������ĵ�i������������2��i-1�η����ڵ�
 *						2.���Ϊk�Ķ�����������2��k�η�-1���ڵ�
 *						3.�����κ�һ�Ŷ�����,����Ϊ2�Ľڵ���n1��,��Ҷ����n2�ض�Ϊ:n1+1,��n2=n1+1;
 * ��������:һ�����Ϊk����2��k�η�-1���ڵ�Ķ�����,ÿ�㶼�����˽ڵ�
 * ��ȫ������:���Ϊk,��n���ڵ�Ķ�����,���ҽ�����ÿһ���ڵ㶼�����Ϊk����������
 *					 �б�Ŵ�1��n�Ľڵ�һһ��Ӧ,�����ص���ֻ�����һ��Ҷ�Ӳ���,��ȫ�����������
 * ������n���ڵ����ȫ�����������k��Ϊ:log2n�ľ���ֵ+1,�����K=log2n+1;
 *	������ȫ������,����������,�������ұ��,����Ϊi�Ľڵ�,�����ӱ�ű�Ϊ2i,���Һ��ӱ�ű�Ϊ2i+1
 *	��˫�׵ı�ű�Ϊi/2(i=1ʱΪ��,����);
 * ��������˳��洢:�����������϶���,�������ұ��,��һ�������Ĵ洢��Ԫ�洢,˳��洢��,
 *	�������ȫ������������������,���Ը�ԭ��Ψһ��Ӧ�Ķ�������״,��������ȫ������,һ��תΪ��ȫ������
 * �������ȱ��ͳͳ������ڵ�,������Ϊ��
 */

//���Ķ�������ʾ��
typedef struct BitNode 
{
	int data;
	struct BitNode *lchild, *rchild;
}BitNode, *BitTree;


//������������ʾ��,�и��ڵ�
typedef struct ThBitNode
{
	int data;
	struct ThBitNode *lchild, *rchild;
	struct ThBitNode *parent;
}ThBitNode, *ThBitTree;

//����˫�ױ�ʾ��

typedef struct PBitNode 
{
	int data;
	int parentPosttion;//˫���������е��±�λ��
	char lrTag;//���Һ��ӱ��
}PBitNode;
typedef struct PBitTree
{
	PBitNode nodes[10];//�ڵ�����
	int nodeCount;//�ڵ����
	int root;//���ڵ��λ��,�洢���Ǹ��ڵ��������е��±�λ��
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

//�������
void DLR(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);

	//����������
	DLR(root->lchild);
	//����������
	DLR(root->rchild);
}

//�������
void LDR(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//����������
	LDR(root->lchild);
	printf("%d ", root->data);
	//����������
	LDR(root->rchild);
}

//�������
void LRD(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//����������
	LRD(root->lchild);
	//����������
	LRD(root->rchild);
	printf("%d ", root->data);
}

//��Ҷ�ӽڵ���
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

//�������
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

//copy ������
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
 * �������ı���:1.�������:DLR ���ڵ�->������->������ ǰ׺���ʽ
 *						 2.�������:LDR ������->���ڵ�->������ ��׺���ʽ
 *						 3.�������:LRD ������->������->���ڵ� ��׺���ʽ
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
	printf("�������\n");
	DLR(&b1);
	printf("\n�������\n");
	LDR(&b1);
	printf("\n�������\n");
	LRD(&b1);
	printf("\n");
	countLeaf(&b1);
	printf("Ҷ�ӽڵ���Ϊ:%d \n", sum);
	int dep = depth(&b1);
	printf("���ĸ߶�Ϊ:%d \n", dep);
	BitNode *newNode =  copyTree(&b1);
	printf("copy���������\n");
	DLR(newNode);
	return 0;
}
