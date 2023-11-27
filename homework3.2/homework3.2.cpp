#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#define  N  (int)1e5
#define  MIN  (int)-1e9
#define  MAX  (int)1e9

bool judgement(vector<int>& nums, int k)
{
	unordered_map<int,int> numIndex;	//存储数组中每个元素的最新索引
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		if (numIndex.count(nums[i]) > 0 && abs(i - numIndex[nums[i]]) <= k)		//检查当前元素是否已经在哈希表中且索引的差值是否不超过 k
			return true;
		numIndex[nums[i]] = i;
	}
	return false;
}

int input(vector<int>& nums)
{
	int num;
	cout << "请输入数组，以空格分隔，遇到回车结束" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num < MIN || MAX < num)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "输入的范围错误，请从错误项重新输入" << endl;
			i--;
			continue;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "输入错误，请从错误项重新输入" << endl;
			i--;
			continue;
		}
		nums.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	int k;
	bool validInput = false;
	cout << "请输入整数k: ";
	while (!validInput)
	{
		cin >> k;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "输入错误，请重新输入k" << endl;
		}
		else if (k < 0 || N < k)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "k的范围错误，请重新输入k" << endl;
		}
		else
			validInput = true;
	}
	return k;
}

void output(vector<int>& nums, int k)
{
	int size = nums.size();
	cout << "输入为: ";
	for (const auto& num : nums)
		cout << num << " ";
	cout << endl;
	cout << "k: " << k << endl;
	cout << boolalpha << judgement(nums, k) << endl;	//设置输出流的状态，1输出true，0输出false
}

int main()
{
	vector<int> nums;
	int k = input(nums);
	output(nums, k);
	return 0;
}