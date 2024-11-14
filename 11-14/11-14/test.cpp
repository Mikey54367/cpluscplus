#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//买卖股票的最佳时机含冷冻期
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(3));
    dp[0][0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][2] = dp[i - 1][0] + prices[i];
    }
    return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
}
//买卖股票的最佳时机手续费
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> f(n);
    vector<int> g(n);
    f[0] = -prices[0];
    for (int i = 1; i < n; ++i)
    {
        f[i] = max(f[i - 1], g[i - 1] - prices[i]);
        g[i] = max(g[i - 1], f[i - 1] + prices[i] - fee);
    }
    return max(f[n - 1], g[n - 1]);
}
//股票3
int maxProfit3(vector<int>& prices) {
    int n = prices.size();
    int k = 2;
    vector<vector<int>> f(n, vector<int>(k + 1));
    vector<vector<int>> g(n, vector<int>(k + 1));
    f[0][0] = f[0][1] = f[0][2] = -prices[0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
            g[i][j] = g[i - 1][j];
            if (j >= 1)
                g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
        }
    }
    return *max_element(g[n - 1].begin(), g[n - 1].end());
}
//股票4
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    //int k=2;
    vector<vector<int>> f(n, vector<int>(k + 1));
    vector<vector<int>> g(n, vector<int>(k + 1));
    for (int i = 0; i <= k; ++i)
        f[0][i] = -prices[0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
            g[i][j] = g[i - 1][j];
            if (j >= 1)
                g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
        }
    }
    return *max_element(g[n - 1].begin(), g[n - 1].end());
}
int main()
{
	return 0;
}