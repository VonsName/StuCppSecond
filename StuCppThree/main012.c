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
 * ѡ������
 */
void selectSort(int *arr,int len)
{
	for (int i=0;i<len;i++)
	{
		int k = i;//��С
		for (int j=i+1;j<len;j++)
		{
			if (arr[j] < arr[k])//��һ��Ԫ�غ�ÿһ��Ԫ�رȽ�
			{
				k = j;//�Ƚϵó���С
			}
		}
		myswap(arr, k, i);//����
	}
	for (int i=0;i<len;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/**
 * ��������
 */
void insertSort(int *arr, int len)
{
	int k = 0;
	int tmp = -1;
	for (int i = 1; i < len; i++)
	{
		k = i;//�������λ��
		tmp = arr[k];//�������Ԫ��(��ǰ�Ƚϵ�Ԫ��)
		for (int j = i - 1; (j > 0) && (arr[j] > tmp); j--)
		{
			arr[j + 1] = arr[j];//Ԫ�غ���
			k = j;//�ҵ�Ҫ�����λ��
		}
		arr[k] = tmp;//����Ԫ��
	}

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/**
 * ð������ ��������Ԫ�رȽ�
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
 * ϣ������
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