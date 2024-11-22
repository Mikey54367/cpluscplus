#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//最长递增子序列个数
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> len(n, 1);
    vector<int> count(n, 1);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                if (len[i] == len[j] + 1) count[i] += count[j];
                else if (len[i] < len[j] + 1)
                {
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                }
            }
        }
    }
    int ret = 1; int maxVal = len[0];
    for (int i = 1; i < n; ++i)
    {
        if (len[i] > maxVal)
        {
            maxVal = len[i];
            ret = count[i];
        }
        else if (len[i] == maxVal)
        {
            ret += count[i];
        }
    }
    return ret;
}
//最长数对链
struct CompareLess {
    bool operator()(vector<int>& v1, vector<int>& v2)
    {
        return (v1[0] < v2[0]);
    }
};
int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    CompareLess com;
    sort(pairs.begin(), pairs.end(), com);
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
//两数之和
//struct Compare {
//    bool operator()(pair<int, int> p1, pair<int, int> p2)
//    {
//        return p1.first < p2.first;
//    }
//};
//vector<int> twoSum(vector<int>& nums, int target) {
//    vector<pair<int, int>> v(nums.size());
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        v[i] = { nums[i],i };
//    }
//    sort(v.begin(), v.end(), Compare());
//    int left = 0; int right = nums.size() - 1;
//    while (left < right)
//    {
//        if (v[left].first + v[right].first == target) return { v[left].second,v[right].second };
//        else if (v[left].first + v[right].first > target) right--;
//        else left++;
//    }
//    return { 143,134 };
//}
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    hash[nums[0]] = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        if (hash.find(target - nums[i]) != hash.end()) return { hash[target - nums[i]],i };
        hash[nums[i]] = i;
    }
    return { 0,0 };
}
//判断是否为字符重排
bool CheckPermutation(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    char hash[26] = { 0 };
    for (int i = 0; i < s1.size(); ++i)
    {
        hash[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.size(); ++i)
    {
        hash[s2[i] - 'a']--;
        if (hash[s2[i] - 'a'] < 0)
            return false;
    }
    
    return true;
}
//重复元素1
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> hash;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (hash.find(nums[i]) != hash.end()) return true;
        hash.insert(nums[i]);
    }
    return false;
}
//重复元素2
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = hash.find(nums[i]);
        if (it != hash.end())
        {
            if (abs(i - (it->second)) <= k) return true;
        }
        hash[nums[i]] = i;
    }
    return true;
}
int main()
{
    vector<int> v{ 1,2,3,1,2,3 };
    containsNearbyDuplicate(v, 2);
    //findNumberOfLIS(v);
	return 0;
}