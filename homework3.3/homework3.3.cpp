#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
constexpr auto N = (int)1e5;
constexpr auto MIN = (int)-1e9;
constexpr auto MAX = (int)1e9;

bool judgement(vector<int>& nums, int indexDiff, int valueDiff)
{
	unordered_map<int, int> buckets;	//�洢Ͱ�������Ͷ�Ӧ��Ԫ��
	int width = valueDiff + 1;		//Ͱ�Ŀ��
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		int num = nums[i];
		int bucketIndex = num / width;		//��Ӧ��Ͱ������
		if (num < 0)	//��Ԫ��Ϊ����ʱ������������Ͱ��������1�����򿿽�0������������������Ϊ0��Ͱ
			bucketIndex--;
		if (buckets.count(bucketIndex) > 0)		//��鵱ǰͰ�Ƿ��Ѿ�����Ԫ�أ��������˵����������������true
			return true;
		if (buckets.count(bucketIndex - 1) > 0 && abs(buckets[bucketIndex - 1] - num) <= valueDiff)		//���ǰһ��Ͱ�Ƿ���������
			return true;
		if (buckets.count(bucketIndex + 1) > 0 && abs(buckets[bucketIndex + 1] - num) <= valueDiff)		//����һ��Ͱ�Ƿ���������
			return true;
		buckets[bucketIndex] = num;
		if (i >= indexDiff)		//�Ƴ�����indexDiff��Χ��Ͱ
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
	cout << "����������(-10^9 <= nums[i] <= 10^9)���Կո�ָ��������س�����" << endl;
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
		if (cin.get() == '\n' && i > 0)
			break;
	}
	int temp;
	int size = nums.size();
	bool validInput = false;
	cout << "����������indexDiff(1 <= indexDiff <= " << size << "): ";
	while (!validInput)
	{
		cin >> temp;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�����������������indexDiff" << endl;
		}
		else if (temp < 1 || size < temp)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "indexDiff�ķ�Χ��������������indexDiff" << endl;
		}
		else
			validInput = true;
	}
	indexDiff = temp;
	validInput = false;
	cout << "����������valueDiff(0 <= valueDiff <= 10^9): ";
	while (!validInput)
	{
		cin >> temp;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�����������������valueDiff" << endl;
			continue;
		}
		else if (temp < 0 || MAX < temp)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "valueDiff�ķ�Χ��������������valueDiff" << endl;
			continue;
		}
		else
			validInput = true;
	}
	valueDiff = temp;
}

void output(vector<int>& nums, int indexDiff, int valueDiff)
{
	cout << "����Ϊ��";
	for (const auto& num : nums)
		cout << num << " ";
	cout << endl;
	cout << "indexDiff: " << indexDiff << endl;
	cout << "valueDiff: " << valueDiff << endl;
	cout << boolalpha << judgement(nums, indexDiff, valueDiff) << endl;	//�����������״̬��1���true��0���false
}

int main()
{
	vector<int> nums;
	int indexDiff, valueDiff;
	input(nums, indexDiff, valueDiff);
	output(nums, indexDiff, valueDiff);
	return 0;
}