#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
//最长等差子序列
int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int ret = 2;
    unordered_map<int, int> hash;
    hash[nums[0]] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int a = 2 * nums[i] - nums[j];
            if (hash.count(a)) dp[i][j] = dp[hash[a]][i] + 1;
            ret = max(ret, dp[i][j]);
        }
        hash[nums[i]] = i;
    }
    return ret;
}
//等差数列划分2 子序列
int numberOfArithmeticSlices(vector<int>& nums) {
    unordered_map<long long, vector<int>> hash;
    int n = nums.size();
    for (int i = 0; i < n; ++i) hash[nums[i]].emplace_back(i);
    vector<vector<int>> dp(n, vector<int>(n));
    int ret = 0;
    for (int j = 2; j < n; ++j)
    {
        for (int i = 1; i < j; ++i)
        {
            long long a = (long long)2 * nums[i] - nums[j];
            if (hash.count(a))
            {
                for (int k = 0; k < hash[a].size(); ++k)
                {
                    if (hash[a][k] >= i) break;
                    dp[i][j] += dp[hash[a][k]][i] + 1;
                }
            }
            ret += dp[i][j];
        }
    }
    return ret;
}
//最长回文字串
string longestPalindrome(string s) {
    int n = s.size();
    string ret;
    int longestStr = 0;
    int leftOfLongestStr = 0;
    for (int i = 0; i < n; ++i)
    {
        //先找奇数
        int left = i - 1, right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        if ((right - left - 1) > longestStr)
        {
            longestStr = right - left - 1;
            leftOfLongestStr = left + 1;
        }
        //找偶数
        left = i - 1, right = i;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        if ((right - left - 1) > longestStr)
        {
            longestStr = right - left - 1;
            leftOfLongestStr = left + 1;
        }
    }
    ret = s.substr(leftOfLongestStr, longestStr);
    return ret;
}
//字符串相乘
string add(string num1, string num2)
{
    string ret;
    int t = 0;
    int cur1 = num1.size() - 1;
    int cur2 = num2.size() - 1;
    while (cur1>=0 || cur2 >=0|| t)
    {
        if (cur1>=0) t += num1[cur1--]-'0';
        if (cur2>=0) t += num2[cur2--]-'0';
        ret += t % 10 + '0';
        t = t / 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string multiply(string num1, string num2) {
    string ret;
    int cur1 = 0;
    while (cur1 < num1.size())
    {
        int cur2 = num2.size() - 1;
        string tmpRet;
        int t = 0;
        while (cur2 >= 0 || t)
        {
            if (cur2>=0) t = (num1[cur1] - '0') * (num2[cur2] - '0') + t;
            tmpRet += t % 10 + '0';
            t = t / 10;
            --cur2;
        }
        reverse(tmpRet.begin(), tmpRet.end());
        ret += '0';
        ret = add(ret, tmpRet);
        cur1++;
    }
    int len = 0;
    for (int i = 0; i < ret.size() - 1; ++i)
    {
        if (ret[i] == '0') ++len;
        else break;
    }
    if (len > 0)
    {
        ret.erase(0, len);
    }
    return ret;
}
int main()
{
    multiply("9133", "0");
	return 0;
}