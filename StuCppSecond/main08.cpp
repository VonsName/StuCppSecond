#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <functional>
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


//һԪν��
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

//�º���
template <typename T>
class SumAdd
{
public:
	T operator()(T &t1,T &t2)
	{
		return t1 + t2;
	}
protected:
private:
};
//��Ԫ��������
void testfunobj02()
{
	vector<int> v1, v2;
	vector<int>	v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);
	v3.resize(v2.size());
	//����һ��Ŀ�������ĵ�����(�����ǵ���������)
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	for_each(v3.begin(), v3.end(), funShowEle<int>);//funShowEle<int>������ڵ�ַ
	printf("\n");
}


template <typename T>
bool myCompare(const int &a, const int &b)
{
	return a < b;
}

//��Ԫν��
void testfunobj03()
{
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(rand());
	}

	//myCompare<int> ��Ԫν��
	sort(v1.begin(), v1.end(), myCompare<int>);
	
	for_each(v1.begin(), v1.end(), funShowEle<int>);
}

/**
 * �º��� ��Ԫν�� ��set���ʹ��
 */
struct MyCompartByNoCase 
{
	//ע���������ص�operator()Ҳ������const�ģ��������ֶ�ʧconst�޶�������
	bool operator()( const string s1,const string s2)const
	{
		string tmp1;
		string tmp2;
		tmp1.resize(s1.size());
		tmp2.resize(s2.size());
		transform(s1.begin(), s1.end(), tmp1.begin(), tolower);
		transform(s2.begin(), s2.end(), tmp2.begin(), tolower);
		return (tmp1 < tmp2);
	}
};
//��Ԫν����set�е�Ӧ��
void testfunobj04()
{
	set<string, MyCompartByNoCase> s1;
	s1.insert("aaa");
	s1.insert("ccc");
	s1.insert("bbb");
	set<string, MyCompartByNoCase>::iterator it = s1.find("bBb");
	if (it != s1.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}

/**
 * 1.һԪ��������:�º����Ĳ�����һ��
 * 2.һԪν��:����������һ��,�ҷ���ֵ��bool����,������Ϊһ���ж�ʽ,
 *					ν�ʿ�����һ���º���,Ҳ������һ���ص�����;
 * 3.��Ԫν��:����������2��,�ҷ���ֵ��bool����;
 */

//12-->09��ʱ��ʼ
int main08002(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

//	testfunobj01();
//	testfunobj02();
//	testfunobj03();
	testfunobj04();
	string str = "aaaaa";
	cout << "str.size=" << str.size() << endl;
	cout << "str.length=" << str.length() << endl;
	return 0;
}




void testfunobj05()
{
	plus<int> intAdd;
	int a = 10;
	int b = 20;
	int z = intAdd(a, b);
	cout << "z=" << z << endl;

	plus<string> strAdd;
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = strAdd(s1, s2);
	cout << "s3=" << s3 << endl;
}

template <typename T>
struct MyOperationAdd
{
	T operator()(const T &t1, const T &t2) 
	{
		return t1 + t2;
	}
};


//�Զ��庯������
void testfunobj06()
{
	MyOperationAdd<int> myadd;
	int a = myadd(1, 2);
	cout << "a=" << a <<  endl;
}



//����������
void testfunobj07()
{
	vector<string> s1;
	s1.push_back("bbb");
	s1.push_back("ddd");
	s1.push_back("ccc");
	s1.push_back("aaa");
	s1.push_back("fff");
	s1.push_back("aaa");
	sort(s1.begin(), s1.end(), greater<string>());
	for (vector<string>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
	//bind2nd()��������������Ԥ���庯������͵ڶ����������а�
	int num=count_if(s1.begin(), s1.end(), bind2nd(equal_to<string>(), "aaa"));
	cout << "aaa���ֵĸ�����" << num << endl;
}


class MyGreater
{
public:
	MyGreater(int m)
	{
		this->m = m;
	}
	bool operator()(int a)
	{
		return a > m;
	}
protected:
private:
	int m;
};
/**
 * ����������
 */
void testfunobj08()
{
	vector < int> v1;
	for (unsigned int i = 0; i < 9; i++)
	{
		v1.push_back(i + 1);
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
	int num1 = count(v1.begin(), v1.end(), 2);
	int num2 = count_if(v1.begin(), v1.end(), MyGreater(2));
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
	//modulus() ȡ��
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	//not1() ȡ��
	int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "2�ĸ�����" << num1 << endl;
	cout << "����2�ĸ�����" << num2 << endl;
	cout << "����2�ĸ�����" << num3 << endl;
	cout << "����������" << num4 << endl;
	cout << "ż��������" << num5 << endl;
}

void testfunobj09()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);
	//ɾ��С�ڵ���2��Ԫ��
	vector<int>::iterator it=v1.erase(remove_if(v1.begin(), v1.end(), bind2nd(less_equal<int>(), 2)));
	for (; it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(5);
	//not1(bind1st(less<int>(), 2))) �൱��bind2nd(less_equal<int>(), 2)) С�ڵ���2
	//bind1st(less<int>(), 2)) ����2
	vector<int>::iterator it2 = v2.erase(remove_if(v2.begin(), v2.end(), not1(bind1st(less<int>(), 2))));
	for (; it2 != v2.end(); it2++)
	{
		cout << *it2 << " ";
	}
}

/**
 * Ԥ���庯������ͺ���������
 * 1.plus<int> ��ʵ�ֲ�ͬ��������֮������,ͨ����������(�º���)ʵ�ֵ�
 */
int main08003(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	testfunobj05();
//	testfunobj06();
//	testfunobj07();

	int a = 10;
	int *p = &a;
	//ָ�������
	int* &p1 = p;
	cout << "*p=" << *p << endl;
	cout << "*p1=" << *p1 << endl;
	return 0;
}

/**
 * make_heap��//����Χ�ڵ�Ԫ�ؽ��ɶѿ��Կ��ٵ�ȡ���䷶Χ�ڵ����ֵ
 * sort_heap��//ʹ��operator<���бȽϣ�ǰ���Ƿ�Χ�ڵ�Ԫ���Ѿ���һ�����ˣ���������
			//��������н�ʧȥ�ѵ����ԣ�
 *	
 */
void testfunobj010()
{
	vector<int> v1{ 1,7,5,6,8,9,3 };
	for each (int i in v1)
	{
		cout << i << " ";
	}
	cout << endl;
	printf("--\n");

//	sort_heap(v1.begin(), v1.end());//error ��ʱvector��Χ�е�Ԫ�ػ�����һ����
//	for each (int i in v1)
//	{
//		cout << i << " ";
//	}
	//����Χ�ڵ�Ԫ�ؽ��ɶѿ��Կ��ٵ�ȡ���䷶Χ�ڵ����ֵ
	make_heap(v1.begin(), v1.end());
	for each (int i in v1)
	{
		cout << i << " ";
	}
	cout << endl;
	printf("--\n");
	//ʹ��operator<���бȽϣ�ǰ���Ƿ�Χ�ڵ�Ԫ���Ѿ���һ�����ˣ���������
	//��������н�ʧȥ�ѵ����ԣ�
	sort_heap(v1.begin(), v1.end());
	for each (int i in v1)
	{
		cout << i << " ";
	}
}

/**
 * pop_heap������һ�����Ԫ���ƶ���end()��ǰ����
 *			 ͬʱ��ʣ�µ�Ԫ�����¹����һ���µ�heap		
 * push_heap:�Ըղ���ģ�β����Ԫ����������
 */
void testfunobj011()
{
	vector<int> v1{ 1,7,5,6,8,9,3 };
	make_heap(v1.begin(), v1.end());

	pop_heap(v1.begin(), v1.end());
	for each (int i in v1)
	{
		cout << i << " ";
	}
	printf("\n--\n");
	push_heap(v1.begin(), v1.end());
	for each (int i in v1)
	{
		cout << i << " ";
	}
}

//����������
int main08004(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	testfunobj08();
//	testfunobj09();
//	testfunobj010();
	testfunobj011();
	return 0;
}