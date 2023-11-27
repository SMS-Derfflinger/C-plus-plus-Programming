#include <iostream>
#include <vector>
using namespace std;
#define  N  5000	//prices.length�����ֵ

int maxProfit(vector<int> prices)
{
	int buy = INT_MIN;	//ȷ��buy�ڵ�һ��ѭ��ʱ��ȷ��ֵ
	int sell = 0;
	int freeze = 0;
	int size = prices.size();
	for (int i = 0; i < size; i++)
	{
		int oldsell = sell;                     //ǰһ������������
		sell = max(sell, buy + prices[i]);      //��������������
		buy = max(buy, freeze - prices[i]);		//����Ļ���
		freeze = max(freeze, oldsell);          //���������ȴ��
	}	//�������󣬾�������ѭ�����ܸ��µ����룬��Ӧһ�����ȴ��
	return sell;
}

vector<int> input()
{
	vector<int> prices;
	int price;
	cout << "������ɼۣ�0-1000�����Կո�ָ��������س�����" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> price;
		if (price < 0 || 1000 < price)
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
	vector<int> prices = input();
	print(prices);

	return 0;
}