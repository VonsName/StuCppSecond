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
#include <set>
#include <string>
#include <map>

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

	//重载=
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
void testvec05()
{
	vector<int> v2(5);
	for (unsigned int i = 0; i < v2.size(); i++)
	{
		v2[i] = i + 3;
	}

	//end();的位置是在容器最后一个元素的后面
	//正向遍历
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}

	printf("\n");
	//逆序遍历 rend()的位置是在容器第一个元素的前面
	for (vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
	{
		cout << *it << " ";
	}

	//只读迭代器
	printf("\n");
	for (vector<int>::const_iterator it = v2.cbegin(); it != v2.cend(); it++)
	{
		cout << *it << " ";
	}
	//只读迭代器
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

	//区间删除
	v2.erase(v2.begin(), v2.begin()+3); //0 -3 全部删除
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}


	//指定位置删除 
	vector<int>::iterator it=v2.erase(v2.end()-1); 
	//erase()会自动让迭代器后移,删除一个元素并返回下一个迭代器的位置
	printf("\n");
	for (vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
	{
		cout << *it << " ";
	}

	//插入
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
 * 1.vector :内部是以数组的方式存储的,存储空间是连续的
 *			:可以随机存取元素，也可以通过索引,获取元素的速度快
 *			:在中间删除元素较慢，添加元素慢
 *			:push_back(): 在尾部插入元素
 *			:back(): 返回尾部的元素,返回的是引用
 *			:pop_back() 删除尾部元素
 *			:front():返回头部元素，返回一个引用
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

	d1.pop_back();//弹出尾部元素
	d1.pop_front();//弹出头部元素

	printf("\n");
	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	//根据迭代器查找数组下标
	deque<int>::iterator it=find(d1.begin(), d1.end(), 3);
	if (it != d1.end())
	{
		cout << "数组下标为: " << distance(d1.begin(), it) <<endl;
	}
	else
	{
		cout << "没有找到 " << endl;
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
		cout << s1.top() << " ";//获取栈顶元素
		s1.pop();//弹出栈顶元素
	}
}

void testqueue001()
{
	queue<int> q1;
	q1.push(3);//队尾进,队头出,先进先出
	q1.push(5);
	q1.push(7);
	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
}


/**
 * list不能随机访问 
 */
void	testlist001()
{
	list<int> l1;
	l1.push_back(1);//尾插法
	l1.push_back(3);
	l1.push_back(5);
	l1.push_front(7);
	l1.push_front(9);
	l1.push_front(11);//头插法
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	l1.insert(l1.begin(), 77);//在开始位置前插入
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	l1.erase(l1.begin(), --l1.end());//区间删除,左闭右开
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	l1.push_back(1);//尾插法
	l1.push_back(3);
	l1.push_back(5);
	l1.push_front(7);
	l1.push_front(9);
	l1.push_front(11);//头插法

	l1.remove(5);//删除所有元素5
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
	//erase(l1.begin()); 删除指定位置的元素,返回下一个元素的迭代器位置
	list<int>::iterator it=l1.erase(l1.begin());
	cout << *it << endl;//9
	for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}

}

/**
 * 优先级队列 priority_queue:默认为最大值优先级队列
 */
void testpriority_queue()
{


	//priority_queue:默认为最大值优先级队列
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
	//最小值优先级队列
	priority_queue<int,vector<int>,greater<int>> pq2; //greater 要包含头文件->functional
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
 * 元素不能重复，自动排序,默认升序
 */
void testset()
{
//	set < int, less<int>> s;//默认
	set<int> s1;
	for (int i = 0; i < 5; i++)
	{
		s1.insert(rand());
	}
	s1.insert(99);
	s1.insert(99);
	s1.insert(99);
	/*for each (auto it in s1)
	{
		cout << it << " ";
	}*/
	for (set<int>::const_iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
	s1.erase(s1.begin());
	for (set<int>::const_iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	//降序
	set<int, greater<int>> s2;
	for (int i = 0; i < 5; i++)
	{
		s2.insert(rand());
	}
	for (set<int,greater<int>>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
}


class Apple
{
public:
	Apple(int height)
	{
		this->height = height;
	}
public:
	int height;
protected:
private:
};

//仿函数,
struct FuncApp 
{
	//重载了函数调用符()
	bool operator()(const Apple &left, const Apple &right)
	{
		return left.height > right.height;
	}
};

/**
 * set自定义数据类型排序
 */
void testset01()
{
	Apple a1(23);
	Apple a2(33);
	Apple a3(3);
	Apple a4(8);
	Apple a5(19);
	Apple a6(33);
	set<Apple, FuncApp> s1;
	s1.insert(a1);
	//insert()会返回插入的结果
	pair<set<Apple,FuncApp>::iterator,bool> it2= s1.insert(a2);
	if (it2.second)
	{
		cout << "插入a2成功" << endl;
	}
	else
	{
		cout << "插入a2失败" << endl;
	}
	s1.insert(a3);
	s1.insert(a4);
	s1.insert(a5);

	//自定义放函数按照年龄排序时，如果插入重复的年龄，则第二个会插入失败
	pair<set<Apple, FuncApp>::iterator, bool> it6 = s1.insert(a6);
	if (it6.second)
	{
		cout << "插入a6成功" << endl;
	}
	else
	{
		cout << "插入a6失败" << endl;
	}

	for (set<Apple, FuncApp>::const_iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << it->height << endl;
	}

}

/**
 *
 *	//s1.lower_bound()//返回第一个大于等于元素的迭代器
 *	//s1.upper_bound() //返回第一个大于元素的迭代器
 */
void testset02()
{
	set<int> s1;
	for (int i = 0; i < 5; i++)
	{
		s1.insert(i+1);
	}
	for (set<int>::const_iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
	//find()返回迭代器位置
	set<int>::iterator it = s1.find(3);
	cout << *it << endl;

	cout << endl;
	int cnum = s1.count(3);
	cout << cnum << endl;
	printf("\n");

	//lower_bound(3) 返回大于等于3的第一个迭代器的位置
	set<int>::iterator lit=s1.lower_bound(3);
	cout << *lit << endl;//3

	//upper_bound(3) 返回第一个大于3的元素的迭代器的位置
	//要注意，如果元素是位于set最后一个位置，程序会段错误，返回的是空迭代器
	set<int>::const_iterator lit2=s1.upper_bound(3);
	if (lit2 != s1.end())
	{
		cout << "*lit2: " << *lit2 << endl;//4
	}

//	s1.erase(3);
	//equal_range(3) 返回两个迭代器，一个大于等于3的第一个，第二个大于3的第一个
	pair<set<int>::const_iterator, set<int>::const_iterator> pit = s1.equal_range(3);
	cout << *(pit.first) << endl;//3
	cout << *(pit.second) << endl;//4
}


/**
 * 可以重复元素
 */ 
void testmultiset()
{
	multiset<int> ms1;
	ms1.insert(1);
	ms1.insert(3);
	ms1.insert(5);
	ms1.insert(3);
	ms1.insert(1);
	for (multiset<int>::iterator it = ms1.begin(); it != ms1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");


	ms1.erase(3);
	for (multiset<int>::iterator it = ms1.begin(); it != ms1.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
}

/**
 * stl
 * 1.deque双端数组,头部和尾部都可以插入
 * 2.stack 先进后出
 * 3.queue:队列 队尾进,队头出,先进先出
 * 4.priority_queue:优先队列，默认最大值优先
 * 5.list :双向链表,不可以随机的存取元素,不支持at() [] 取元素
 * 6.set:包含的元素是唯一的，集合中的元素按一定的顺序排列，
 *		元素插入过程是按排序规则插入，所以不能指定插入位置，不能直接存取元素，
 *		不支持at() []，set支持唯一键值，元素不能重复；multiset元素可以重复，
 *		不能直接修改set或者multiset中的值，只能先删除，再插入新的值
 */
int main06002(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	testdeque01();
//	teststack001();
//	testqueue001();
//	testlist001();
//	testvec06();
//	testpriority_queue();
//	testset();
//	testset01();
//	testset02();
	testmultiset();
	return 0;
}



void testmap()
{
	map<int, string> m1;

	pair<map<int,string>::iterator,bool> pa=m1.insert(pair<int,string>(1, "zhangsan"));
	if (pa.second)
	{
		printf("插入成功\n");
	}
	else
	{
		printf("插入失败\n");
	}

	pa = m1.insert(make_pair(2, "lisi"));
	if (pa.second)
	{
		printf("插入成功\n");
	}
	else
	{
		printf("插入失败\n");
	}

	pa = m1.insert(map<int, string>::value_type(3, "wangwu"));
	if (pa.second)
	{
		printf("插入成功\n");
	}
	else
	{
		printf("插入失败\n");
	}
	m1[4] = "zhaoliu";
	m1[4] = "wangermazi";//相同键则覆盖掉前面的，insert()相同的则报错

	for (map<int, string>::const_iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << it->first << "==>" << it->second << endl;
	}


	map<int,string>::iterator mit= m1.find(3);
	if (mit != m1.end())
	{
		cout << "查找=3->" << mit->first << "\t" << mit->second << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

	pair<map<int,string>::iterator, map<int, string>::iterator>mypair=m1.equal_range(3);

	if (mypair.first != m1.end())
	{
		cout << "查找大于等于3->" << mypair.first->first << "\t" << mypair.first->second << endl;
	}
	else 
	{
		cout << "没有找到大于等于" << endl;
	}
	if (mypair.second != m1.end())
	{
		cout << "查找大于3->" << mypair.second->first << "\t" << mypair.second->second << endl;
	}
	else
	{
		cout << "没有找到大于的" << endl;
	}

	printf("over\n");
	while (!m1.empty())
	{
		map<int, string>::iterator it = m1.begin();
		cout << (*it).first << "\t" << (*it).second << endl;
		m1.erase(it);
	}
}


void testmultimap()
{

}

/**
 * map/multimap
 * map :键是唯一的
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	testmap();
	testmultimap();
	return 0;
}