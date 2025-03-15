#include<iostream>
#include<vector>
using namespace std;
//第 n 个泰波那契数
//int tribonacci(int n) {
//    if (n == 0) return 0;
//    if (n == 1) return 1;
//    if (n == 2) return 1;
//    vector<int> dp(n + 1, 0);
//    dp[0] = 0;
//    dp[1] = 1;
//    dp[2] = 1;
//    for (int i = 3; i <= n; ++i)
//    {
//        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//    }
//    return dp[n];
//}
////三步问题
//int waysToStep(int n) {
//    vector<int> dp(n + 1, 0);
//    if (n == 1) return 1;
//    if (n == 2) return 2;
//    if (n == 3) return 4;
//    dp[1] = 1;
//    dp[2] = 2;
//    dp[3] = 4;
//    for (int i = 4; i <= n; ++i)
//    {
//        dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000007 + dp[i - 3]) % 1000000007;
//    }
//    return dp[n];
//}
////使用最小花费爬楼梯
//int minCostClimbingStairs(vector<int>& cost) {
//    int n = cost.size();
//    vector<int> dp(n + 1);
//    for (int i = 2; i <= n; ++i)
//    {
//        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//    }
//    return dp[n];
//}
////解码方法
//int numDecodings(string s) {
//    int n = s.size();
//    vector<int> dp(n + 1, 0);
//    dp[0] = dp[1] = 1;
//    if (s[0] == '0') return 0;
//    for (int i = 2; i <= n; ++i)
//    {
//        if (s[i - 1] != '0')
//            dp[i] += dp[i - 1];
//        if ((s[i - 2] == '1') || (s[i - 2] == '2' && (s[i - 1] >= '0' && s[i - 1] <= '6')))
//            dp[i] += dp[i - 2];
//    }
//    return dp[n];
//}
////不同路径
//int uniquePaths(int m, int n) {
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//    dp[1][1] = 1;
//    for (int i = 1; i <= m; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
//        }
//    }
//    return dp[m][n];
//}
////不同路径2
//int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//    int m = obstacleGrid.size();
//    int n = obstacleGrid[0].size();
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//    dp[0][1] = 1;
//
//    for (int i = 1; i <= m; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            if (obstacleGrid[i - 1][j - 1] == 0)
//                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
//        }
//    }
//    return dp[m][n];
//}
////珠宝的最高价值
//int jewelleryValue(vector<vector<int>>& frame) {
//    int m = frame.size();
//    int n = frame[0].size();
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//    for (int i = 1; i <= m; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
//        }
//    }
//    return dp[m][n];
//}

//下降路径最小和
#include<algorithm>
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = INT_MAX;
        dp[i][n + 1] = INT_MAX;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
    int ret = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        if (dp[n][i] < ret) ret = dp[n][i];

    }
    return ret;
}
//最小路径和
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[0][1] = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    return dp[m][n];
}
//地下城游戏
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m][n - 1] = 1;
    for (int i = m - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
        {
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            if (dp[i][j] <= 0) dp[i][j] = 1;
        }
    return dp[0][0];
}
int main()
{
    std::vector<int> v1(2);
    std::vector<int> v2(2);
    v1[0] = 17;
    v1[1] = 82;
    v2[0] = 1;
    v2[1] = -44;
    std::vector<std::vector<int>> vv(2);
    vv[0] = v1;
    vv[1] = v2;
    minFallingPathSum(vv);
	return 0;
}