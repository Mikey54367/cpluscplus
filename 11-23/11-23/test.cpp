#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//最长定差子序列
int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    vector<int> dp(n, 1);
    unordered_map<int, int> hash;
    hash[arr[0]] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (hash.count(arr[i] - difference)) dp[i] = hash[arr[i] - difference] + 1;
        hash[arr[i]] = dp[i];
    }
    return *max_element(dp.begin(), dp.end());
}
//最长斐波那契子序列的长度
int lenLongestFibSubseq(vector<int>& arr) {
    unordered_map<int, int> hash;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        hash[arr[i]] = i;
    }
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int ret = 0;
    for (int j = 2; j < n; ++j)
    {
        for (int i = 1; i < j; ++i)
        {
            if (hash.count(arr[j] - arr[i]))
            {
                if (hash[arr[j] - arr[i]] < i)
                    dp[i][j] = dp[hash[arr[j] - arr[i]]][i] + 1;
            }
            ret = max(ret, dp[i][j]);
        }
    }
    return ret < 3 ? 0 : ret;
}
//字母异位词分组
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hash;
    for (int i = 0; i < strs.size(); ++i)
    {
        string s = strs[i];
        sort(strs[i].begin(), strs[i].end());
        hash[strs[i]].emplace_back(move(s));
    }
    auto it = hash.begin();
    vector<vector<string>> ret;
    while (it != hash.end())
    {
        ret.emplace_back(move(it->second));
        ++it;
    }
    return ret;
}
//最长公共前缀
string find(string& str1, string& str2)
{
    string ret;
    for (int i = 0; i < str1.size() && i < str2.size(); ++i)
    {
        if (str1[i] == str2[i]) ret += str1[i];
        else break;
    }
    return ret;
}
string longestCommonPrefix(vector<string>& strs) {
    string ret = strs[0];
    for (int i = 1; i < strs.size(); ++i)
    {
        ret = find(ret, strs[i]);
    }
    return ret;
}
int main()
{
    vector<string> v{ "eat", "tea", "tan", "ate", "nat", "bat" };
    groupAnagrams(v);
	return 0;
}