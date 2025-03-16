#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//按摩师
int massage(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> f(n);
    vector<int> g(n);
    f[0] = nums[0];
    f[1] = nums[1];
    g[0] = 0;
    g[1] = f[0];
    for (int i = 2; i < n; ++i)
    {
        f[i] = g[i - 1] + nums[i];
        g[i] = max(g[i - 1], f[i - 1]);
    }
    return max(f[n - 1], g[n - 1]);
}
//打家劫舍2
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    vector<int> f(n);
    vector<int> g(n);
    f[0] = nums[0];
    f[1] = nums[1];
    g[1] = nums[0];
    for (int i = 2; i < n - 1; ++i)
    {
        f[i] = g[i - 1] + nums[i];
        g[i] = max(f[i - 1], g[i - 1]);
    }
    int ret = max(f[n - 2], g[n - 2]);
    f[0] = nums[1];
    f[1] = nums[2];
    g[1] = nums[1];
    for (int i = 2; i < n - 1; ++i)
    {
        f[i] = g[i - 1] + nums[i + 1];
        g[i] = max(f[i - 1], g[i - 1]);
    }
    return max(ret, max(f[n - 2], g[n - 2]));
}
//删除并获得点数
int deleteAndEarn(vector<int>& nums) {
    vector<int> arr(10001);
    for (auto e : nums)
    {
        arr[e] += e;
    }
    vector<int> f(10001);
    vector<int> g(10001);
    f[0] = arr[0];
    f[1] = arr[1];
    g[1] = arr[0];
    for (int i = 2; i < 10001; ++i)
    {
        f[i] = g[i - 1] + arr[i];
        g[i] = max(g[i - 1], f[i - 1]);
    }
    return max(f[10000], g[10000]);
}
//粉刷房子
int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
    }
    return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}
//买卖股票最佳时机含冷冻期
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp1(n);//买入状态
    vector<int> dp2(n);//卖出状态
    vector<int> dp3(n);//冷冻期状态
    dp1[0] = -prices[0];
    for (int i = 1; i < n; ++i)
    {
        dp1[i] = max(dp1[i - 1], dp3[i - 1] - prices[i]);
        dp2[i] = max(dp2[i - 1], dp1[i - 1] + prices[i]);
        dp3[i] = dp2[i - 1];
    }
    return max(max(dp1[n - 1], dp2[n - 1]), dp3[n - 1]);
}
int main()
{
	
	return 0;
}