#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

/**
 * �̳б�׼���쳣
 */
class MyException :public exception
{
public:
	MyException(const char *p);
	~MyException();
public:
	char const* what() const
	{
		cout << this->p << endl;
		return this->p;
	}
private:
	char *p;
};

