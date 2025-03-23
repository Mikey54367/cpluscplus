#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
//最小覆盖字串
string minWindow(string s, string t) {
    unordered_map<char, int> hash_t;
    for (int i = 0; i < t.size(); ++i)
    {
        hash_t[t[i]]++;
    }
    unordered_map<char, int> hash_s;
    int left = 0;
    int right = 0;
    int count = 0;
    int ret_index = s.size() + 1;
    int ret_len = s.size() + 1;
    while (right < s.size())
    {
        hash_s[s[right]]++;
        if (hash_t[s[right]] && hash_t[s[right]] >= hash_s[s[right]])
            count++;
        ++right;
        while (count == t.size())
        {
            if (ret_len > right - left)
            {
                ret_len = right - left;
                ret_index = left;
            }
            if (hash_t[s[left]] && hash_t[s[left]] >= hash_s[s[left]])
            {
                count--;
            }
            hash_s[s[left]]--;
            left++;
        }
    }
    if (ret_len == s.size() + 1) return "";
    return s.substr(ret_index, ret_len);
}
//二分查找
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = left + (right - left) / 2;
    while (left <= right)
    {
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
        mid = left + (right - left) / 2;
    }
    return -1;
}
//最长斐波那契子序列长度
int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 2));
    unordered_map<int, int> hash;//value index
    hash[arr[0]] = 0;
    hash[arr[1]] = 1;
    int max_len = 0;
    for (int i = 2; i < n; ++i)
    {
        for (int j = i - 1; j > 0; --j)
        {
            if (hash.count(arr[i] - arr[j]) && arr[j] > arr[i] - arr[j])
            {
                dp[i][j] = dp[j][hash[arr[i] - arr[j]]] + 1;
                max_len = max(max_len, dp[i][j]);
            }
        }
        hash[arr[i]] = i;
    }
    return max_len;
}
//最长等差序列
int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 2));
    unordered_map<int, int> hash;
    hash[nums[0]] = 0;
    int ret = 2;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int a = 2 * nums[i] - nums[j];
            if (hash.count(a))
            {
                dp[i][j] = dp[hash[a]][i] + 1;
                ret = max(ret, dp[i][j]);
            }
        }
        hash[nums[i]] = i;
    }
    return ret;
}
int searchLeft(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    if (right == -1) return -1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return nums[left] == target ? left : -1;
}
int searchRight(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    if (right == -1) return -1;
    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;
        if (nums[mid] > target) right = mid - 1;
        else left = mid;
    }
    return nums[left] == target ? left : -1;
}
//在排序数组中查找元素的第一个位置和最后一个位置
vector<int> searchRange(vector<int>& nums, int target) {

    return { searchLeft(nums,target),searchRight(nums,target) };
}
int main()
{
    vector<int> v{ 7,7,7,7};
	return 0;
}