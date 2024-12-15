#include<iostream>
#include<vector>
using namespace std;
//[À¶ÇÅ±­ 2022 Ê¡ A] ÇóºÍ
int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	long long ret = 0;
	while (n--)
	{
		int a;
		cin >> a;
		ret += a * sum;
		sum += a;
	}
	cout << ret << endl;
	return 0;
}