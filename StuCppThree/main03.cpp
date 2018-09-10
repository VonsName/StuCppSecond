#include <iostream>
#include "CppLinkedList.cpp"
using namespace std;


class Book
{
public:
	int no;
protected:
private:
};
int main0301(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	CppLinkedList<Book> list;
	Book b1, b2, b3;
	b1.no = 1;
	b2.no = 2;
	b3.no = 3;
	list.insertV(b1);
	list.insertV(b2);
	list.insertV(b3);
	for (int i = 0; i < list.getLen(); i++)
	{
		Node<Book> *tmp = list.getNode(i);
		cout << tmp->value.no << endl;
	}
	list.deleteNode(0);
	for (int i = 0; i < list.getLen(); i++)
	{
		Node<Book> *tmp = list.getNode(i);
		cout << tmp->value.no << endl;
	}
	return 0;
}