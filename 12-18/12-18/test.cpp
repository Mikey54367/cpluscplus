#include<iostream>
using namespace std;
//[���ű� 2022 ʡ B] ˢ��ͳ��
int main()
{
	long long a;
	long long b;
	long long n;
	cin >> a >> b >> n;
	long long ret = 0;
	long long finishPerWeek = 5 * a + 2 * b;
	ret = n / finishPerWeek;
	long long finish = 0;
	finish = finishPerWeek * ret;
	ret *= 7;
	int k = 1;
	while (finish < n)
	{
		if (k <= 5) finish += a;
		else finish += b;
		k++;
		ret++;
	}
	cout << ret << endl;
	return 0;
}