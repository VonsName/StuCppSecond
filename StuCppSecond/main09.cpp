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
using namespace std;


//函数指针做函数参数
void showFunElement(int &t)
{
	cout << t << " ";
}

//仿函数对象
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
	//函数指针做函数参数，回调函数，参数是函数的入口地址
	for_each(v1.begin(), v1.end(), showFunElement);
	printf("\n");
	//仿函数对象做函数参数
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
	//回调函数,函数的入口地址
	transform(v1.begin(), v1.end(), v1.begin(), increasem);
	
	for (int a:v1)
	{
		cout << a << " ";
	}
	printf("\n");
	//仿函数对象
	transform(v1.begin(), v1.end(), v1.begin(), MyIncreate());
	for (int a : v1)
	{
		cout << a << " ";
	}
	printf("\n");
	//预定义函数对象
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
	//#include <iterator> 直接输出到屏幕
	transform(v1.begin(), v1.end(),ostream_iterator<int>(cout," "),negate<int>());
}
/**
 * stl常用算法
 * transform()参数中的回调函数以及仿函数对象必须要有返回值
 *					错误:->error C2440: “=”: 无法从“void”转换为“int”
 *							void 类型的表达式不能转换为其他类型
 * for_each();
 */
int main0901(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	
//	main09_for_each();
	main09_transform();
	return 0;
}


//查找重复的两个相邻的元素
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
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有" << endl;
	}

	//distance 根据迭代器 得到迭代器所在的下标
	int index = distance(v1.begin(), it);
	cout << "相邻的两个重复元素第一个下标的位置为: " << index << endl;
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
	cout << "大于3的元素有:" << num << "个" << endl;
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
		cout << "找到了" << endl;
	}
}

/**
 * stl查找相关算法
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

void main_set_intersection()
{
	set<int> v1{ 1,3,5,2,6,9 };
	set<int> v2{ 2,4,6,3,10 };
	set<int> v3;
	//并集
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3, v3.begin()));
	for (int i:v3)
	{
		cout << i << " ";
	}
	v3.clear();
	printf("\n");
	//交集
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3, v3.begin()));
	for (int i : v3)
	{
		cout << i << " ";
	}
	v3.clear();
	printf("\n");
	//差集
	set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), inserter(v3, v3.begin()));
	for (int i : v3)
	{
		cout << i << " ";
	}
}

/**
 * 排序相关算法
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	main_merge();
	main_set_intersection();
	return 0;
}