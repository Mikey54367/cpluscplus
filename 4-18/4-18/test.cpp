#include<iostream>
#include<vector>
using namespace std;
//������Ʊ�����ʱ��
int maxProfit(vector<int>& prices) {
    int ret = 0;
    int cur = prices[0];
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > cur)
        {
            ret = max(ret, prices[i] - cur);
        }
        else
            cur = prices[i];
    }
    return ret;
}
int main()
{

	return 0;
}