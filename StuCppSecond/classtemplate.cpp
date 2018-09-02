#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

template <typename T>
class TemClass
{
public:
	TemClass()
	{

	}
	TemClass(T a)
	{
		this->a = a;
	}
protected:
private:
	T a;
};


//从模板类派生普通类必须具体化模板类 类型参数
class TemClass1:public TemClass<int>
{
public:
	TemClass1()
	{

	}
	TemClass1(int a, int b) :TemClass<int>(a)
	{
		this->b = b;
	}
protected:
private:
	int b;
};



//从模板类派生模板类
template <typename T1>
class TemClass2:public TemClass<T1>
{
public:
	TemClass2()
	{

	}
	TemClass2(T1 a, T1 c) :TemClass<T1>(a)
	{
		this->c = c;
	}
	void print_t()
	{
		cout << c << endl;
	}
protected:
private:
	T1 c;
};

void test()
{
	cout << " --" << endl;
}

void test(int a)
{
	cout <<  a <<  " --" << endl;
}

void test(int a,int b)
{
	cout << a << b << " --" << endl;
}
int maincc0111(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	TemClass1 tc1(1,2);

	TemClass2<int> tc2(3, 5);
	tc2.print_t();

	test();
	test(1);
	test(1, 2);
	return 0;
}