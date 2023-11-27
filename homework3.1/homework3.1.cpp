#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
#define  N  (int)1e5
#define  MIN  (int)-1e9
#define  MAX  (int)1e9

bool judgement(vector<int>& nums)
{
	unordered_set<int> numSet;
	for (const auto& num : nums)	//遍历数组中的每个元素，将元素作为键存储在哈希表中
	{
		if (numSet.count(num) > 0)	//检查当前元素是否已经存在于哈希表中
			return true;
		numSet.insert(num);
	}
	return false;
}

void input(vector<int>& nums)
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
		if (!cin.good())
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
}

void output(vector<int>& nums)
{
	int size = nums.size();
	cout << "输入为: ";
	for (const auto& num : nums)
		cout << num << " ";
	cout << endl;
	cout << boolalpha << judgement(nums) << endl;	//设置输出流的状态，1输出true，0输出false
}

int main()
{
	vector<int> nums;
	input(nums);
	output(nums);
	return 0;
}