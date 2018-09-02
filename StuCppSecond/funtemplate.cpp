#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

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
int mainf01()
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
 * 1.函数模板当函数参数
 * 2.调用模板函数,会严格的按照参数类型进行匹配,不会进行自动类型转换
 * 3.普通函数的调用,可以进行隐式的类型转换
 * 4.编译器从函数模板通过具体类型产生不同的函数,编译器会对函数模板进行两次编译,
 *			在声明的地方对模板代码本身进行编译,在调用的地方对参数进行替换后的代码进行编译,
 *			相同类型的多次调用只会编译一次
 * 5.当模板函数和普通函数都符合调用时,优先选择普通函数
 */
int mainf02()
{

	int a[] = {33,12,8,1,0,55,88,31,8,6};
	int size = sizeof(a) / sizeof(*a);
	mySort<int,int>(a, size);
	myprint<int,int>(a, size);


	printf("\n");
//	char *buf = "adaqejqpejqada";//error 字符串常量不可改变 交换顺序的时候改变了 程序段错误
	char buf[] = "kdladapzopadaqejqpejqada";
	int len = strlen(buf);
	mySort<char,int>(buf, len);
	myprint<char,int>(buf, len);
	return 0;
}