#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define  N  10000	//intervals.length�����ֵ

bool compare(vector<int>& a, vector<int>& b)	//�ȽϺ����������sort������Ҫ�ã���a�Ľ���ʱ��С��b�Ľ���ʱ��ʱ������true�����򷵻�false
{
	return a[1] < b[1];
}

bool judgement(vector<vector<int>>& intervals)
{
	sort(intervals.begin(), intervals.end(), compare);		//������ʱ����絽������
	int endtime = 0;
	for (const auto& lines : intervals)		//����intervals���飬�ж�ÿ����Ӱ�Ľ���ʱ���Ƿ�������һ����Ӱ�Ŀ�ʼʱ�䣬�������ڷ���false
	{
		if (lines[0] >= endtime)
			endtime = lines[1];
		else
			return false;
	}
	return true;	//�����е�Ӱ�Ľ���ʱ�䶼������һ����Ӱ�Ŀ�ʼʱ���򷵻�true
}

void input(vector<vector<int>>& intervals)
{
	vector<int> lines(2, 0);	//intervals��ÿһ�У�ÿ����Ӱ�Ŀ�ʼʱ�������ʱ��
	int starti, endi;
	cout << "����������ÿ����Ӱ�Ŀ�ʼ�ͽ���ʱ�䣬�Կո�ָ��������س�����" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> starti >> endi;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(N, '\n');
			cout << "���������Ӵ�������������" << endl;
			continue;
		}
		if (!(starti < endi))
		{
			cin.ignore(N, '\n');
			cout << "����ʱ�䲻�����ڿ�ʼʱ�䣬��Ӵ�������������" << endl;
			continue;
		}
		if (starti < 0 || 100000 < starti || endi < 0 || 100000 < endi)
		{
			cin.ignore(N, '\n');
			cout << "����ķ�Χ������Ӵ�������������" << endl;
			continue;
		}
		lines[0] = starti;
		lines[1] = endi;
		intervals.push_back(lines);
		if (cin.get() == '\n')
			break;
	}
}

void output(vector<vector<int>>& intervals)
{
	cout << "����Ĳ���ʱ�䰲��Ϊ��[ ";
	for (const auto& lines : intervals)		//����intervals����
		cout << "[" << lines[0] << "," << lines[1] << "] ";
	cout << "]" << endl;
	cout << boolalpha << judgement(intervals) << endl;		//�����������״̬��1���true��0���false
}

int main()
{
	vector<vector<int>> intervals;
	input(intervals);
	output(intervals);
	return 0;
}