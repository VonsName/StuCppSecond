#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <string>
#include <cstring>

using namespace std;


/**
 * cin���ղ������ܴ��ո�
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
 * cin.get(a):���������û������,��һֱ����
 */
int main05003(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	char a, b,c;
	cin.get(a).get(b).get(c);
	cout << a << b << c << endl;
	return 0;
}


/**
 * cin.getline():�����ַ���
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
	cin.ignore(2);//������ǰ�������ַ�
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

	cin.putback(c);//�Żػ�����
	return 0;
}

int main00507(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	cout.put('c').put('b');//һ���ַ�һ���ַ����������Ļ
	cout << endl;


	const char *p = "dadas";
	cout.write(p, strlen(p));//�Զ����������
	cout << endl;

	cout << "[start]";
	cout.width(30);//���30���ַ�
	cout.fill('*');//����30��*���
	cout.setf(ios::showbase);
	cout.setf(ios::internal);//���м����
	cout << hex << 123;
	cout << "[end]" << endl;


	//ʹ�ÿ��Ʒ�
	cout << "[start]" 
		<<setw(30)//���ÿ�� �൱��cout.width()
		<<setfill('*')//�൱��cout.fill('*')
		<<setiosflags(ios::showbase)//�൱��cout.setf(ios::showbase);
		<<setiosflags(ios::internal)//�൱��cout.setf(ios::internal);
		<<hex //��16�������
		<<123
		<<"[end]"
		<< endl;
	cout << dec << 10 << endl;//��10�������
	return 0;
}


/**
 * ��д�ļ�
 */
int main05008(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	char *p = "C:\\Users\\vons0\\Desktop\\1.txt";
	ofstream out(p, ios::out);//����һ�����������,���ļ����� 
									//ios::out û���½�,���𸲸�   ios::app:׷��

	if (!out.is_open())
	{
		return 0;
	}
	out << "hello world" << endl;

//	out.open(p, ios::out); 
	out.close();


	char buf[1024];
	ifstream in(p,ios::in);//����һ������������,���ļ����� ios::in|ios::binary ���ʹ��,�Զ���������һ���ļ�
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

	//feof C�ж��ļ�ĩβ
	if (in.eof())//�ж��Ƿ��ļ�ĩβ
	{
		return 0;
	}
	while (in.getline(buf, strlen(buf)))
	{
		cout << buf;
	}

	//string s;
	//in >> noskipws;//��ʾ�����ո�س�һ���ȡ
	//while (getline(in,s))
	//{
	//	cout << s;
	//}
	in.close();//�ر�������
	return 0;
}





/**
 * �Զ����ƶ�д�ļ�
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
 * �����ƶ�д����(���л�����)
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	char *p = "C:\\Users\\vons0\\Desktop\\3.txt";
	ofstream outfile;
	outfile.open(p, ios::out | ios::binary);

	Book b1(23, "��������");

	Book b2(25, "ˮ�ת");
	if (outfile.is_open())
	{
		outfile.write((char *)(&b1), sizeof(b1));
		outfile.write((char *)(&b2), sizeof(b2));
	}

	outfile.close();


	char mybuf[1024];//char a[]���� ���С��ʱ��ֻ����sizeof() strlen()�ĳ��Ȳ�׼ȷ
	printf("strlen(mybuf)=%d\n", strlen(mybuf));
	printf("strlen(mybuf)=%d\n", sizeof(mybuf)/sizeof(char));

	char *pname = "adadasda";
	printf("strlen(mybuf)=%d\n", strlen(pname));//8 ->����ո�
	printf("strlen(mybuf)=%d\n", sizeof(pname));//4 ָ���С
	//memset(mybuf, 0, );
	ifstream in;
	Book tmp;
	in.open(p, ios::in | ios::binary);
	if (in.is_open())
	{
		//Ҫ�ȶ�һ��,��Ȼ���ȡ�����һ���ظ�������
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