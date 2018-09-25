#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * �����ת�� a[m][n] -> b[n][m] b��a��ת��

 */
void trsmat(int(*arr1)[8], int(*arr2)[5], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	int i, j;
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			arr2[i][j] = arr1[j][i];
		}
	}

}


/**
 * ����
 */
void maxmin(int(*arr1)[8],  int m, int n)
{
	int max[8];//�������Ԫ��
	int min[5];//������СԪ��
	//	//�����Сֵ
	for (int i = 0; i < m; i++)
	{
		min[i] = arr1[i][0];//Ĭ��ÿ�е�һ��Ԫ��Ϊ��С
		for (int j = 1; j < n; j++)
		{
			if (arr1[i][j] < min[i])
			{
				min[i] = arr1[i][j];
			}
		}
	}
	//�����ֵ
	for (int i = 0; i < n; i++)
	{
		//Ĭ��ÿ�е�һ��Ԫ��Ϊ���ֵ
		max[i] = arr1[0][i];
		for (int j = 1; j < m; j++)
		{
			if (arr1[j][i] > max[i])
			{
				max[i] = arr1[j][i];
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (min[i] == max[j])
			{
				printf("����Ϊ��%d��,����СֵΪ:%d--��%d��,�����ֵΪ%d", i,min[i],j, max[j]);
				printf("\n");
				return;
			}
		}
	}
	printf("û������\n");
}

/**
 * ��ά����͹����
 */
int main01001(int argc, char *argv[])
{

	int a[5][8] = {
		{1,2,3,4,5,6,7,8},
		{11,22,33,44,55,66,77,88},
		{21,22,23,24,25,26,27,28},
		{60,62,63,64,65,66,67,68},
		{51,52,53,54,55,56,57,58}
	};
	int b[8][5] = { 0 };
	int m = 5;
	int n = 8;
	//	trsmat(a, b, m, n);
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}*/
	maxmin(a, m, n);
	return 0;
}
