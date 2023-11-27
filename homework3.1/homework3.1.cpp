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
	for (const auto& num : nums)	//���������е�ÿ��Ԫ�أ���Ԫ����Ϊ���洢�ڹ�ϣ����
	{
		if (numSet.count(num) > 0)	//��鵱ǰԪ���Ƿ��Ѿ������ڹ�ϣ����
			return true;
		numSet.insert(num);
	}
	return false;
}

void input(vector<int>& nums)
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
		if (!cin.good())
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
}

void output(vector<int>& nums)
{
	int size = nums.size();
	cout << "����Ϊ: ";
	for (const auto& num : nums)
		cout << num << " ";
	cout << endl;
	cout << boolalpha << judgement(nums) << endl;	//�����������״̬��1���true��0���false
}

int main()
{
	vector<int> nums;
	input(nums);
	output(nums);
	return 0;
}