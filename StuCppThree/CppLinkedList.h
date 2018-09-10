#pragma once

template <typename T>
class Node;

template <typename T>
class CppLinkedList
{
public:
	CppLinkedList();
	~CppLinkedList();
	
public:
	Node<T> *header;
	int length;
public:
	int insertV(T value);
	int deleteNode(int pos);
	Node<T>* getNode(int pos);
	int getLen();
};

template <typename T>
class Node
{
public:
	Node *next;
	T value;
public:
	Node()
	{
		this->next = nullptr;
	}
};

