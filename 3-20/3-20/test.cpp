#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;
//���ʲ��
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> hash;
    for (auto& e : wordDict)
    {
        hash.insert(e);
    }
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (dp[j] == true)
            {
                if (hash.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[n];
}
//�����ַ����е�Ψһ���ַ���
int findSubstringInWraproundString(string s) {
    int n = s.size();
    vector<int> dp(n, 1);
    dp[0] = 1;
    unordered_map<char, int> hash;
    hash.insert({ s[0],1 });
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1] + 1) dp[i] = dp[i - 1] + 1;
        if (s[i] == 'a' && s[i - 1] == 'z') dp[i] = dp[i - 1] + 1;
        if (hash.count(s[i])) hash[s[i]] = max(dp[i], hash[s[i]]);
        else hash.insert({ s[i],dp[i] });
    }
    int ret = 0;
    for (auto& e : hash)
    {
        ret += e.second;
    }
    return ret;
}
//�����������
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
//�ڶ�����
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n, 1);//����ǰһ��
    vector<int> g(n, 1);//С��ǰһ��
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (nums[i] > nums[j]) f[i] = max(f[i], g[j] + 1);
            if (nums[i] < nums[j]) g[i] = max(g[i], f[j] + 1);
        }
    }
    return max(*max_element(f.begin(), f.end()), *max_element(g.begin(), g.end()));
}
//����������еĸ���
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> dp(n, { 1,1 });
    int Max = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (nums[i] > nums[j])
            {
                if (dp[i].first < dp[j].first + 1)
                {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = dp[j].second;
                }
                else if (dp[i].first == dp[j].first + 1)
                {
                    dp[i].second += dp[j].second;
                }
            }
        }
        Max = max(dp[i].first, Max);
    }
    int ret = 0;
    for (auto& e : dp)
    {
        if (e.first == Max) ret += e.second;
    }
    return ret;
}
//�������
class Compare
{
public:
    bool operator()(vector<int>&v1,vector<int>&v2)
    {
        return v1[0] < v2[0];
    }
};
int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    vector<int> dp(n, 1);
    sort(pairs.begin(), pairs.end(), Compare());
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (pairs[i][0] > pairs[j][1])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
//������С��������
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = 1;
    int sum = nums[0];
    if (sum > target) return 1;
    int ret = n + 1;
    while (right < n)
    {
        sum += nums[right];
        right++;
        while (sum >= target)
        {
            ret = min(ret, right - left);
            sum -= nums[left];
            left++;
        }
    }
    if (ret == n + 1) return 0;
    return ret;
}

int main()
{
    
	return 0;
}