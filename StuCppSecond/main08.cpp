#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <vector>
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

/**
 * 1.一元函数对象:仿函数的参数是一个
 * 2.一元谓词:函数参数是一个,且返回值是bool类型,可以作为一个判断式,
 *					谓词可以是一个仿函数,也可以是一个回调函数;
 * 3.二元谓词:函数参数是2个,且返回值是bool类型;
 */

//12-->09课时开始
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	testfunobj01();
	return 0;
}