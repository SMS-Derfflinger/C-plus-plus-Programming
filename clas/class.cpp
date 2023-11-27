#include <iostream>
using namespace std;

template <class TT>
class FF
{
public:
	FF(TT b1, TT b2, TT b3) {
		a1 = b1; a2 = b2; a3 = b3;
	}
	TT Sum() {
		return a1 + a2 + a3;
	}
private:
	TT a1, a2, a3;
};
int main()
{
	FF<int> x(8, 3, 4), y(5, 9, 11);
	cout << x.Sum() << " " << y.Sum() << endl;
	system("pause");
	return 0;
}