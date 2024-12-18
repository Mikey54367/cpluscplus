#include<iostream>
#include <cmath>
using namespace std;
//模拟
//[蓝桥杯 2014 国 C] 拼接平方数
bool isSquareNumber(int i)
{
	if (i == 0) return false;
	if (((int)sqrt(i) * (int)sqrt(i)) == i) return true;
	return false;
}
bool isSpliceSquareNumber(int i)
{
	int a = 1;
	int b = 0;
	int k = 1;
	while (a)
	{
		a = i / (int)pow(10,k);
		b = i % (int)pow(10,k);
		if (isSquareNumber(a) && isSquareNumber(b)) return true;
		++k;
	}
	return false;
}
int main()
{
	int a;
	int b;
	cin >> a >> b;
	for (int i = a; i <= b; ++i)
	{
		if (isSquareNumber(i))
		{
			if (isSpliceSquareNumber(i))
				cout << i << endl;
		}
	}
	return 0;
}
//int main()
//{
//	return 0;
//}