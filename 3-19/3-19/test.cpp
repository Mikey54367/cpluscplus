#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//四数之和
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int i = nums.size() - 1;
    while (i > 2)
    {
        int j = i - 1;
        while (j > 1)
        {
            int left = 0;
            int right = j - 1;
            while (left < right)
            {
                if ((long long)nums[left] + nums[right] + nums[j] + nums[i] == target)
                {
                    ret.emplace_back(vector<int>{nums[left], nums[right], nums[j], nums[i]});
                    int tmp = nums[right];
                    while (left < right && nums[right] == tmp) right--;
                }
                else if ((long long)nums[left] + nums[right] + nums[j] + nums[i] > target)
                {
                    int tmp = nums[right];
                    while (left < right && nums[right] == tmp) right--;
                }
                else
                {
                    int tmp = nums[left];
                    while (left < right && nums[left] == tmp) ++left;
                }
            }
            int tmp = nums[j];
            while (j > 1 && nums[j] == tmp) --j;
        }
        int tmp = nums[i];
        while (i > 2 && nums[i] == tmp) --i;
    }
    return ret;
}
//最长湍流子数组
int maxTurbulenceSize(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i)
    {
        if (i % 2)//单数
        {
            if (arr[i] > arr[i - 1]) dp[i] = dp[i - 1] + 1;
        }
        else
        {
            if (arr[i] < arr[i - 1]) dp[i] = dp[i - 1] + 1;
        }
    }
    vector<int> dp1(n, 1);
    for (int i = 1; i < n; ++i)
    {
        if (i % 2)//单数
        {
            if (arr[i] < arr[i - 1]) dp1[i] = dp1[i - 1] + 1;
        }
        else
        {
            if (arr[i] > arr[i - 1]) dp1[i] = dp1[i - 1] + 1;
        }
    }
    return max(*max_element(dp.begin(), dp.end()), *max_element(dp1.begin(), dp1.end()));
}
//等差数列划分
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    int ret = 0;
    for (int i = 2; i < n; ++i)
    {
        if ((nums[i - 1] * 2) == (nums[i - 2] + nums[i])) dp[i] = dp[i - 1] + 1;
        ret += dp[i];
    }
    return ret;
}
//乘积为整数的最长子数组
int getMaxLen(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp1(n);//正数
    vector<int> dp2(n);//负数
    if (nums[0] > 0) dp1[0] = 1;
    if (nums[0] < 0) dp2[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] > 0)
        {
            dp1[i] = dp1[i - 1] + 1;
            if (dp2[i - 1] != 0) dp2[i] = dp2[i - 1] + 1;
        }
        if (nums[i] < 0)
        {
            dp2[i] = dp1[i - 1] + 1;
            if (dp2[i - 1] != 0) dp1[i] = dp2[i - 1] + 1;
        }
    }
    return *max_element(dp1.begin(), dp1.end());
}
//乘积最大子数组
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp1(n);
    vector<int> dp2(n);
    dp1[0] = dp2[0] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        dp1[i] = max(nums[i], max(dp1[i - 1] * nums[i], dp2[i - 1] * nums[i]));
        dp2[i] = min(nums[i], min(dp1[i - 1] * nums[i], dp2[i - 1] * nums[i]));
    }
    return *max_element(dp1.begin(), dp1.end());
}
int main()
{
    vector<int> v{ 1,0,-1,0,-2,2 };
    fourSum(v,0);
	return 0;
}