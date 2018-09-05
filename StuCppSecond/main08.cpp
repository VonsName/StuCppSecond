#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <vector>
using namespace std;


//�º�������
template <typename T>
class FunShow
{
public:
	FunShow()
	{
		n = 0;
	}
	void operator()(T &t)
	{
		n++;
		cout << t << " ";
		//print_n();
	}
	void print_n()
	{
		cout << "n= " << n << endl;
	}
protected:
private:
	int n;
};


//�º���
template <typename T>
class IsDiv
{
public:
	IsDiv(T diver)
	{
		this->diver = diver;
	}
public:
	bool operator()(T &t)
	{
		return (t % this->diver == 0);
	}
protected:
private:
	T diver;
};


//ģ�庯��
template <typename T>
void funShowEle(const T &t)
{
	cout << t << " ";
}


void testfunobj()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	//FunShow<int>() �����º�������
//	for_each(v1.begin(), v1.end(), FunShow<int>());

	printf("\n");
	//funShowEle<int> �ص���������ڵ�ַ
//	for_each(v1.begin(), v1.end(), funShowEle<int>);

	//�º�������
	FunShow<int> show;
//	IsDiv<int> isdiv(2);
	//�º�����������������,for_each()�㷨������ر�������������ĺ�������
	show=for_each(v1.begin(), v1.end(), show);
	//ͨ��for_each�㷨�ķ��ؽ���鿴�º��������״̬
	show.print_n();
}

/**
 * �㷨
 * 1.��������:�����˺������÷�()����Ķ���,��Ϊ���ƺ��� 
 *					:���Ա��ֵ���״̬
 */

int main08001(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	testfunobj();
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////



void testfunobj01()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(8);

	int a = 4;
	//�º�������,һ��������,����ֵ��bool ����Ҳ���Խ�һԪν��
	IsDiv<int> divor(a);

	//find_if�㷨����һ��������
	//vector<int>::iterator it=find_if(v1.begin(), v1.end(),IsDiv<int>(a));//һԪν��
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), divor);//һԪν��
	if (it != v1.end())
	{
		cout << "vector�е�һ���ܱ�" << a<< "����������:" << *it << endl;
	}
	else
	{
		cout << "vector��û���ܱ�" << a << "��������" << endl;
	}

}

/**
 * 1.һԪ��������:�º����Ĳ�����һ��
 * 2.һԪν��:����������һ��,�ҷ���ֵ��bool����,������Ϊһ���ж�ʽ,
 *					ν�ʿ�����һ���º���,Ҳ������һ���ص�����;
 * 3.��Ԫν��:����������2��,�ҷ���ֵ��bool����;
 */

//12-->09��ʱ��ʼ
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	testfunobj01();
	return 0;
}