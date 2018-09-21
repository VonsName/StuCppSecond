#pragma once

template <typename T>
class CppSeqList
{
public:
	CppSeqList();
	CppSeqList(int capacity);
	~CppSeqList();

public:
	T insert(T &data, int pos);
	T insert(T &data);
	T getData(int pos);
public:
	T *data;
	int len;
	int capacity;
};



