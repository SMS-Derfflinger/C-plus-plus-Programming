#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define  N  10000	//intervals.length�����ֵ

bool compare(vector<int>& a, vector<int>& b)	//�ȽϺ����������sort������Ҫ�ã���a�Ŀ�ʼʱ��С��b�Ŀ�ʼʱ��ʱ������true�����򷵻�false
{
	return a[0] < b[0];
}

vector<vector<int>> combine(vector<vector<int>>& intervals)		//����������
{
	vector<vector<int>> answer;		//�������
	sort(intervals.begin(), intervals.end(), compare);		//����ʼʱ����絽������
	answer.push_back(intervals[0]);		//�ѿ�ʼʱ������ĵ�Ӱ�洢��answer�ĵ�һ��λ��
	int size = intervals.size();
	for (int i = 1; i < size; i++)	//����intervals������ǰ��Ӱ�Ŀ�ʼʱ����ڽ�����������һ����Ӱ�Ľ���ʱ�䣬�򽫵�ǰʱ��μ��������飬����ϲ�ʱ���
	{
		if (intervals[i][0] > answer.back()[1])
			answer.push_back(intervals[i]);
		else
			answer.back()[1] = max(answer.back()[1], intervals[i][1]);
	}
	return answer;
}

void input(vector<vector<int>>& intervals)
{
	vector<int> line(2, 0);
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
		line[0] = starti;
		line[1] = endi;
		intervals.push_back(line);
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
	vector<vector<int>> answer = combine(intervals);
	cout << "[ ";
	for (const auto& lines : answer)	//����answer����
		cout << "[" << lines[0] << "," << lines[1] << "] ";
	cout << "]" << endl;
}

int main()
{
	vector<vector<int>> intervals;
	input(intervals);
	output(intervals);
	return 0;
}