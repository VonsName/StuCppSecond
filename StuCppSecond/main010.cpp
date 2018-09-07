#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <functional>
#include <iterator>
#include <numeric>
#include <map>
#include <iterator>
#include <deque>
using namespace std;



class Speaker
{
public:
	string name;
	int id;
	int score[3];
public:
	Speaker(string name,int id)
	{
		this->name = name;
		this->id = id;
	}
	Speaker()
	{

	}
};

//��ʼ��ѡ����Ϣ
int initData(map<int, Speaker> &smp,vector<int> &v)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());
	for (unsigned int i = 0; i < 24; i++)
	{
		string name = "ѡ��";
		name = name + str[i];
		Speaker tmp(name, i + 100);
		smp.insert(make_pair(tmp.id,tmp));
		v.push_back(tmp.id);
	}
	return 0;
}


//��ʼ����
int startGame(int index, map<int, Speaker> &map, vector<int> &v1, vector<int> &v2)
{
	printf("��%d�ֱ�����ʼ\n",index+1);
	random_shuffle(v1.begin(), v1.end());
	//���ռ�����,�Խ���ķ�ʽ
	multimap<int, int,greater<int>> mscore;
	deque<int> dscore;
	int tmpcount = 0;
	int num = 1;
	for (std::vector<int>::iterator it = v1.begin();it != v1.end(); it++)
	{
		{
			tmpcount++;
			//���д��
			for (unsigned int j = 0; j < 10; j++)
			{
				int score = 50 + rand() % 50;
				dscore.push_back(score);
			}
			sort(dscore.begin(), dscore.end());
			dscore.pop_front();
			dscore.pop_back();
			//����ƽ����
			int sumScore=accumulate(dscore.begin(), dscore.end(), 0);
			int avgScore = sumScore / dscore.size();
			map[*it].score[index] = avgScore;
			mscore.insert(pair<int, int>(avgScore,*it));
			dscore.clear();
		}
		if (tmpcount % 6 == 0)
		{
			printf("��%d�ֵ�%dС��ɼ�\n", index + 1,num);
			for (multimap<int, int>::iterator its = mscore.begin(); its != mscore.end(); its++)
			{
				cout << "ѡ�ֱ��: " << its->second<< "\tѡ������: " << map[its->second].name<< "\tѡ�ֳɼ�: " << its->first << endl;
			}
			while (mscore.size() > 3)
			{
				multimap<int, int,greater<int>>::iterator mit = mscore.begin();
				v2.push_back(mit->second);
				mscore.erase(mit);
			}
			mscore.clear();
			tmpcount = 0;
			num++;
		}
	}
	num = 1;
	return 0;
}

void print_score(int index,map<int, Speaker> &map, vector<int> &v)
{
	printf("��������Ϊ:\n");
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ��id: " << *it << "\tѡ������: " << map[*it].name << "\tѡ�ַ���: " << map[*it].score[index] << endl;
	}
}

int main0101(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	map<int, Speaker> smp;
	vector<int> v1;//��һ�ֱ���
	initData(smp, v1);
	
	vector<int> v2;//��1�ν���С��
	startGame(0,smp, v1,v2);
	print_score(0,smp, v2);
	printf("-------------------------------------------\n");

	vector<int> v3;//��2�ν���С��
	startGame(1, smp, v2, v3);
	print_score(1, smp, v3);
	printf("-------------------------------------------\n");

	vector<int> v4;//��2�ν���С��
	startGame(2, smp, v3, v4);
	print_score(2, smp, v4);
	
	return 0;
}


/**
 * ����pair��value����������
 */
bool myLess(const pair<int, int> &left, const pair<int, int> &right)
{
	return left.second < right.second;
}

/**
 * ����pair��value��������
 */
bool myGreater(const pair<int, int> &left, const pair<int, int> &right)
{
	return left.second > right.second;
}

//���庯��ָ��
typedef bool(*MySortBy)(const pair<int, int> &left, const pair<int, int> &right);


vector<pair<int, int>> sortByValue(const map<int, int> &m, MySortBy sb= myLess)
{
	vector < pair<int, int>> res;
	for (auto &_pait:m)
	{
		res.push_back(_pait);
	}
	sort(res.begin(), res.end(), sb);
	return res;
}

/**
 * ����pair��ֵ��������
 */
void main_sort_by_pairvalue()
{
	map<int, int> m;
	m.insert(make_pair(1, 31));
	m.insert(make_pair(2, 22));
	m.insert(make_pair(3, 60));
	m.insert(make_pair(4, 99));
	m.insert(make_pair(5, 88));
	vector<pair<int, int>> v = sortByValue(m, myGreater);
	for (pair<int, int> _pair : v)
	{
		cout << _pair.first << " " << _pair.second << endl;
	}
}

template <typename T>
struct MyMapSort 
{
	bool  operator()(const T t1, const T t2)
	{
		return (t1 < t2);
	}
};

void main_test_map()
{
	map<int, int, MyMapSort<int>> m;
	m.insert(pair<int, int>(2, 67));
	m.insert(pair<int, int>(8, 55));
	m.insert(pair<int, int>(5, 99));
	m.insert(pair<int, int>(1, 23));
	m.insert(pair<int, int>(3, 18));
	for (auto &_pair:m)
	{
		cout << _pair.first << " " << _pair.second << endl;
	}
}

/**
 * map ���� pair��ֵ��������
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	main_sort_by_pairvalue();
	main_test_map();
	return 0;
}