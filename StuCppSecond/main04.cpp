#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyArrays.cpp"
#include <stdexcept>
#include <string.h>
#include "MyException.h"

using namespace std;


void testmyexpet()
{
	throw MyException("����MyException");
}

int mainmain0401(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	try
	{
		MyArrays<int,int> arr(10);
		string str = "aaa";
		//throw out_of_range(str);//��׼�쳣��
		testmyexpet();
	}
	catch (tooSmallError & e)
	{
		e.prin_err();
	}
	catch (tooSmallError::TooBig e)
	{
		e.prin_err();
	}
	catch (MyException e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}
	return 0;
}