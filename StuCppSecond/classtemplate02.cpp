#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ComplexTest.hpp"

using namespace std;

int maincl005(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	ComplexTest<int> c1(1, 2);
	cout << c1;

	ComplexTest<int> c2(3, 5);
	cout << c2;



	ComplexTest<int> c3 = c1 + c2;
	cout << c3;


	ComplexTest<int> c5 = c2 - c1;
	cout << c5;


	ComplexTest<int> c6 = myadd1(c1, c2);
	cout << c6;


	///////////////////////////////////////////////////////////
	cout << ComplexTest<int>::total << endl;


	//模板类和静态成员变量在一起的时候,不同类型的变量的值不会共用
	ComplexTest<double>::total = 11.11;
	cout << ComplexTest<double>::total << endl;


	
	//模板类和静态成员变量在一起的时候,不同类型的变量的值不会共用
	//同类型的模板类的静态成员变量才会共用一个变量的值
	//ComplexTest<float>::total = 12.6;
	cout << ComplexTest<float>::total << endl;//这里float如果没有初始化,输出10,最开始的默认的初始化值

	//ComplexTest<char>::total = 'c';
	cout << ComplexTest<char>::total << endl;//char 类型的如果没有初始化,输出为空字符串

	return 0;
}