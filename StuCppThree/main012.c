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


int paritition(int *arr,int low, int high)
{
	int pv = arr[low];
	while (low < high)
	{
		while (low < high && (arr[high] >= pv))
		{
			high--;
		}
		myswap(arr, low, high);
		while (low < high && (arr[low] <= pv))
		{
			low++;
		}
		myswap(arr, low, high);
	}
	return low;
}

void qSort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pv = paritition(arr,low, high);
		qSort(arr, low, pv - 1);
		qSort(arr, pv + 1, high);
	}
}
/**
 * ��������
 */
void quickSort(int *arr, int len)
{
	qSort(arr, 0, len - 1);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/**
 * �鲢����
 */
void myMerage(int *src, int *des, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (src[i]<src[j])
		{
			des[k++] = src[i++];
		}
		else {
			des[k++] = src[j++];
		}
	}
	while (i <= mid)
	{
		des[k++] = src[i++];
	}
	while (j <= right)
	{
		des[k++] = src[j++];
	}
}

void msort(int *src, int *des, int left, int right, int max)
{
	if (left == right)
	{
		des[left] = src[left];
	}
	else {
		int mid = (left + right) / 2;
		int *space = (int *)malloc(sizeof(int)*max);
		if (space != NULL)
		{
			msort(src, space, left,mid,max);
			msort(src, space, mid+1,right,max);
			myMerage(space, des, left, mid, right);
			free(space);
		}
	}
}

void mergeSort(int *arr,int len)
{
	msort(arr, arr, 0, len - 1, len);
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
	quickSort(a, len);
	mergeSort(a, len);
	return 0;
}