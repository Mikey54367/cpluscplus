#include<iostream>
#include<vector>
using namespace std;
//������Ʊ�����ʱ��2
int maxProfit(vector<int>& prices) {
    int ret = 0;
    int cur = prices[0];
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > cur)
        {
            ret += prices[i] - cur;
            cur = prices[i];
        }
        else
        {
            cur = prices[i];
        }
    }
    //ret+=cur;
    return ret;
}
int main()
{
	return 0;
}