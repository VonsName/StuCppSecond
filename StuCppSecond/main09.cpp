#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <functional>
#include <iterator>
#include <numeric>
using namespace std;


//����ָ������������
void showFunElement(int &t)
{
	cout << t << " ";
}

//�º�������
struct ShowFunObj 
{
	void operator()(int &t)
	{
		cout << t << " ";
	}
};

///
void main09_for_each()
{
	vector<int> v1{ 1,7,5,6,8,9,3 };
	//����ָ���������������ص������������Ǻ�������ڵ�ַ
	for_each(v1.begin(), v1.end(), showFunElement);
	printf("\n");
	//�º�����������������
	for_each(v1.begin(), v1.end(), ShowFunObj());
}


int increasem(int a)
{
	return a + 100;
}
struct MyIncreate 
{
	int operator()(int a)
	{
		return a + 100;
	}
};

//
void main09_transform()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	//�ص�����,��������ڵ�ַ
	transform(v1.begin(), v1.end(), v1.begin(), increasem);
	
	for (int a:v1)
	{
		cout << a << " ";
	}
	printf("\n");
	//�º�������
	transform(v1.begin(), v1.end(), v1.begin(), MyIncreate());
	for (int a : v1)
	{
		cout << a << " ";
	}
	printf("\n");
	//Ԥ���庯������
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
	for (int a : v1)
	{
		cout << a << " ";
	}
	printf("\n");
	transform(v1.begin(), v1.end(), v1.begin(), bind2nd(multiplies<int>(), 10));
	for (int a : v1)
	{
		cout << a << " ";
	}
	printf("\n");
	//#include <iterator> ֱ���������Ļ
	transform(v1.begin(), v1.end(),ostream_iterator<int>(cout," "),negate<int>());
}
/**
 * stl�����㷨
 * transform()�����еĻص������Լ��º����������Ҫ�з���ֵ
 *					����:->error C2440: ��=��: �޷��ӡ�void��ת��Ϊ��int��
 *							void ���͵ı��ʽ����ת��Ϊ��������
 * for_each();
 */
int main0901(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	
//	main09_for_each();
	main09_transform();
	return 0;
}


//�����ظ����������ڵ�Ԫ��
void main_adjacent()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(5);
	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if (it != v1.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û��" << endl;
	}

	//distance ���ݵ����� �õ����������ڵ��±�
	int index = distance(v1.begin(), it);
	cout << "���ڵ������ظ�Ԫ�ص�һ���±��λ��Ϊ: " << index << endl;
}



void main_count_if()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(5);

	int num=count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 3));
	cout << "����3��Ԫ����:" << num << "��" << endl;
}


void main_binary_search()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	bool b=binary_search(v1.begin(), v1.end(), 5);
	if (b)
	{
		cout << "�ҵ���" << endl;
	}
}

/**
 * stl��������㷨
 */
int main0902(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	main_adjacent();
//	main_count_if();
//	main_binary_search();
	return 0;
}


bool daYu3(int a,int b)
{
	if (a>b)
	{
		return true;
	}
	return false;
}

void main_merge()
{
	vector<int> v1{1,3,5};
	vector<int> v2{2,4,6};
	vector<int> v3(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (int i:v3)
	{
		cout << i << " ";
	}
}


/**
 * ���������
 */
void main_set_intersection()
{
	set<int> v1{ 1,3,5,2,6,9 };
	set<int> v2{ 2,4,6,3,10 };
	set<int> v3;
	//����
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3, v3.begin()));
	for (int i:v3)
	{
		cout << i << " ";
	}
	v3.clear();
	printf("\n");
	//����
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3, v3.begin()));
	for (int i : v3)
	{
		cout << i << " ";
	}
	v3.clear();
	printf("\n");
	//�
	set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), inserter(v3, v3.begin()));
	for (int i : v3)
	{
		cout << i << " ";
	}
}


class Students
{
public:
	Students(string name, int id)
	{
		this->name = name;
		this->id = id;
	}

protected:
public:
	string name;
	int id;
};

bool CompareStudent(const Students& s1,const Students &s2)
{
	return (s1.id < s2.id);
}
void main_sort()
{
	Students s1("lisi", 1);
	Students s2("wangqu", 2);
	Students s3("zhangsan", 3);
	Students s4("zhaokiu", 4);
	vector<Students> v1;
	v1.push_back(s3);
	v1.push_back(s2);
	v1.push_back(s4);
	v1.push_back(s1);
	for (Students item:v1)
	{
		cout << item.id << "\t" << item.name << endl;
	}
	sort(v1.begin(), v1.end(), CompareStudent);
	printf("\n");
	for (Students item : v1)
	{
		cout << item.id << "\t" << item.name << endl;
	}
}

void main_copy()
{
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(3);

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for (int i:v2)
	{
		cout << i << " ";
	}
	printf("\n");
	replace(v2.begin(), v2.end(), 3, 30);
	for (int i : v2)
	{
		cout << i << " ";
	}
	replace_if(v2.begin(), v2.end(), bind2nd(greater<int>(), 3), 99);
	printf("\n");
	for (int i : v2)
	{
		cout << i << " ";
	}
	printf("\n");
	swap(v1,v2);
	for (int i : v2)
	{
		cout << i << " ";
	}
	printf("\n");
	for (int i : v1)
	{
		cout << i << " ";
	}
}
/**
 * ��������㷨
 */
int main0903(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	main_merge();
//	main_set_intersection();
//	main_sort();
//	random_shuffle()//�������
//	reverse() //����
	main_copy();
//	fill()
//	accumulate()
	return 0;
}