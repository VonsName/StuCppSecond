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


	//ģ����;�̬��Ա������һ���ʱ��,��ͬ���͵ı�����ֵ���Ṳ��
	ComplexTest<double>::total = 11.11;
	cout << ComplexTest<double>::total << endl;


	
	//ģ����;�̬��Ա������һ���ʱ��,��ͬ���͵ı�����ֵ���Ṳ��
	//ͬ���͵�ģ����ľ�̬��Ա�����ŻṲ��һ��������ֵ
	//ComplexTest<float>::total = 12.6;
	cout << ComplexTest<float>::total << endl;//����float���û�г�ʼ��,���10,�ʼ��Ĭ�ϵĳ�ʼ��ֵ

	//ComplexTest<char>::total = 'c';
	cout << ComplexTest<char>::total << endl;//char ���͵����û�г�ʼ��,���Ϊ���ַ���

	return 0;
}