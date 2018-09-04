#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;


/**
 * ������Ż�������
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
	//ͳ��Ԫ�س��ֵĴ���
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

	//����()
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

	//����=
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
 * ������������� �����������ָ��Ԫ�أ�����Ҫ���Ա�����(��д�������캯��)
 * ����=  ()������
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

	//������()�Ų�����,������Ҳ����ÿ������캯��
	Man m5(m1);

	m5(m2);
}

/**
 * �����洢ָ������
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


	//��ʼ���ļ��ַ�ʽ
	vector<int> v1(v);
	vector<int> v2(10, 0);
	cout << v2.front() << endl;
	cout << v1.front() << endl;
	vector<int> v3(v1.begin(), v1.end());
	cout << v3.back() << endl;
	cout << v3.front() << endl;


	//vectorͨ��[]��ʽ���Ԫ�ص�ʱ��,һ��Ҫ�ȳ�ʼ�����ĳ���
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
	{  //error ��ѭ�� ��һֱ��β�����Ԫ�أ��������ʼ��ǰ��10����ֵ 
		v5.push_back(i + 2);
	}*/
	v5.push_back(100);//��10��0�������Ԫ��
	v5.push_back(200);
	for (unsigned int i = 0; i < v5.size(); i++)
	{
		cout << v5[i] << " ";
	}
	printf("\n");
	cout << v5.size() << endl;//���12
}

/**
 * stl
 * 1.vector :�ڲ���������ķ�ʽ�洢��,�洢�ռ���������
 *			:���������ȡԪ�أ�Ҳ����ͨ������,��ȡԪ�ص��ٶȿ�
 *			:���м�ɾ��Ԫ�ؽ��������Ԫ����
 *			:push_back(): ��β������Ԫ��
 *			:back(): ����β����Ԫ��,���ص�������
 *			:pop_back() ɾ��β��Ԫ��
 *			:front():����ͷ��Ԫ�أ�����һ������
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//test01vec();
//	test02vec();
	//test03vec();
	testvec04();
	return 0;
}