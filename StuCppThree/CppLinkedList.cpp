#include <string.h>
#include "CppLinkedList.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;



template <typename T>
CppLinkedList<T>::CppLinkedList()
{
	this->header = new Node<T>;
	memset(this->header, 0, sizeof(this->header));
	this->header->next = nullptr;
	this->length = 0;
}

template <typename T>
CppLinkedList<T>::~CppLinkedList()
{
	if (this->header != NULL)
	{
		Node<T> *current = NULL;
		while (this->header)
		{
			current = this->header->next;
			delete this->header;
			this->header = current;
		}
		this->header = nullptr;
		this->length = 0;
	}
}

template<typename T>
int CppLinkedList<T>::insertV(T value)
{
	Node<T> *newNode = new  Node<T>;
	newNode->value = value;
	newNode->next = this->header->next;
	this->header->next = newNode;
	this->length++;
	return 0;
}

template<typename T>
int CppLinkedList<T>::deleteNode(int pos)
{
	if (pos < 0)
	{
		cout << "deleteNode参数错误" << endl;
		return NULL;
	}
	Node<T> *current = this->header;
	Node<T> *res = NULL;
	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	res = current->next;
	current->next = res->next;
	delete res;
	this->length--;
	return 0;
}

template<typename T>
Node<T> *CppLinkedList<T>::getNode(int pos)
{
	if (pos < 0)
	{
		cout << "deleteNode参数错误" << endl;
		return nullptr;
	}
	Node<T> *current = NULL;
	current = this->header;
	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	return current->next;
}

template<typename T>
int CppLinkedList<T>::getLen()
{
	return this->length;
}
