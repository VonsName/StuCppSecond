#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

/**
 * ¼Ì³Ð±ê×¼¿âÒì³£
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

