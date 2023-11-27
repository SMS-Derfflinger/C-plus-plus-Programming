#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define  N  10000	//intervals.length的最大值

bool compare(vector<int>& a, vector<int>& b)	//比较函数，下面的sort函数中要用，当a的结束时间小于b的结束时间时，返回true，否则返回false
{
	return a[1] < b[1];
}

int countPlay(vector<vector<int>>& intervals)	//计算需要的放映厅的最少数量
{
	sort(intervals.begin(), intervals.end(), compare);		//按结束时间从早到晚排序
	int endtime = 0;
	vector<int> playRoom = { 0 };
	for (const auto& lines : intervals)		//遍历intervals数组，判断每场电影的结束时间是否早于下一场电影的开始时间，若不早于给num+1
	{	
		bool sign = false;
		int size = playRoom.size();
		for (int i = 0; i < size; i++)
		{	
			if (playRoom[i] < lines[0])
			{
				playRoom[i] = lines[1];
				sign = true;
				break;
			}
		}
		if (!sign)
			playRoom.push_back(lines[1]);
	}
	int num = playRoom.size();
	return num;
}

void input(vector<vector<int>>& intervals)
{
	vector<int> lines(2, 0);	//intervals的每一行，每场电影的开始时间与结束时间
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
		lines[0] = starti;
		lines[1] = endi;
		intervals.push_back(lines);
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
	cout  << countPlay(intervals) << endl;
}

int main()
{
	vector<vector<int>> intervals;
	input(intervals);
	output(intervals);
	return 0;
}