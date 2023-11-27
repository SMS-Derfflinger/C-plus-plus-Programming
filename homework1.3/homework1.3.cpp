#include <iostream>
#include <vector>
using namespace std;
#define  N  5000	//prices.length的最大值

int maxProfit(vector<int> prices)
{
	int buy = INT_MIN;	//确保buy在第一次循环时正确赋值
	int sell = 0;
	int freeze = 0;
	int size = prices.size();
	for (int i = 0; i < size; i++)
	{
		int oldsell = sell;                     //前一天卖出的利润
		sell = max(sell, buy + prices[i]);      //当天卖出的利润
		buy = max(buy, freeze - prices[i]);		//买入的花费
		freeze = max(freeze, oldsell);          //卖出后的冷却期
	}	//在卖出后，经过两次循环才能更新到买入，对应一天的冷却期
	return sell;
}

vector<int> input()
{
	vector<int> prices;
	int price;
	cout << "请输入股价（0-1000），以空格分隔，遇到回车结束" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> price;
		if (price < 0 || 1000 < price)
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
	vector<int> prices = input();
	print(prices);

	return 0;
}