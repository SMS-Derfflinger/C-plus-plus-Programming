#include <iostream>
#include <vector>
using namespace std;
#define  N  105		//prices.length的最大值

int maxProfit(vector<int> prices)
{
	int buy = INT_MIN;
	int sell = 0;
	int size = prices.size();
	for (int i = 0; i < size; i++)
	{
		buy = max(buy, -prices[i]);			//买入的花费
		sell = max(sell, buy + prices[i]);	//卖出的利润
	}
	return sell;
}

vector<int> input()
{
	vector<int> prices;
	int price;
	cout << "请输入股价（0-104），以空格分隔，遇到回车结束" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> price;
		if (price < 0 || 104 < price)
		{
			cin.clear();
			cin.ignore(N, '\n');
			cout << "输入的范围错误，请从错误项重新输入" << endl;
			continue;
		}
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(N, '\n');
			cout << "输入错误，请从错误项重新输入" << endl;
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
	cout << "输入的股价为：";
	for (int i = 0; i < size; i++)
		cout << prices[i] << " ";
	cout << endl;
	cout << "最大利润为：" << maxProfit(prices) << endl;
}

int main()
{
	vector<int> prices = input();	//输入
	print(prices);					//输出

	return 0;
}