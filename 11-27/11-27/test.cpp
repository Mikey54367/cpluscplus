#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
//回文字串
int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    int ret = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (i == j) dp[i][j] = true;
            else if (i + 1 == j && s[i] == s[j]) dp[i][j] = true;
            else if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true;
            else dp[i][j] = false;
            if (dp[i][j]) ret++;
        }

    }
    return ret;
}
//最长回文子串
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    string ret;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (i == j) dp[i][j] = true;
            else if (s[i] == s[j] && (j == i + 1 || dp[i + 1][j - 1]))
                dp[i][j] = true;
            else dp[i][j] = false;
            if (dp[i][j] && j - i + 1 > ret.size())
                ret = s.substr(i,  j- i + 1);
        }
    }
    return ret;
}
//删除字符串中的相邻重复项
string removeDuplicates(string s) {
    string ret;
    for (auto ch : s)
    {
        if (ret.size() && ch == ret.back()) ret.pop_back();
        else ret += ch;
    }
    return ret;
}
//比较含退格的字符串
bool backspaceCompare(string s, string t) {
    string s1;
    string s2;
    for (auto ch : s)
    {
        if (s1.size() && ch == '#') s1.pop_back();
        else if (ch != '#') s1 += ch;
    }
    for (auto ch : t)
    {
        if (s2.size() && ch == '#') s2.pop_back();

        else if (ch != '#')s2 += ch;
    }
    return s1 == s2;
}
int main()
{
    longestPalindrome("babad");
    string s1 = "s";
    string s2 = "aaaaaaaaaaaaaaaaaa";
    s1 = s2.substr(1,3);
    cout << s1 << endl;
	return 0;
}