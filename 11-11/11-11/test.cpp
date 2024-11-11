#include<iostream>
#include<vector>
using namespace std;
//最小路径和
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, -1));
    dp[1][0] = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
    return (int)dp[m][n];

}
//地下城游戏
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
            dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
    return dp[0][0];
}
//替换所有问号
string modifyString(string s) {
    if (s[0] == '?')
    {
        s[0] = 'a';
        if (s[0] == s[1])
            s[0]++;
    }if (s[s.size() - 1] == '?')
    {
        s[s.size() - 1] = 'a';
        if (s[s.size() - 1] == s[s.size() - 2])
            s[s.size() - 1]++;
    }

    for (int i = 1; i < s.size() - 1; ++i)
    {
        if (s[i] == '?')
        {
            s[i] = 'a';
            if (s[i] == s[i - 1])
            {
                s[i]++;
                if (s[i] == s[i + 1])
                    s[i]++;
            }
            if (s[i] == s[i + 1])
            {
                s[i]++;
                if (s[i] == s[i - 1])
                    s[i]++;
            }
        }

    }
    return s;
}
//提莫攻击
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int ret = 0;
    for (int i = 1; i < timeSeries.size(); ++i)
    {
        if (timeSeries[i] - timeSeries[i - 1] >= duration) ret += duration;
        else ret += timeSeries[i] - timeSeries[i - 1];
    }
    ret += duration;
    return ret;
}
//Z字形变换
string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int d = 2 * numRows - 2;
    string ret;
    int i = 0;
    while (i < s.size())
    {
        ret += s[i];
        i += d;
    }
    for (i = 1; i < numRows - 1; ++i)
    {

        for (int j = i, k = d - j; j < s.size();)
        {

            ret += s[j];
            if (k < s.size()) ret += s[k];
            j += d; k += d;
        }
    }
    for (i = numRows - 1; i < s.size();)
    {
        ret += s[i];
        i += d;
    }
    return ret;
}
//外观数组
string countAndSay(int n) {
    if (n == 1) return "1";
    string ret = "11";
    for (int i = 3; i <= n; ++i)
    {
        int count = 1;
        char a = ret[0];
        string tmp;
        for (int j = 1; j < ret.size(); ++j)
        {
            if (ret[j] == a) count++;
            else
            {
                tmp += (count + '0');
                tmp += a;
                a = ret[j];
                count = 1;
            }
        }
        tmp += (count + '0');
        tmp += a;
        swap(tmp, ret);
    }
    return ret;
}
//数青蛙
int minNumberOfFrogs(string croakOfFrogs) {
    int c = 0, r = 0, o = 0, a = 0, k = 0;
    for (int i = 0; i < croakOfFrogs.size(); ++i)
    {
        if (croakOfFrogs[i] == 'c')
        {
            if (k) k--;
            c++;
        }
        if (croakOfFrogs[i] == 'r')
        {
            if (c) c--, r++;
            else return -1;
        }

        if (croakOfFrogs[i] == 'o')
        {
            if (r) r--, o++;
            else return -1;
        }
        if (croakOfFrogs[i] == 'a')
        {
            if (o) o--, a++;
            else return -1;
        }
        if (croakOfFrogs[i] == 'k')
        {
            if (a) a--, k++;
            else return -1;
        }


    }
    if (c || r || o || a) return -1;
    return k;
}
int main()
{
    countAndSay(4);
    vector<vector<int>> vv{ {1,-3,3}, { 0,-2,0 },{-3,-3,-3} };
    calculateMinimumHP(vv);
	return 0;
}