#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//买卖股票最佳时机含手续费
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> dp1(n);
    vector<int> dp2(n);
    dp1[0] = -prices[0];
    for (int i = 1; i < n; ++i)
    {
        dp1[i] = max(dp1[i - 1], dp2[i - 1] - prices[i]);
        dp2[i] = max(dp2[i - 1], dp1[i - 1] + prices[i] - fee);
    }
    return dp2[n - 1];
}
//股票3
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> f(n, vector<int>(3));
    vector<vector<int>> g(n, vector<int>(3));
    f[0][0] = -prices[0];
    f[0][1] = g[0][1] = -1000000;
    f[0][2] = g[0][2] = -1000000;
    for (int i = 1; i < n; ++i)
    {
        f[i][0] = max(f[i - 1][0], -prices[i]);
        for (int j = 1; j <= 2; ++j)
        {
            f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
            g[i][j] = max(f[i - 1][j - 1] + prices[i], g[i - 1][j]);
        }
    }
    return max(g[n - 1][0], max(g[n - 1][1], g[n - 1][2]));
}
//股票4
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> f(n, vector<int>(k + 1));
    vector<vector<int>> g(n, vector<int>(k + 1));
    f[0][0] = -prices[0];

    for (int i = 1; i <= k; ++i)
    {
        f[0][i] = g[0][i] = -1000000;
    }
    for (int i = 1; i < n; ++i)
    {
        f[i][0] = max(f[i - 1][0], -prices[i]);
        for (int j = 1; j <= k; ++j)
        {
            f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
            g[i][j] = max(f[i - 1][j - 1] + prices[i], g[i - 1][j]);
        }
    }
    int ret = 0;
    for (int i = 0; i <= k; ++i)
    {
        ret = max(ret, g[n - 1][i]);
    }
    return ret;
}
//最大子数组和
int maxSubArray(vector<int>& nums) {
    //dp[i]表示已=以i位置为末尾的子数组的最大和
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int sum = dp[0];
    int Min = min(0, dp[0]);
    for (int i = 1; i < n; ++i)
    {
        sum += nums[i];
        dp[i] = sum - Min;
        Min = min(Min, sum);

    }
    return *max_element(dp.begin(), dp.end());
}
//环形子数组最大和
int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int sum = dp[0];
    int Max = max(dp[0], 0);
    for (int i = 1; i < n; ++i)
    {
        sum += nums[i];
        dp[i] = sum - Max;
        Max = max(Max, sum);
    }
    int Min = *min_element(dp.begin(), dp.end());
    if (sum == Min) return maxSubArray(nums);
    return max(sum - Min, maxSubArray(nums));
}
int main()
{
    vector<int> v{ -3,-2,-3 };
    maxSubarraySumCircular(v);
	return 0;
}