#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
class SizeError//:public exception
{
public:
	explicit SizeError(char *p);
	~SizeError();
	virtual void prin_err() = 0;
	/*virtual const char * what()
	{
		return this->p;
	}*/
public:
	char *p;
};

class tooSmallError :public SizeError
{
public:
	explicit tooSmallError(char *p) :SizeError(p) {	;}
	
public:
	class TooBig:public SizeError
	{
	public:
		explicit TooBig(char *p) :SizeError(p) { ; }
		virtual void prin_err()
		{
			cout << p << endl;
		}
	};
public:
	virtual void prin_err()
	{
		cout << p << endl;
	}
protected:
private:
};

