#include "MyArrays.h"
 #pragma warning (disable:4390) 

template <typename T, typename I>
MyArrays<T,I>::MyArrays()
{
	this->size = 5;
	this->data = new T[this->size];
}


template <typename T, typename I>
MyArrays<T,I>::~MyArrays()
{
	if (this->data != NULL);
	{
		delete[] this->data;
		this->data = NULL;
	}
}


//重载[]操作符 只能使用成员函数重载 ,还有 = -> ()
template<typename T, typename I>
T & MyArrays<T, I>::operator[](I index)
{
	return this->data[index];
}


/**
 * 重载=号操作符深拷贝
 * 拷贝构造函数,如果元素要向容器中存储,元素必须要有深拷贝
 */
template<typename T, typename I>
MyArrays<T, I> & MyArrays<T, I>::operator=(const MyArrays<T,I> & arr)
{
	if (this->data != NULL)
	{
		delete[] this->data;
		this->size = 0;
		this->data = NULL;
	}
	this->size = arr.size;
	this->data = new T[arr.size];
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = arr.data[i];
	}
	return *this;
}



template <typename T, typename I>
MyArrays<T, I>::MyArrays(I size)
{
	if (size == 0)
	{
		this->size = 5;
	}
	else 
	{
		this->size = size;
	}
	this->data = new T[this->size];
}


/**
 * 拷贝构造函数,如果元素要向容器中存储,必须重写拷贝构造函数进行深拷贝
 */
template<typename T, typename I>
MyArrays<T, I>::MyArrays(const MyArrays & arr)
{
	this->size = arr.size;
	this->data = new T[arr.size];
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = arr.data[i];
	}
}
