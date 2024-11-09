#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的非空 子数组 的数目。
//
//子数组 是数组中 连续 的部分

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    int sum = 0; int ret = 0;
    hash[0] = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        if (hash.find((sum % k + k) % k) != hash.end())
            ret += hash[(sum % k + k) % k];
        hash[(sum % k + k) % k]++;
    }
    return ret;
}

//给定一个二进制数组 nums, 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度
int findMaxLength(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] == 0) nums[i] = -1;
    unordered_map<int, int> hash;
    hash[0] = -1;
    int sum = 0, ret = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        if (hash.find(sum) != hash.end()) ret = max(ret, i - hash[sum]);
        if (hash.find(sum) == hash.end()) hash[sum] = i;
    }
    return ret;
}
//矩阵区域和
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> answer(m, vector<int>(n));
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            int x1 = max(i - k, 0) + 1;
            int y1 = max(j - k, 0) + 1;
            int x2 = min(i + k, m) + 1;
            int y2 = min(j + k, n) + 1;
            answer[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];

        }
    return answer;
}
// 不同路径 无障碍
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m][n];
}
//不同路径 有障碍
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (obstacleGrid[i - 1][j - 1] == 1) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    return dp[m][n];
}
int main()
{


    return 0;
}