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


//����ָ������������
void showFunElement(int &t)
{
	cout << t << " ";
}

//�º�������
struct ShowFunObj 
{
	void operator()(int &t)
	{
		cout << t << " ";
	}
};

///
void main09_for_each()
{
	vector<int> v1{ 1,7,5,6,8,9,3 };
	//����ָ���������������ص������������Ǻ�������ڵ�ַ
	for_each(v1.begin(), v1.end(), showFunElement);
	printf("\n");
	//�º�����������������
	for_each(v1.begin(), v1.end(), ShowFunObj());
}

//
void main09_transform()
{

}
/**
 * stl�����㷨
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	main09_for_each();
	return 0;
}