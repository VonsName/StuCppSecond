#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


template <typename T>
class MyComplex;


template <typename T>
MyComplex<T> myadd(MyComplex<T> &c1, MyComplex<T> &c2);



template <class T>
class MyComplex
{
public:
	MyComplex()
	{

	}
	MyComplex(T a, T b)
	{
		this->a = a;
		this->b = b;
	}


	

	//��Ա��������-
	MyComplex operator-(const MyComplex<T> &c);


	//��Ա�������ز�����+
	//MyComplex operator+(const MyComplex<T> &c1);


	//��Ԫ�������ز�����+
	friend MyComplex<T> operator+<T>(MyComplex<T> &c1, MyComplex<T> &c2);


	//��Ԫ�������� <<
	friend ostream& operator <<<T>(ostream &out, MyComplex<T> &c);

	/*friend MyComplex operator+(MyComplex &c1, MyComplex &c2)
	{
		MyComplex<T> tmp(c1.a + c2.a, c1.b + c2.b);
		return tmp;
	}*/


	//������Ԫ����
	friend MyComplex<T> myadd<T>(MyComplex<T> &c1, MyComplex<T> &c2);
	

protected:
private:
	T a;
	T b;
};


/**
 * ��Ա��������+
 */
//template <typename T>
//MyComplex<T> MyComplex<T>::operator+(const MyComplex<T> &c1)
//{
//	this->a = this->a + c1.a;
//	this->b = this->b + c1.b;
//	return *this;
//}



//��Ա��������-�Ų�����
template <typename T>
MyComplex<T> MyComplex<T>::operator-(const MyComplex<T> &c)
{
	this->a = this->a - c.a;
	this->b = this->b - c.b;
	return *this;
}


/**
 * ʹ����Ԫ��������<<����������ģ�����ʱ��
 * ��������д��->friend ostream& operator <<<T>(ostream &out, MyComplex &c);
 */
template <typename T>
ostream& operator<<(ostream &out, MyComplex<T> &c)
{
	out << c.a << "--" << c.b << endl;
	return out;
}


/**
 * ��Ԫ�������ز�����+
 */
template <typename T>
MyComplex<T> operator+(MyComplex<T> &c1, MyComplex<T> &c2)
{
	MyComplex<T> tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}


////////////////////////////////////////////////////////////////////////////////
/**
 * friend MyComplex myadd(MyComplex &c1, MyComplex &c2);
 */

//������Ԫ����
template <typename T>
MyComplex<T> myadd(MyComplex<T> &c1, MyComplex<T> &c2)
{
	MyComplex<T> tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}
////////////////////////////////////////////////////////////////////////////////




int main003(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	
	MyComplex<int> c1(1, 2);
	cout << c1;

	MyComplex<int> c2(3, 5);
	cout << c2;

//	MyComplex<int> c3 = c1 + c2;
	//cout << c3;


	MyComplex<int> c3=c1 + c2;
	cout << c3;


	MyComplex<int> c5 = c2 - c1;
	cout << c5;


	MyComplex<int> c6=myadd(c1, c2);
	cout << c6;
	return 0;
}