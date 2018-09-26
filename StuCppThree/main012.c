#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void myswap(int *arr, int k, int i)
{
	int tmp = arr[i];
	arr[i] = arr[k];
	arr[k] = tmp;
}
/**
 * 选择排序
 */
void selectSort(int *arr,int len)
{
	for (int i=0;i<len;i++)
	{
		int k = i;//最小
		for (int j=i+1;j<len;j++)
		{
			if (arr[j] < arr[k])//第一个元素和每一个元素比较
			{
				k = j;//比较得出最小
			}
		}
		myswap(arr, k, i);//交换
	}
	for (int i=0;i<len;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/**
 * 插入排序
 */
void insertSort(int *arr, int len)
{
	int k = 0;
	int tmp = -1;
	for (int i = 1; i < len; i++)
	{
		k = i;//待插入的位置
		tmp = arr[k];//待插入的元素(当前比较的元素)
		for (int j = i - 1; (j > 0) && (arr[j] > tmp); j--)
		{
			arr[j + 1] = arr[j];//元素后移
			k = j;//找到要插入的位置
		}
		arr[k] = tmp;//插入元素
	}

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/**
 * 冒泡排序 相邻两个元素比较
 */
void bubbleSort(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[i])
			{
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/**
 * 希尔排序
 */
void shellSort(int *arr, int len)
{
	int k = 0;
	int tmp = -1;
	int gap = len;
	do 
	{
		gap = gap / 3 + 1;
		for (int i = 1; i < len; i+=gap)
		{
			k = i;
			tmp = arr[k];
			for (int j = i - gap; (j > 0) && (arr[j] > tmp); j-=gap)
			{
				arr[j + gap] = arr[j];
				k = j;
			}
			arr[k] = tmp;
		}
	} while (gap>1);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int a[] = { 2,12,3,5,8 };

	int len = sizeof(a) / sizeof(*a);
	selectSort(a,len);
	insertSort(a, len);
	bubbleSort(a,len);
	shellSort(a, len);
	return 0;
}