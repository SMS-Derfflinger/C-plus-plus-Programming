#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#define  N  (int)1e5
#define  MIN  (int)-1e9
#define  MAX  (int)1e9

bool judgement(vector<int>& nums, int k)
{
	unordered_map<int,int> numIndex;	//�洢������ÿ��Ԫ�ص���������
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		if (numIndex.count(nums[i]) > 0 && abs(i - numIndex[nums[i]]) <= k)		//��鵱ǰԪ���Ƿ��Ѿ��ڹ�ϣ�����������Ĳ�ֵ�Ƿ񲻳��� k
			return true;
		numIndex[nums[i]] = i;
	}
	return false;
}

int input(vector<int>& nums)
{
	int num;
	cout << "���������飬�Կո�ָ��������س�����" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num < MIN || MAX < num)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "����ķ�Χ������Ӵ�������������" << endl;
			i--;
			continue;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "���������Ӵ�������������" << endl;
			i--;
			continue;
		}
		nums.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	int k;
	bool validInput = false;
	cout << "����������k: ";
	while (!validInput)
	{
		cin >> k;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�����������������k" << endl;
		}
		else if (k < 0 || N < k)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "k�ķ�Χ��������������k" << endl;
		}
		else
			validInput = true;
	}
	return k;
}

void output(vector<int>& nums, int k)
{
	int size = nums.size();
	cout << "����Ϊ: ";
	for (const auto& num : nums)
		cout << num << " ";
	cout << endl;
	cout << "k: " << k << endl;
	cout << boolalpha << judgement(nums, k) << endl;	//�����������״̬��1���true��0���false
}

int main()
{
	vector<int> nums;
	int k = input(nums);
	output(nums, k);
	return 0;
}