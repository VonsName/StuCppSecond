#define  _CRT_SECURE_NO_WARNINGS
#include "MyException.h"



MyException::MyException(const char *p) :exception(p)
{
	if (p == NULL)
	{
		return;
	}
	int len = strlen(p) + 1;
	this->p = new char[len];
	strcpy(this->p, p);
}


MyException::~MyException()
{
}

