#include<iostream>
#include<vector>
using namespace std;
//组合总和
class Solution0 {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        dfs(candidates, target, 0);
        return ret;
    }
    void dfs(vector<int>& candidates, int target, int index)
    {
        if (target == 0)
        {
            ret.emplace_back(path);
            return;
        }
        if (target < 0)
            return;
        int prev = 1;
        for (int i = index; i < candidates.size(); ++i)
        {
            if (candidates[i] == prev) continue;
            else prev = candidates[i];
            target -= candidates[i];
            path.emplace_back(candidates[i]);
            dfs(candidates, target, i);
            target += candidates[i];
            path.pop_back();
        }
    }
};
//字母大小写全排列
class Solution1 {
    vector<string> ret;
    string path;
public:
    vector<string> letterCasePermutation(string s)
    {
        dfs(s, 0);
        return ret;
    }
    void dfs(string s, int i)
    {
        if (i == s.size())
        {
            ret.emplace_back(path);
            return;
        }
        if ('a' <= s[i] && s[i] <= 'z')
        {
            path += s[i];
            dfs(s, i + 1);
            path.pop_back();
            path += (s[i] - 'a' + 'A');
            dfs(s, i + 1);
            path.pop_back();
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            path += s[i];
            dfs(s, i + 1);
            path.pop_back();
            path += (s[i] + 'a' - 'A');
            dfs(s, i + 1);
            path.pop_back();
        }
        else
        {
            path += s[i];
            dfs(s, i + 1);
            path.pop_back();
        }

    }
};
//优美的排列
class Solution2 {
    int ret;
    vector<int> path;
    bool check[16] = { false };
public:
    int countArrangement(int n) {
        dfs(n);
        return ret;
    }
    void dfs(int n)
    {
        if (path.size() == n)
        {
            ret++;
            return;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!check[i])
            {
                check[i] = true;
                path.emplace_back(i);
                if (i % path.size() == 0 || path.size() % i == 0)
                    dfs(n);
                check[i] = false;
                path.pop_back();
            }
        }
    }
};
#include<unordered_map>
using namespace std;
//等差数列划分2
int numberOfArithmeticSlices(vector<int>& nums)
{
    int n = nums.size();
    int ret = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    unordered_map<long long, vector<int>> hash;
    for (int i = 0; i < n; ++i)
    {
        hash[nums[i]].emplace_back(i);
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            long long a = 2 * (long long)nums[i] - (long long)nums[j];
            if (hash.count(a))
            {
                for (int k = 0; k < hash[a].size(); ++k)
                {
                    if (hash[a][k] < i)
                        dp[i][j] += dp[hash[a][k]][i] + 1;
                }
            }
            ret += dp[i][j];
        }
    }
    return ret;
}
//回文字串
int countSubstrings(string s) {
    int n = s.size();
    int ret = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    //i为起始位置 j为末位置
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                if (i == j || i + 1 == j)
                {
                    dp[i][j] = true;
                    ret++;
                }
                else if (dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    ret++;
                }
            }
        }
    }
    return ret;
}
int main()
{
    string s{ "aaa" };
    countSubstrings(s);
    vector<int> v{ 0,2000000000,-294967296 };
    numberOfArithmeticSlices(v);
    int n = 4;
    vector<string> path(n, string(n, '.'));
    return 0;
}