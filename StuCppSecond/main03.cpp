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
		cout << "鸟" << endl;
	}
protected:
private:
};
class Dog:public Animal
{
public:
	virtual void cry()
	{
		cout << "狗" << endl;
	}
protected:
private:
};


void playObj(Animal *base)
{
	//dynamic_cast动态类型转换 父类转为子类，向下转型
	Dog *dog = dynamic_cast<Dog *>(base);
	if (dog != NULL)
	{
		dog->cry();
	}

	//dynamic_cast如果类型转换失败,为NULL
	Bird *bird = dynamic_cast<Bird *>(base);
	if (bird != NULL)
	{
		bird->cry();
	}
}

//06-09课时
void print_const_cart(const char *p)
{
	//p[0] = 'z'; //error ,不能改变
	//这里要确保指针p指向的内存空间确实是可以修改的才行
	char *tmp = const_cast<char *>(p);//使用const_cast去除const只读属性,可以被修改
									//但是如果形参是 char *p="asd",则也不能改变
									//因为char *p="asd"是指向字符串常量区的
	tmp[0] = 'z';
	printf("%s\n", p);
}

/**
 * 类型转换：
 * 1.static_cast:静态类型转换 如int转为char
 * 2.reinterpret_cast:重新解释类型 强制类型转换
 * 3.dynamic_cast:动态类型转换，如子类与父类之间的转换
 * 4.const_cast:去除变量的只读属性
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
	//static_cast 向上转型
	a = static_cast<Animal*>(&b1);//C++编译器会进行类型检查
	a = static_cast<Animal*>(&d1);
	a = reinterpret_cast<Animal *>(&d1);//reinterpret_cast强制类型转换不会做类型检查
	
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
		cout << "构造函数" << endl;
	}
	BadErr(const BadErr &e)
	{
		cout << "拷贝构造函数" << endl;
	}
	~BadErr()
	{
		cout << "析构函数" << endl;
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
 * 1.如果抛出异常的类型是类类型，在使用try ..catch(..e)接受的时候
 *		catch(..e)C++会使用拷贝构造函数拷贝throw出的类对象到e变量
 * 2.异常的声明周期：从抛出的地方一直到catch(..e)所在的函数结束
 * 3.异常被抛出后,从进入try块起,到异常被抛掷前,这期间在栈上构造的所有对象,都会被自动析构
 *			,析构的顺序与构造的顺序相反,这一过程称为栈解旋
 */
int mainmain02(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	try
	{
		testBad(1);
	}
	/*
	catch (BadErr b)//抛出类类型异常的时候，如果catch(BadErr b)使用元素接受
						//则C++编译器会调用拷贝构造函数
	{
		cout << "BadErr" << endl;
	}*/

	//指针可以和引用、元素同时存在，但是元素和引用不能同时存在
	catch (BadErr &b)//如果使用引用接受，则不会调用拷贝构造函数
	{
		cout << "BadErr &b" << endl;
	}
	catch (BadErr *b)//抛出的时候要抛出地址 throw &(BadErr());
	{
		cout << "BadErr *b" << endl;
	}
	catch (...)
	{
		cout << "...未知异常" << endl;
	}
	return 0;
}