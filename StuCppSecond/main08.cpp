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


//仿函数对象
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


//仿函数
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


//模板函数
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

	//FunShow<int>() 匿名仿函数对象
//	for_each(v1.begin(), v1.end(), FunShow<int>());

	printf("\n");
	//funShowEle<int> 回调函数的入口地址
//	for_each(v1.begin(), v1.end(), funShowEle<int>);

	//仿函数对象
	FunShow<int> show;
//	IsDiv<int> isdiv(2);
	//仿函数对象做函数参数,for_each()算法结果返回被当作参数传入的函数对象
	show=for_each(v1.begin(), v1.end(), show);
	//通过for_each算法的返回结果查看仿函数保存的状态
	show.print_n();
}

/**
 * 算法
 * 1.函数对象:重载了函数调用符()的类的对象,行为类似函数 
 *					:可以保持调用状态
 */

int main08001(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	testfunobj();
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////


//一元谓词
void testfunobj01()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(8);

	int a = 4;
	//仿函数对象,一个参数的,返回值是bool 所以也可以叫一元谓词
	IsDiv<int> divor(a);

	//find_if算法返回一个迭代器
	//vector<int>::iterator it=find_if(v1.begin(), v1.end(),IsDiv<int>(a));//一元谓词
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), divor);//一元谓词
	if (it != v1.end())
	{
		cout << "vector中第一个能被" << a<< "整除的数是:" << *it << endl;
	}
	else
	{
		cout << "vector中没有能被" << a << "整除的数" << endl;
	}

}

//仿函数
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
//二元函数对象
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
	//返回一个目标容器的迭代器(这里是第三个参数)
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");

	for_each(v3.begin(), v3.end(), funShowEle<int>);//funShowEle<int>函数入口地址
	printf("\n");
}


template <typename T>
bool myCompare(const int &a, const int &b)
{
	return a < b;
}

//二元谓词
void testfunobj03()
{
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(rand());
	}

	//myCompare<int> 二元谓词
	sort(v1.begin(), v1.end(), myCompare<int>);
	
	for_each(v1.begin(), v1.end(), funShowEle<int>);
}

/**
 * 仿函数 二元谓词 和set结合使用
 */
struct MyCompartByNoCase 
{
	//注意这里重载的operator()也必须是const的，否则会出现丢失const限定符错误
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
//二元谓词在set中的应用
void testfunobj04()
{
	set<string, MyCompartByNoCase> s1;
	s1.insert("aaa");
	s1.insert("ccc");
	s1.insert("bbb");
	set<string, MyCompartByNoCase>::iterator it = s1.find("bBb");
	if (it != s1.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}
}

/**
 * 1.一元函数对象:仿函数的参数是一个
 * 2.一元谓词:函数参数是一个,且返回值是bool类型,可以作为一个判断式,
 *					谓词可以是一个仿函数,也可以是一个回调函数;
 * 3.二元谓词:函数参数是2个,且返回值是bool类型;
 */

//12-->09课时开始
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


//自定义函数对象
void testfunobj06()
{
	MyOperationAdd<int> myadd;
	int a = myadd(1, 2);
	cout << "a=" << a <<  endl;
}



//函数适配器
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
	//bind2nd()函数适配器，把预定义函数对象和第二个参数进行绑定
	int num=count_if(s1.begin(), s1.end(), bind2nd(equal_to<string>(), "aaa"));
	cout << "aaa出现的个数：" << num << endl;
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
 * 函数适配器
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
	//modulus() 取余
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	//not1() 取反
	int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "2的个数：" << num1 << endl;
	cout << "大于2的个数：" << num2 << endl;
	cout << "大于2的个数：" << num3 << endl;
	cout << "奇数个数：" << num4 << endl;
	cout << "偶数个数：" << num5 << endl;
}

void testfunobj09()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);
	//删除小于等于2的元素
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
	//not1(bind1st(less<int>(), 2))) 相当于bind2nd(less_equal<int>(), 2)) 小于等于2
	//bind1st(less<int>(), 2)) 大于2
	vector<int>::iterator it2 = v2.erase(remove_if(v2.begin(), v2.end(), not1(bind1st(less<int>(), 2))));
	for (; it2 != v2.end(); it2++)
	{
		cout << *it2 << " ";
	}
}

/**
 * 预定义函数对象和函数适配器
 * 1.plus<int> 能实现不同数据类型之间的相加,通过函数对象(仿函数)实现的
 */
int main08003(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	testfunobj05();
//	testfunobj06();
//	testfunobj07();

	int a = 10;
	int *p = &a;
	//指针的引用
	int* &p1 = p;
	cout << "*p=" << *p << endl;
	cout << "*p1=" << *p1 << endl;
	return 0;
}

/**
 * make_heap：//将范围内的元素建成堆可以快速地取得其范围内的最大值
 * sort_heap：//使用operator<进行比较，前提是范围内的元素已经是一个堆了，否则会出错！
			//排序后序列将失去堆的属性！
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

//	sort_heap(v1.begin(), v1.end());//error 此时vector范围中的元素还不是一个堆
//	for each (int i in v1)
//	{
//		cout << i << " ";
//	}
	//将范围内的元素建成堆可以快速地取得其范围内的最大值
	make_heap(v1.begin(), v1.end());
	for each (int i in v1)
	{
		cout << i << " ";
	}
	cout << endl;
	printf("--\n");
	//使用operator<进行比较，前提是范围内的元素已经是一个堆了，否则会出错！
	//排序后序列将失去堆的属性！
	sort_heap(v1.begin(), v1.end());
	for each (int i in v1)
	{
		cout << i << " ";
	}
}

/**
 * pop_heap：将第一个最大元素移动到end()的前部，
 *			 同时将剩下的元素重新构造成一个新的heap		
 * push_heap:对刚插入的（尾部）元素做堆排序
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

//函数适配器
int main08004(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	testfunobj08();
//	testfunobj09();
//	testfunobj010();
	testfunobj011();
	return 0;
}