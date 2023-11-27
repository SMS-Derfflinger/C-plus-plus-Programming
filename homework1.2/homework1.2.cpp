#include <iostream>
#include <vector>
using namespace std;
#define  N  105		//prices.length�����ֵ

int maxProfit(vector<int> prices)
{
	int buy = INT_MIN;
	int sell = 0;
	int size = prices.size();
	for (int i = 0; i < size; i++)
	{
		buy = max(buy, -prices[i]);			//����Ļ���
		sell = max(sell, buy + prices[i]);	//����������
	}
	return sell;
}

vector<int> input()
{
	vector<int> prices;
	int price;
	cout << "������ɼۣ�0-104�����Կո�ָ��������س�����" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> price;
		if (price < 0 || 104 < price)
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

void print(vector<int> prices)
{
	int size = prices.size();
	cout << "����Ĺɼ�Ϊ��";
	for (int i = 0; i < size; i++)
		cout << prices[i] << " ";
	cout << endl;
	cout << "�������Ϊ��" << maxProfit(prices) << endl;
}

int main()
{
	vector<int> prices = input();	//����
	print(prices);					//���

	return 0;
}