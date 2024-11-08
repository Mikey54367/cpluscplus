#include<iostream>
#include<vector>
using namespace std;
//动态规划 解码方法

int numDecodings(string s) {
    vector<int> dp(s.size());
    dp[0] = 1;
    if (s[0] == '0') return 0;
    if (s.size() == 1) return 1;
    if (s[0] == '1')
    {
        if (s[1] == '0') dp[1] = 1;
        else dp[1] = 2;
    }
    else if (s[0] == '2')
    {
        if (s[1] == '0' || s[1] > '6') dp[1] = 1;
        else dp[1] = 2;
    }

    else if (s[1] != '0') dp[1] = 1;

    for (int i = 2; i < dp.size(); ++i)
    {
        if (s[i] != '0') dp[i] += dp[i - 1];
        if (s[i - 1] == '1') dp[i] += dp[i - 2];
        if (s[i - 1] == '2' && s[i] < '7') dp[i] += dp[i - 2];
    }
    return dp.back();
}
int main()
{
    string s{ "301" };
    numDecodings(s);
	return 0;
}