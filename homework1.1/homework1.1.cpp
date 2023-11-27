#include <iostream>
#include <vector>
using namespace std;
#define  N  105		//prices.length的最大值

vector<int> input()
{
	vector<int> prices;
	int price;
	cout << "请输入股价（30-100），以空格分隔，遇到回车结束" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> price;
		if (price < 30 || 100 < price)
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

void print(vector<int> prices, vector<int> answer)
{
	int size = prices.size();
	cout << "输入的股价为：";
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
	vector<int> prices = input();			//输入
	vector<int> answer = Nextup(prices);	
	print(prices, answer);					//输出

	return 0;
}