#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;


/**
 * ����ģ��
 */
template <typename T>
void myswap(T &t1,T &t2)
{
	T tmp;
	tmp = t1;
	t1 = t2;
	t2 = tmp;
}


template <typename T,typename I>
void mySort(T *array, I size)
{
	I i = 0, j = 0;
	I tmp = 0;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}


template <typename T,typename I>
void myprint(T *array, I size)
{
	I i = 0;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

/**
 * ����ģ��,�����Ͳ�����,���ͱ��
 */
int mainf01()
{

	int a = 10, b = 20;
	myswap<int>(a, b);//����ģ�����->��ʾ����
	printf("%d %d \n", a, b);
	char x = 'a', y = 'b';
	myswap<char>(x, y);
	printf("%c %c \n", x, y);

	myswap(a, b);//����ģ�����->�Զ������Ƶ�


	return 0;
}


/**
 * 1.����ģ�嵱��������
 * 2.����ģ�庯��,���ϸ�İ��ղ������ͽ���ƥ��,��������Զ�����ת��
 * 3.��ͨ�����ĵ���,���Խ�����ʽ������ת��
 * 4.�������Ӻ���ģ��ͨ���������Ͳ�����ͬ�ĺ���,��������Ժ���ģ��������α���,
 *			�������ĵط���ģ����뱾����б���,�ڵ��õĵط��Բ��������滻��Ĵ�����б���,
 *			��ͬ���͵Ķ�ε���ֻ�����һ��
 * 5.��ģ�庯������ͨ���������ϵ���ʱ,����ѡ����ͨ����
 */
int mainf02()
{

	int a[] = {33,12,8,1,0,55,88,31,8,6};
	int size = sizeof(a) / sizeof(*a);
	mySort<int,int>(a, size);
	myprint<int,int>(a, size);


	printf("\n");
//	char *buf = "adaqejqpejqada";//error �ַ����������ɸı� ����˳���ʱ��ı��� ����δ���
	char buf[] = "kdladapzopadaqejqpejqada";
	int len = strlen(buf);
	mySort<char,int>(buf, len);
	myprint<char,int>(buf, len);
	return 0;
}