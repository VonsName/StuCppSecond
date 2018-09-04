#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void main071()
{
	string str1 = "abc";
	string str2 = str1;
	string str3(3, 'b');
	string str4(str1);
	string str5("bcdoqjeqno");
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	//遍历字符串
	for (unsigned int i=0;i<str5.length();i++)
	{
		cout << str5[i] << endl; //[]出现错误不会向外面抛出异常,使用try catch也不能捕捉到
	}
	printf("-----------------------\n");
	for (string::iterator it = str1.begin(); it != str1.end(); it++)
	{
		cout << *it << endl;
	}
	printf("-----------------------\n");

	for (unsigned int i = 0; i < str1.length(); i++)
	{
		cout << str1.at(i);//at 出现错误会向外面 抛出异常 可以使用try catch 捕捉到
	}
}


void main072()
{
	string str1 = "adada";
	const char *p = str1.data();

	const char *p1=str1.c_str();

	char buf[64] = {0};
	str1.copy(buf, str1.length(),0 );
	cout << buf << endl;
	string str2 = "12121";
	cout << str1 + str2 << endl;

	cout << str1.append(buf) << endl;
}


/**
 * 查找子字符串出现的次数
 */
void main073()
{
	string str = "adaqwesqqwwehelloqweaadaqwe12312qwe1312";
	//find("qwe", 0) 从0位置开始查找qwe字符串，返回第一次出现的下标位置
	int index = str.find("qwe", 0);
	cout << index << endl;
	int count = 0;
	//查找子字符串并替换
	while (index != string::npos)
	{
		count++;
		str.replace(index, strlen("qwe"),"QQQ");
		index = str.find("qwe", index + strlen("qwe"));
	}
	cout << count << endl;
	cout << str << endl;
	string str2 = "aaa";
	string str3 = "bbb";
	
	//交换两个字符串
	swap(str2, str3);
	cout << "str2: " << str2 << " " << "str3: " << str3 << endl;
}


//删除字符串中的字符
void main074()
{
	string str1 = "hellowordaallahehlo";
	int index = str1.find('l', 0);
	while (index != string::npos)
	{
		//str1.replace(index, 1, "");
		str1.erase(index, 1);
		
		index = str1.find('l', index + 1);
		
	}
	cout << str1 << endl;

	string str2 = "hellowordaallahehlo";
	string::iterator it = find(str2.begin(), str2.end(),'l');
	while (it != str2.end())
	{
		str2.erase(it);
	}
	cout << "str2:" << str2 << endl;

	//在0下标前插入AAA
	string str3 = "aa";
	str3.insert(0, "AAA");
	cout << str3 << endl;
	str3.insert(str3.length(), "CCC");
	cout << str3 << endl;
}

/**
 * transform
 */
void main075()
{
	string str1 = "aaaa";
	string str2;
	transform(str1.begin(), str1.end(),str1.begin(),toupper);
	cout << str1 << endl;


	transform(str1.begin(), str1.end(), str1.begin(), tolower);
	cout << str1 << endl;
}

/**
 * string
 */
int main076(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	main071();
//	main072();
//	main073();
//	main074();
	main075();
	return 0;
}