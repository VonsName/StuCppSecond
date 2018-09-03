#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <string>
#include <cstring>

using namespace std;


/**
 * cin接收参数不能带空格
 */
int main0501(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int a;
	long l;
	cin >> a;
	cin >> l;
	cout << a << " " << l << endl;
	return 0;
}

int main05002(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	char ch;
	while ((ch = cin.get()) != EOF)
	{
		cout << ch << endl;
	}
	return 0;
}


/**
 * cin.get(a):如果缓冲区没有数据,会一直阻塞
 */
int main05003(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	char a, b,c;
	cin.get(a).get(b).get(c);
	cout << a << b << c << endl;
	return 0;
}


/**
 * cin.getline():接收字符串
 */
int main05004(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	char buf[1024];
	cin.getline(buf, strlen(buf));
	cout << buf << endl;
	return 0;
}



int main05005(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	cin.ignore(2);//忽略最前面两个字符
	char buf[1024];
	cin.getline(buf, strlen(buf));
	cout << buf << endl;
	return 0;
}

int main00506(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	
	char c = cin.peek();
	cout << c << endl;

	char buf[1024];
	cin.getline(buf, strlen(buf));
	cout << buf << endl;

	cin.putback(c);//放回缓冲区
	return 0;
}

int main00507(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	cout.put('c').put('b');//一个字符一个字符的输出到屏幕
	cout << endl;


	const char *p = "dadas";
	cout.write(p, strlen(p));//以二进制流输出
	cout << endl;

	cout << "[start]";
	cout.width(30);//输出30个字符
	cout.fill('*');//不足30用*填充
	cout.setf(ios::showbase);
	cout.setf(ios::internal);//在中间填充
	cout << hex << 123;
	cout << "[end]" << endl;


	//使用控制符
	cout << "[start]" 
		<<setw(30)//设置宽度 相当于cout.width()
		<<setfill('*')//相当于cout.fill('*')
		<<setiosflags(ios::showbase)//相当于cout.setf(ios::showbase);
		<<setiosflags(ios::internal)//相当于cout.setf(ios::internal);
		<<hex //以16进制输出
		<<123
		<<"[end]"
		<< endl;
	cout << dec << 10 << endl;//以10进制输出
	return 0;
}


/**
 * 读写文件
 */
int main05008(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	char *p = "C:\\Users\\vons0\\Desktop\\1.txt";
	ofstream out(p, ios::out);//建立一个输出流对象,和文件关联 
									//ios::out 没有新建,有责覆盖   ios::app:追加

	if (!out.is_open())
	{
		return 0;
	}
	out << "hello world" << endl;

//	out.open(p, ios::out); 
	out.close();


	char buf[1024];
	ifstream in(p,ios::in);//建立一个输入流对象,和文件关联 ios::in|ios::binary 结合使用,以二进制流打开一个文件
	if (!in.is_open())
	{
		return 0;
	}
	/*while (in >> buf)
	{
			cout << buf;
	}*/

	/*char ch;
	while (in.get(ch))
	{
		cout << ch;
	}*/

	//feof C判断文件末尾
	if (in.eof())//判断是否到文件末尾
	{
		return 0;
	}
	while (in.getline(buf, strlen(buf)))
	{
		cout << buf;
	}

	//string s;
	//in >> noskipws;//表示包含空格回车一起读取
	//while (getline(in,s))
	//{
	//	cout << s;
	//}
	in.close();//关闭输入流
	return 0;
}





/**
 * 以二进制读写文件
 */
int main05009(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	char *p="C:\\Users\\vons0\\Desktop\\2.txt";
	ofstream out;
	out.open(p, ios::out | ios::binary);
	char buf[2048] = { "adadasdasdasdasdasd" };
	if (out.is_open())
	{
		out.write(buf, strlen(buf));
	}
	out.close();

	ifstream in;
	in.open(p, ios::in | ios::binary);

	char tmp[2014] = {0};
	if (in.is_open())
	{
		while (!in.eof())
		{
			in.read(tmp, strlen(buf));
			cout << tmp;
		}
	}

	in.close();
	
	return 0;
}




class Book
{
public:
	Book()
	{

	}
	Book(int no, char *name)
	{
		this->no = no;
		memset(this->buf, 0, sizeof(buf) / sizeof(char));
		strcpy(this->buf, name);
	}
	void print_b()
	{
		cout << this->no << " " << this->buf << endl;
	}
protected:
private:
	int no;
	char buf[1024] = { 0 };
};

/**
 * 二进制读写对象(序列化对象)
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	char *p = "C:\\Users\\vons0\\Desktop\\3.txt";
	ofstream outfile;
	outfile.open(p, ios::out | ios::binary);

	Book b1(23, "三国演义");

	Book b2(25, "水浒转");
	if (outfile.is_open())
	{
		outfile.write((char *)(&b1), sizeof(b1));
		outfile.write((char *)(&b2), sizeof(b2));
	}

	outfile.close();


	char mybuf[1024];//char a[]数组 求大小的时候只能用sizeof() strlen()的长度不准确
	printf("strlen(mybuf)=%d\n", strlen(mybuf));
	printf("strlen(mybuf)=%d\n", sizeof(mybuf)/sizeof(char));

	char *pname = "adadasda";
	printf("strlen(mybuf)=%d\n", strlen(pname));//8 ->不算空格
	printf("strlen(mybuf)=%d\n", sizeof(pname));//4 指针大小
	//memset(mybuf, 0, );
	ifstream in;
	Book tmp;
	in.open(p, ios::in | ios::binary);
	if (in.is_open())
	{
		//要先读一次,不然会读取到最后一条重复的数据
		in.read((char *)&tmp, sizeof(Book));
		while (!in.eof())
		{
			tmp.print_b();
			in.read((char *)&tmp, sizeof(Book));
		}
	}
	in.close();
	return 0;
}