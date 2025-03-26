#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
//和为k的子数组
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    unordered_map<int, int> hash;
    // key--sum   value--num
    hash[dp[0]] = 1;
    int ret = 0;
    if (dp[0] == k) ret++;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = dp[i - 1] + nums[i];
        if (dp[i] == k) ret++;
        ret += hash[dp[i] - k];
        hash[dp[i]]++;
    }
    return ret;
}
//和可被k整除的子数组
int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int ret = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;
    if (dp[0] % k == 0) ret++;
    hash[(dp[0] % k + k) % k]++;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = dp[i - 1] + nums[i];
        ret += hash[(dp[i] % k + k) % k]++;
    }
    return ret;
}
//连续数组
int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == 0) nums[i] = -1;
    }
    vector<int> dp(n);
    dp[0] = nums[0];
    unordered_map<int, int> hash;
    hash[0] = -1;
    hash[dp[0]] = 0;
    int ret = 0;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = dp[i - 1] + nums[i];
        if (hash.count(dp[i]))
        {
            ret = max(ret, i - hash[dp[i]]);
        }
        if (!hash.count(dp[i]))
        {
            hash[dp[i]] = i;
        }
    }
    return ret;
}
//矩阵区域和
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }
    vector<vector<int>> ret(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ret[i][j] = dp[min(i + 1 + k, m)][min(j + 1 + k, n)] - dp[min(i + 1 + k, m)][max(0, j - k)] - dp[max(0, i - k)][min(j + 1 + k, n)] + dp[max(0, i - k)][max(0, j - k)];
        }
    }
    return ret;
}
//判断字符是否唯一
bool isUnique(string astr) {
    if (astr.size() > 26) return false;
    int n = astr.size();
    int bit = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((bit >> astr[i] - 'a') & 1) return false;
        bit = bit | (1 << astr[i] - 'a');
    }
    return true;
}
int main()
{
    isUnique("leetcode");
    vector<vector<int>> vv{ {1,2,3},{4,5,6} ,{7,8,9} };
    matrixBlockSum(vv,1);
	return 0;
}