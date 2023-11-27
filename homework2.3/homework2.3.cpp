#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define  N  10000	//intervals.length的最大值

bool compare(vector<int>& a, vector<int>& b)	//比较函数，下面的sort函数中要用，当a的开始时间小于b的开始时间时，返回true，否则返回false
{
	return a[0] < b[0];
}

vector<vector<int>> combine(vector<vector<int>>& intervals)		//计算结果数组
{
	vector<vector<int>> answer;		//结果数组
	sort(intervals.begin(), intervals.end(), compare);		//按开始时间从早到晚排序
	answer.push_back(intervals[0]);		//把开始时间最早的电影存储到answer的第一个位置
	int size = intervals.size();
	for (int i = 1; i < size; i++)	//遍历intervals，若当前电影的开始时间大于结果数组中最后一个电影的结束时间，则将当前时间段加入结果数组，否则合并时间段
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
	cout << "请依次输入每场电影的开始和结束时间，以空格分隔，遇到回车结束" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> starti >> endi;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(N, '\n');
			cout << "输入错误，请从错误项重新输入" << endl;
			continue;
		}
		if (!(starti < endi))
		{
			cin.ignore(N, '\n');
			cout << "结束时间不能早于开始时间，请从错误项重新输入" << endl;
			continue;
		}
		if (starti < 0 || 100000 < starti || endi < 0 || 100000 < endi)
		{
			cin.ignore(N, '\n');
			cout << "输入的范围错误，请从错误项重新输入" << endl;
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
	cout << "输入的播放时间安排为：[ ";
	for (const auto& lines : intervals)		//遍历intervals数组
		cout << "[" << lines[0] << "," << lines[1] << "] ";
	cout << "]" << endl;
	vector<vector<int>> answer = combine(intervals);
	cout << "[ ";
	for (const auto& lines : answer)	//遍历answer数组
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