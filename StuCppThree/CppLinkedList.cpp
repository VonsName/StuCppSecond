#include "CppLinkedList.h"
#include <string.h>


template <typename T>
CppLinkedList<T>::CppLinkedList()
{
	this->header = new Node;
	memset(this->header, 0, sizeof(this->header));
	this->header->next = nullptr;
	this->length = 0;
}

template <typename T>
CppLinkedList<T>::~CppLinkedList()
{
}
