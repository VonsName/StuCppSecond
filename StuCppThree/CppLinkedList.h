#pragma once
template <typename T>
class CppLinkedList
{
public:
	CppLinkedList();
	~CppLinkedList();
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
public:
	Node *header;
	int length;
};

