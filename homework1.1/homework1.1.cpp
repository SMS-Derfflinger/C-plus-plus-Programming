#include <iostream>
#include <vector>
using namespace std;
#define  N  105		//prices.length�����ֵ

vector<int> input()
{
	vector<int> prices;
	int price;
	cout << "������ɼۣ�30-100�����Կո�ָ��������س�����" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> price;
		if (price < 30 || 100 < price)
		{
			cin.clear();
			cin.ignore(N, '\n');
			cout << "����ķ�Χ������Ӵ�������������" << endl;
			continue;
		}
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(N, '\n');
			cout << "���������Ӵ�������������" << endl;
			continue;
		}
		prices.push_back(price);
		if (cin.get() == '\n')
			break;
	}
	return prices;
}

void print(vector<int> prices, vector<int> answer)
{
	int size = prices.size();
	cout << "����Ĺɼ�Ϊ��";
	for (int i = 0; i < size; i++)
		cout << prices[i] << " ";
	cout << endl;
	cout << "answer: ";
	for (int i = 0; i < size; i++)
		cout << answer[i] << " ";
	cout << endl;
}

vector<int> Nextup(vector<int> prices)
{
	int size = prices.size();
	vector<int> answer(size, 0);
	for (int i = 0; i < size - 1; i++)
	{
		int member = 0;
		for (int j = i + 1; j < size; j++)
		{
			member++;
			if (prices[i] < prices[j])
			{
				answer[i] = member;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	vector<int> prices = input();			//����
	vector<int> answer = Nextup(prices);	
	print(prices, answer);					//���

	return 0;
}