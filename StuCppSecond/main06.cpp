#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;


/**
 * 容器存放基础类型
 */
void test01vec()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);
	v.push_back(3);
	for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
	//统计元素出现的次数
	int num = count(v.begin(), v.end(), 3);
	cout << "num:" << num << endl;
}

class Man
{
public:
	Man(int age,char *name)
	{
		this->age = age;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	Man(const Man &m)
	{
		this->name = new char[strlen(m.name) + 1];
		this->age = m.age;
		strcpy(this->name, m.name);
	}
	~Man()
	{
		if (this->name != NULL)
		{
			delete[] this->name;
		}
	}
	int age;
	char *name;
public:

	//重载()
	Man& operator()(const Man &m)
	{
		if (this->name != NULL);
		{
			delete[] this->name;
			this->age = 0;
		}
		this->name = new char[strlen(m.name) + 1];
		strcpy(this->name, m.name);
		this->age = m.age;
		return *this;
	}

	//重载=
	Man& operator=(const Man &m)
	{
		if (this->name != NULL);
		{
			delete[] this->name;
			this->age = 0;
		}
		this->name = new char[strlen(m.name) + 1];
		strcpy(this->name, m.name);
		this->age = m.age;
		return *this;
	}
protected:
private:
	
};

/**
 * 容器存放类类型 改类型如果有指针元素，必须要可以被拷贝(重写拷贝构造函数)
 * 重载=  ()操作符
 */
void test02vec()
{
	Man m1(12,"lisi");
	Man m2(23,"wangwu");
	Man m3(8,"zhaoliu");
	vector<Man> v;
	v.push_back(m1);
	v.push_back(m2);
	v.push_back(m3);
	for (vector<Man>::iterator it=v.begin();it!=v.end();it++)
	{
		cout << it->age << " " << it->name <<endl;
	}

	//重载了()号操作符,编译器也会调用拷贝构造函数
	Man m5(m1);

	m5(m2);
}

/**
 * 容器存储指针类型
 */
void test03vec()
{
	Man m1(12,"lisi");
	Man m2(23,"zhaoliu");
	Man m3(8,"wangwu");

	Man *p1 = NULL;
	Man *p2 = NULL;
	Man *p3 = NULL;
	p1 = &m1;
	p2 = &m2;
	p3 = &m3;
	vector<Man *> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	for (vector<Man *>::iterator it=v.begin();it!=v.end();it++)
	{
		cout << (*it)->age << endl;
	}
}

void testvec04()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	cout << v.back() << endl;
	v.pop_back();
	cout << v.back() << endl;
	v.front() = 22;
	cout << v.front() << endl;


	//初始化的几种方式
	vector<int> v1(v);
	vector<int> v2(10, 0);
	cout << v2.front() << endl;
	cout << v1.front() << endl;
	vector<int> v3(v1.begin(), v1.end());
	cout << v3.back() << endl;
	cout << v3.front() << endl;


	//vector通过[]方式添加元素的时候,一定要先初始化它的长度
	for (unsigned int i = 0; i < v2.size(); i++)
	{
		v2[i] = i + 3;
	}

	for (unsigned int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	printf("\n");
	vector<int> v5(10, 0);
	/*for (unsigned int i = 0; i < v5.size(); i++)
	{  //error 死循环 会一直在尾部添加元素，而不会初始化前面10个的值 
		v5.push_back(i + 2);
	}*/
	v5.push_back(100);//在10个0后面添加元素
	v5.push_back(200);
	for (unsigned int i = 0; i < v5.size(); i++)
	{
		cout << v5[i] << " ";
	}
	printf("\n");
	cout << v5.size() << endl;//输出12
}

/**
 * stl
 * 1.vector :内部是以数组的方式存储的,存储空间是连续的
 *			:可以随机存取元素，也可以通过索引,获取元素的速度快
 *			:在中间删除元素较慢，添加元素慢
 *			:push_back(): 在尾部插入元素
 *			:back(): 返回尾部的元素,返回的是引用
 *			:pop_back() 删除尾部元素
 *			:front():返回头部元素，返回一个引用
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//test01vec();
//	test02vec();
	//test03vec();
	testvec04();
	return 0;
}