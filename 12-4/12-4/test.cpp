#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i - 1] == '*') dp[0][i] = true;
        else break;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*') dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
int main()
{
    isMatch("cb", "?a");
	return 0;
}