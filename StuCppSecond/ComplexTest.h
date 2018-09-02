#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;



template <typename T>
class ComplexTest;


template <typename T>
ComplexTest<T> myadd1(ComplexTest<T> &c1, ComplexTest<T> &c2);



template <typename T>
class ComplexTest
{
public:
	ComplexTest();

	~ComplexTest();

	ComplexTest(T a, T b);
	


	

	//��Ա��������-
	ComplexTest operator-(const ComplexTest<T> &c);


	//��Ա�������ز�����+
	//MyComplex operator+(const MyComplex<T> &c1);


	//��Ԫ�������ز�����+
	friend ComplexTest<T> operator+<T>(ComplexTest<T> &c1, ComplexTest<T> &c2);


	//��Ԫ�������� <<
	friend ostream& operator <<<T>(ostream &out, ComplexTest<T> &c);


	//������Ԫ����
	friend ComplexTest<T> myadd1<T>(ComplexTest<T> &c1, ComplexTest<T> &c2);

	//int getTotak();
	
	
protected:
private:
	T a;
	T b;
public:

	static T total;
};



