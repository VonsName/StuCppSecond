#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * 矩阵的转置 a[m][n] -> b[n][m] b是a的转置

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
 * 马鞍点
 */
void maxmin(int(*arr1)[8],  int m, int n)
{
	int max[8];//列中最大元素
	int min[5];//行中最小元素
	//	//求出最小值
	for (int i = 0; i < m; i++)
	{
		min[i] = arr1[i][0];//默认每行第一个元素为最小
		for (int j = 1; j < n; j++)
		{
			if (arr1[i][j] < min[i])
			{
				min[i] = arr1[i][j];
			}
		}
	}
	//求最大值
	for (int i = 0; i < n; i++)
	{
		//默认每列第一个元素为最大值
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
				printf("马鞍点为第%d行,行最小值为:%d--第%d列,列最大值为%d", i,min[i],j, max[j]);
				printf("\n");
				return;
			}
		}
	}
	printf("没有马鞍点\n");
}

/**
 * 多维数组和广义表
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
