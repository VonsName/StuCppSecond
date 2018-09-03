#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;



class Animal
{
public:
	Animal()
	{

	}
	virtual void cry() = 0;
protected:
private:
};
class Bird:public Animal
{
public:
	virtual void cry()
	{
		cout << "��" << endl;
	}
protected:
private:
};
class Dog:public Animal
{
public:
	virtual void cry()
	{
		cout << "��" << endl;
	}
protected:
private:
};


void playObj(Animal *base)
{
	//dynamic_cast��̬����ת�� ����תΪ���࣬����ת��
	Dog *dog = dynamic_cast<Dog *>(base);
	if (dog != NULL)
	{
		dog->cry();
	}

	//dynamic_cast�������ת��ʧ��,ΪNULL
	Bird *bird = dynamic_cast<Bird *>(base);
	if (bird != NULL)
	{
		bird->cry();
	}
}

//06-09��ʱ
void print_const_cart(const char *p)
{
	//p[0] = 'z'; //error ,���ܸı�
	//����Ҫȷ��ָ��pָ����ڴ�ռ�ȷʵ�ǿ����޸ĵĲ���
	char *tmp = const_cast<char *>(p);//ʹ��const_castȥ��constֻ������,���Ա��޸�
									//��������β��� char *p="asd",��Ҳ���ܸı�
									//��Ϊchar *p="asd"��ָ���ַ�����������
	tmp[0] = 'z';
	printf("%s\n", p);
}

/**
 * ����ת����
 * 1.static_cast:��̬����ת�� ��intתΪchar
 * 2.reinterpret_cast:���½������� ǿ������ת��
 * 3.dynamic_cast:��̬����ת�����������븸��֮���ת��
 * 4.const_cast:ȥ��������ֻ������
 */
int mainmain001(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	//static_cast 
	char c = static_cast<char>(90);
	printf("%c\n", c);

	//dynamic_cast
	Animal *bird = new Bird;
	Animal *dog = new Dog;
	playObj(bird);
	playObj(dog);

	Animal *a = NULL;
	Bird b1;
	Dog d1;
	//static_cast ����ת��
	a = static_cast<Animal*>(&b1);//C++��������������ͼ��
	a = static_cast<Animal*>(&d1);
	a = reinterpret_cast<Animal *>(&d1);//reinterpret_castǿ������ת�����������ͼ��
	
	char buf[] = "ada";
	print_const_cart(buf);
	cout << buf << endl;
	return 0;
}



class BadErr
{
public:
	BadErr()
	{
		cout << "���캯��" << endl;
	}
	BadErr(const BadErr &e)
	{
		cout << "�������캯��" << endl;
	}
	~BadErr()
	{
		cout << "��������" << endl;
	}
protected:
private:
};


void testBad  (int a) 
{
	if (a==0)
	{
		throw BadErr();
	}
	if (a == 1)
	{
		throw &(BadErr());
	}
}

/**
 * 1.����׳��쳣�������������ͣ���ʹ��try ..catch(..e)���ܵ�ʱ��
 *		catch(..e)C++��ʹ�ÿ������캯������throw���������e����
 * 2.�쳣���������ڣ����׳��ĵط�һֱ��catch(..e)���ڵĺ�������
 * 3.�쳣���׳���,�ӽ���try����,���쳣������ǰ,���ڼ���ջ�Ϲ�������ж���,���ᱻ�Զ�����
 *			,������˳���빹���˳���෴,��һ���̳�Ϊջ����
 */
int mainmain02(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	try
	{
		testBad(1);
	}
	/*
	catch (BadErr b)//�׳��������쳣��ʱ�����catch(BadErr b)ʹ��Ԫ�ؽ���
						//��C++����������ÿ������캯��
	{
		cout << "BadErr" << endl;
	}*/

	//ָ����Ժ����á�Ԫ��ͬʱ���ڣ�����Ԫ�غ����ò���ͬʱ����
	catch (BadErr &b)//���ʹ�����ý��ܣ��򲻻���ÿ������캯��
	{
		cout << "BadErr &b" << endl;
	}
	catch (BadErr *b)//�׳���ʱ��Ҫ�׳���ַ throw &(BadErr());
	{
		cout << "BadErr *b" << endl;
	}
	catch (...)
	{
		cout << "...δ֪�쳣" << endl;
	}
	return 0;
}