#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


/**
 * 函数模板
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
 * 函数模板,让类型参数化,泛型编程
 */
int main01(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	int a = 10, b = 20;
	myswap<int>(a, b);//函数模板调用->显示调用
	printf("%d %d \n", a, b);
	char x = 'a', y = 'b';
	myswap<char>(x, y);
	printf("%c %c \n", x, y);

	myswap(a, b);//函数模板调用->自动类型推导


	return 0;
}


/**
 * 函数模板当函数参数
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	int a[] = {33,12,8,1,0,55,88,31,8,6};
	int size = sizeof(a) / sizeof(*a);
	mySort(a, size);
	myprint(a, size);
	return 0;
}