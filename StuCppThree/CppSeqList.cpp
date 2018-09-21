#include "CppSeqList.h"


template <typename T>
CppSeqList<T>::CppSeqList()
{
	this->capacity = 10;
	this->len = 0;
	this->data = new T[this->capacity];
}


template <typename T>
CppSeqList<T>::~CppSeqList()
{
	if (this->data != nullptr)
	{
		delete[] this->data;
	}
	this->capacity = 0;
	this->len = 0;
}

template<typename T>
T CppSeqList<T>::insert(T & data, int pos)
{
	if (pos<0 || pos>this->len)
	{
		return nullptr;
	}
	int i = 0;
	for (i= this->len; i > pos; i--)
	{
		this->data[i] = this->data[i - 1];
	}
	this->data[i] = data;
	this->len++;
	return data;
}

template <typename T>
T CppSeqList<T>::insert(T &data)
{
	this->data[this->len++] = data;
	return data;
}

template<typename T>
T CppSeqList<T>::getData(int pos)
{
	if (pos<0 || pos>this->len)
	{
		return NULL;
	}
	return this->data[pos];
}


template <typename T>
CppSeqList<T>::CppSeqList(int capacity)
{
	this->capacity = capacity;
	this->len = 0;
	this->data = new T[capacity];
}