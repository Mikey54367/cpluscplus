#include<iostream>
#include<vector>
using namespace std;
//环形数组最大值
int maxSubArray(vector<int>& nums) {
    //int sumMin=0;
    //int sum=0;
    //int ret=INT_MIN;
    //for(int i=0;i<nums.size();++i)
    //{
        //sum+=nums[i];
        //ret=max(ret,sum-sumMin);
        //sumMin=min(sum,sumMin);
    //}
    //return ret;
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i)
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    return *max_element(dp.begin(), dp.end());
}
int minSubArray(vector<int>& nums)
{
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) sum += nums[i];
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i)
        dp[i] = min(dp[i - 1] + nums[i], nums[i]);
    if (sum == *min_element(dp.begin(), dp.end()))
        return INT_MIN;
    return sum - *min_element(dp.begin(), dp.end());
}
int maxSubarraySumCircular(vector<int>& nums) {
    return max(maxSubArray(nums), minSubArray(nums));
}
//乘积最大子数组
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n);
    vector<int> g(n);
    f[0] = g[0] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        f[i] = max(nums[i], max(nums[i] * f[i - 1], nums[i] * g[i - 1]));
        g[i] = min(nums[i], min(nums[i] * f[i - 1], nums[i] * g[i - 1]));
    }
    return *max_element(f.begin(), f.end());
}
//乘积为整数的最长子数组长度
int getMaxLen(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n);
    vector<int> g(n);
    if (nums[0] > 0) f[0]++;
    if (nums[0] < 0) g[0]++;
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] > 0)
        {
            f[i] = f[i - 1] + 1;
            if (g[i - 1])
                g[i] = g[i - 1] + 1;
        }
        if (nums[i] < 0)
        {
            if (g[i - 1])
                f[i] = g[i - 1] + 1;
            g[i] = f[i - 1] + 1;
        }

    }
    return *max_element(f.begin(), f.end());
}
int main()
{
    vector<int> v{ 2,3,-2,4 };
    maxProduct(v);
    return 0;
}