#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
constexpr auto N = (int)1e5;
constexpr auto MIN = (int)-1e9;
constexpr auto MAX = (int)1e9;

bool judgement(vector<int>& nums, int indexDiff, int valueDiff)
{
	unordered_map<int, int> buckets;	//存储桶的索引和对应的元素
	int width = valueDiff + 1;		//桶的宽度
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		int num = nums[i];
		int bucketIndex = num / width;		//对应的桶的索引
		if (num < 0)	//当元素为负数时，将其所属的桶的索引减1，否则靠近0两侧的数都会进到索引为0的桶
			bucketIndex--;
		if (buckets.count(bucketIndex) > 0)		//检查当前桶是否已经存在元素，如果存在说明满足条件，返回true
			return true;
		if (buckets.count(bucketIndex - 1) > 0 && abs(buckets[bucketIndex - 1] - num) <= valueDiff)		//检查前一个桶是否满足条件
			return true;
		if (buckets.count(bucketIndex + 1) > 0 && abs(buckets[bucketIndex + 1] - num) <= valueDiff)		//检查后一个桶是否满足条件
			return true;
		buckets[bucketIndex] = num;
		if (i >= indexDiff)		//移除超出indexDiff范围的桶
		{
			bucketIndex = nums[i - indexDiff] / width;
			if (nums[i - indexDiff] < 0)
				bucketIndex--;
			buckets.erase(bucketIndex);
		}
	}
	return false;
}

void input(vector<int>& nums, int& indexDiff, int& valueDiff)
{
	int num;
	cout << "请输入数组(-10^9 <= nums[i] <= 10^9)，以空格分隔，遇到回车结束" << endl;
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
		if (cin.get() == '\n' && i > 0)
			break;
	}
	int temp;
	int size = nums.size();
	bool validInput = false;
	cout << "请输入整数indexDiff(1 <= indexDiff <= " << size << "): ";
	while (!validInput)
	{
		cin >> temp;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "输入错误，请重新输入indexDiff" << endl;
		}
		else if (temp < 1 || size < temp)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "indexDiff的范围错误，请重新输入indexDiff" << endl;
		}
		else
			validInput = true;
	}
	indexDiff = temp;
	validInput = false;
	cout << "请输入整数valueDiff(0 <= valueDiff <= 10^9): ";
	while (!validInput)
	{
		cin >> temp;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "输入错误，请重新输入valueDiff" << endl;
			continue;
		}
		else if (temp < 0 || MAX < temp)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "valueDiff的范围错误，请重新输入valueDiff" << endl;
			continue;
		}
		else
			validInput = true;
	}
	valueDiff = temp;
}

void output(vector<int>& nums, int indexDiff, int valueDiff)
{
	cout << "输入为：";
	for (const auto& num : nums)
		cout << num << " ";
	cout << endl;
	cout << "indexDiff: " << indexDiff << endl;
	cout << "valueDiff: " << valueDiff << endl;
	cout << boolalpha << judgement(nums, indexDiff, valueDiff) << endl;	//设置输出流的状态，1输出true，0输出false
}

int main()
{
	vector<int> nums;
	int indexDiff, valueDiff;
	input(nums, indexDiff, valueDiff);
	output(nums, indexDiff, valueDiff);
	return 0;
}