#pragma once

template <typename T,typename I>
class MyArrays
{
public:
	MyArrays<T,I>();
	MyArrays<T,I>(I size);
	MyArrays<T,I>(const MyArrays<T,I> &arr);
	~MyArrays();
public:
	T& operator[](I index);
	MyArrays& operator=(const MyArrays &arr);

	int length()
	{
		return this->size;
	}
private:
	T *data;
	I size;
};


//不能使用友元函数重载= -> () []号操作符  否则error ->"operator ="必须是非静态成员
//template<typename T, typename I>
//T & operator=(const T value, I index)  
//{
//	if (this->data != NULL)
//	{
//		this->data[index] = value;
//	}
//}



