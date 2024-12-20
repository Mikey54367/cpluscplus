#include<iostream>
using namespace std;
//[À¶ÇÅ±­ 2024 Ê¡ B] ºÃÊý
bool isGoodNum(int n)
{
	int flag = 1;
	while (n)
	{
		if ((n % 10)%2 != flag)
			return false;
		n /= 10;
		flag = (flag + 1) % 2;
	}
	return true;
}
int main()
{
	int n=24;
	cin >> n;
	int ret = 0;
	for (int i = 1; i <= n; i+=2)
	{
		if (isGoodNum(i)) ret++;
	}
	cout << ret << endl;
	return 0;
}