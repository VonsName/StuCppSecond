#define _CRT_SECURE_NO_WARNINGS
#include "ComplexTest.h"
#include <iostream>

using namespace std;





template <typename T>
ComplexTest<T>::ComplexTest()
{
}


template <typename T>
ComplexTest<T>::~ComplexTest()
{
}

template<typename T>
ComplexTest<T>::ComplexTest(T a, T b)
{
	this->a = a;
	this->b = b;
}


//��Ա��������-
template<typename T>
ComplexTest<T> ComplexTest<T>::operator-(const ComplexTest<T>& c)
{
	this->a = this->a - c.a;
	this->b = this->b - c.b;
	return *this;
}


//��Ԫ��������+
template <typename T>
ComplexTest<T> operator+(ComplexTest<T>& c1, ComplexTest<T>& c2)
{
	ComplexTest<T> tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}


//��Ԫ��������<<
template <typename T>
ostream & operator<<(ostream & out, ComplexTest<T>& c)
{
	out << c.a << "--" << c.b << endl;
	return out;
}


//������Ԫ����
template <typename T>
 ComplexTest<T> myadd1(ComplexTest<T>& c1, ComplexTest<T>& c2)
{
	ComplexTest<T> tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

 template <typename T> T ComplexTest<T>::total = 2;
 /*template <typename T>
 int ComplexTest<T>::getTotak()
 {
	 return total;
 }*/