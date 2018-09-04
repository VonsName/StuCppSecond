#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <functional>

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
		if (this->name != NULL)
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
		if (this->name != NULL)
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
void testvec05()
{
	vector<int> v2(5);
	for (unsigned int i = 0; i < v2.size(); i++)
	{
		v2[i] = i + 3;
	}

	//end();��λ�������������һ��Ԫ�صĺ���
	//�������
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}

	printf("\n");
	//������� rend()��λ������������һ��Ԫ�ص�ǰ��
	for (vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
	{
		cout << *it << " ";
	}

	//ֻ��������
	printf("\n");
	for (vector<int>::const_iterator it = v2.cbegin(); it != v2.cend(); it++)
	{
		cout << *it << " ";
	}
	//ֻ��������
	printf("\n");
	for (vector<int>::const_reverse_iterator it = v2.crbegin(); it != v2.crend(); it++)
	{
		cout << *it << " ";
	}
}


void testvec06()
{
	vector<int> v2(5);
	for (unsigned int i = 0; i < v2.size(); i++)
	{
		v2[i] = i + 3;
	}

	//����ɾ��
	v2.erase(v2.begin(), v2.begin()+3); //0 -3 ȫ��ɾ��
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}


	//ָ��λ��ɾ�� 
	vector<int>::iterator it=v2.erase(v2.end()-1); 
	//erase()���Զ��õ���������,ɾ��һ��Ԫ�ز�������һ����������λ��
	printf("\n");
	for (vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
	{
		cout << *it << " ";
	}

	//����
	printf("\n");
	v2.insert(v2.begin(), 3);
	v2.insert(v2.end(), 3, 5);
	for (vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
	{
		cout << *it << " ";
	}
}

/**
 *		//	vector<int>::const_pointer;
 *		//vector<int>::pointer
 *		//	vector<int>::const_reverse_iterator
 *		//	vector<int>::const_iterator
 * stl
 * 1.vector :�ڲ���������ķ�ʽ�洢��,�洢�ռ���������
 *			:���������ȡԪ�أ�Ҳ����ͨ������,��ȡԪ�ص��ٶȿ�
 *			:���м�ɾ��Ԫ�ؽ��������Ԫ����
 *			:push_back(): ��β������Ԫ��
 *			:back(): ����β����Ԫ��,���ص�������
 *			:pop_back() ɾ��β��Ԫ��
 *			:front():����ͷ��Ԫ�أ�����һ������
 */
int main06001(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	test01vec();
//	test02vec();
//	test03vec();
//	testvec04();
//	testvec05();
	testvec06();
	return 0;
}


void testdeque01()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(3);
	d1.push_back(5);
	d1.push_front(7);
	d1.push_front(9);
	d1.push_front(11);
	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)
	{
		cout << *it << " ";
	}

	d1.pop_back();//����β��Ԫ��
	d1.pop_front();//����ͷ��Ԫ��

	printf("\n");
	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	//���ݵ��������������±�
	deque<int>::iterator it=find(d1.begin(), d1.end(), 3);
	if (it != d1.end())
	{
		cout << "�����±�Ϊ: " << distance(d1.begin(), it) <<endl;
	}
	else
	{
		cout << "û���ҵ� " << endl;
	}
}


void teststack001()
{
	stack<int> s1;
	s1.push(1);
	s1.push(3);
	s1.push(5);

	while (!s1.empty())
	{
		cout << s1.top() << " ";//��ȡջ��Ԫ��
		s1.pop();//����ջ��Ԫ��
	}
}

void testqueue001()
{
	queue<int> q1;
	q1.push(3);//��β��,��ͷ��,�Ƚ��ȳ�
	q1.push(5);
	q1.push(7);
	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
}


/**
 * list����������� 
 */
void	testlist001()
{
	list<int> l1;
	l1.push_back(1);//β�巨
	l1.push_back(3);
	l1.push_back(5);
	l1.push_front(7);
	l1.push_front(9);
	l1.push_front(11);//ͷ�巨
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	l1.insert(l1.begin(), 77);//�ڿ�ʼλ��ǰ����
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	l1.erase(l1.begin(), --l1.end());//����ɾ��,����ҿ�
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	l1.push_back(1);//β�巨
	l1.push_back(3);
	l1.push_back(5);
	l1.push_front(7);
	l1.push_front(9);
	l1.push_front(11);//ͷ�巨

	l1.remove(5);//ɾ������Ԫ��5
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
	//erase(l1.begin()); ɾ��ָ��λ�õ�Ԫ��,������һ��Ԫ�صĵ�����λ��
	list<int>::iterator it=l1.erase(l1.begin());
	cout << *it << endl;//9
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}

}

/**
 * ���ȼ����� priority_queue:Ĭ��Ϊ���ֵ���ȼ�����
 */
void testpriority_queue()
{


	//priority_queue:Ĭ��Ϊ���ֵ���ȼ�����
	//priority_queue<int,vector<int>,less<int>>
	priority_queue<int> pq1;
	pq1.push(1);
	pq1.push(3);
	pq1.push(5);
	
	while (!pq1.empty())
	{
		cout << pq1.top() <<" ";
		pq1.pop();
	}

	printf("\n");
	//��Сֵ���ȼ�����
	priority_queue<int,vector<int>,greater<int>> pq2; //greater Ҫ����ͷ�ļ�->functional
	pq2.push(1);
	pq2.push(3);
	pq2.push(5);

	while (!pq2.empty())
	{
		cout << pq2.top() << " ";
		pq2.pop();
	}
}

/**
 * stl
 * 1.deque˫������,ͷ����β�������Բ���
 * 2.stack �Ƚ����
 * 3.queue:���� ��β��,��ͷ��,�Ƚ��ȳ�
 * 4.list :˫������,����������Ĵ�ȡԪ��,��֧��at() [] ȡԪ��
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	testdeque01();
//	teststack001();
//	testqueue001();
//	testlist001();
//	testvec06();
	testpriority_queue();
	return 0;
}