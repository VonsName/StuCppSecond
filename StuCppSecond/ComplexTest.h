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
	


	

	//成员函数重载-
	ComplexTest operator-(const ComplexTest<T> &c);


	//成员函数重载操作符+
	//MyComplex operator+(const MyComplex<T> &c1);


	//友元函数重载操作符+
	friend ComplexTest<T> operator+<T>(ComplexTest<T> &c1, ComplexTest<T> &c2);


	//友元函数重载 <<
	friend ostream& operator <<<T>(ostream &out, ComplexTest<T> &c);


	//滥用友元函数
	friend ComplexTest<T> myadd1<T>(ComplexTest<T> &c1, ComplexTest<T> &c2);

	//int getTotak();
	
	
protected:
private:
	T a;
	T b;
public:

	static T total;
};



