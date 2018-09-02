#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "MyArrays.cpp"

using namespace std;


class Teacher
{
public:
	Teacher()
	{
		this->name = new char[1];
		strcpy(this->name, "");
	}
	Teacher(const char *name,int no)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		//memcpy(this->name, name, len);
		strcpy(this->name, name);
		this->no = no;
	}
	Teacher(const Teacher &t)
	{
		int len = strlen(t.getName()) + 1; //const�����ܵ��÷�const����
		this->name = new char[len];
		strcpy(this->name, t.getName());
		this->no = t.getNo();
	}
	~Teacher()
	{
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
	}
	char *getName() const //const�����ܵ��÷�const����
	{
		return this->name;
	}
	int getNo() const //const�����ܵ��÷�const����
	{
		return this->no;
	}
public:
	Teacher& operator=(const Teacher &t);
	
protected:
private:
	char *name;
	int no;
};

Teacher & Teacher::operator=(const Teacher &t)
{
	if (this->name != NULL)
	{
		delete[] this->name;
		this->name = NULL;
		this->no = 0;
	}
	this->name = new char[strlen(t.getName()) + 1];
	strcpy(this->name, t.getName());
	this->no = t.getNo();
	return *this;
}

/**
 * ps:ע��->����ִ�в���Ԫ�صĲ�����ʱ��,�ڲ����е��ǿ�������,Ĭ��ִ�е���
 * �����Ĭ�Ͽ�������(ǳ����),=�Ÿ�ֵ����Ҳ��ǳ����,�����ڶ������ʱ�����
 * �Լ���д�������캯���Լ�=�Ÿ�ֵ�����������
 * Ҳ���������е�Ԫ�ر�������������(�ṩ�������캯��)
 */
//�����ڴ洢Ԫ��
int mainarr01(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Teacher t1("lisi", 1);
	Teacher t2("wangwu", 2);
	Teacher t3("zhaoliu", 3);

	MyArrays<Teacher,int> arr(3);

	arr[0] = t1;
	arr[1] = t2;
	arr[2] = t3;
	for (int i=0;i<arr.length();i++)
	{
		printf("%s %d\n", arr[i].getName(), arr[i].getNo());
	}

	MyArrays<Teacher, int> arr1=arr;
	for (int i = 0; i < arr1.length(); i++)
	{
		printf("%s %d\n", arr1[i].getName(), arr1[i].getNo());
	}

	MyArrays<Teacher, int> arr2(5);
	arr2 = arr1;
	for (int i = 0; i < arr2.length(); i++)
	{
		printf("%s %d\n", arr2[i].getName(), arr2[i].getNo());
	}

	return 0;
}

/**
 * �����ڴ洢ָ��
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Teacher t1("lisi", 1);
	Teacher t2("wangwu", 2);
	Teacher t3("zhaoliu", 3);

	MyArrays<Teacher*, int> arr(3);

	arr[0] = &t1;
	arr[1] = &t2;
	arr[2] = &t3;
	for (int i = 0; i < arr.length(); i++)
	{
		printf("%s %d\n", arr[i]->getName(), arr[i]->getNo());
	}

	MyArrays<Teacher*, int> arr1(5);
	arr1 = arr;
	for (int i = 0; i < arr1.length(); i++)
	{
		printf("%s %d\n", arr1[i]->getName(), arr[i]->getNo());
	}
}