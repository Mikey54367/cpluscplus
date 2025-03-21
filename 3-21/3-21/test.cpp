#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
// 无重复字符的最长字串
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int n = s.size();
    if (n == 0)
        return 0;
    int left = 0;
    hash.insert({ s[left], left });
    int right = 1;
    int ret = 1;
    while (right < n) {
        if (hash.count(s[right])) {
            ret = max(right - left, ret);
            while (left < n && left != hash[s[right]]) {
                hash.erase(s[left]);
                ++left;
            }
            ++left;
            // left = hash[s[right]] + 1;
            hash[s[right]] = right;
            right++;
        }
        else {
            right++;
            ret = max(right - left, ret);
            hash.insert({ s[right - 1], right - 1 });
        }
    }
    return ret;
}
//最长连续1的个数
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0;
    int right = 0;
    int ret = 0;
    while (right < n) {
        if (nums[right] == 0)
        {
            k--;
            if (k < 0)
            {
                while (nums[left] == 1) ++left;
                ++left;
                k++;
                right++;
                ret = max(ret, right - left);
            }
            else
            {
                right++;
                ret = max(ret, right - left);
            }
        }
        else
        {
            right++;
            ret = max(ret, right - left);
        }
    }
    return ret;
}
//将x减小到0的最小操作数
int findMaxSumSubX(vector<int>& nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = 0;
    int sum = 0;
    int ret = 0;
    while (right < n)
    {
        sum += nums[right++];
        while (left<n && left <= right && sum>target) sum -= nums[left++];
        if (sum == target) ret = max(ret, right - left);
    }
    return ret;
}
int minOperations(vector<int>& nums, int x) {
    int sum = 0;
    for (auto& e : nums) sum += e;
    int n = nums.size();
    if (sum == x) return n;
    int maxSumSubX = findMaxSumSubX(nums, sum - x);
    if (maxSumSubX == 0) return -1;
    return n - maxSumSubX;
}
//水果成篮
int totalFruit(vector<int>& fruits) {
    vector<int> basket(2, -1);
    int left = 0;
    int right = 1;
    int n = fruits.size();
    basket[0] = fruits[left];
    int ret = 1;
    while (right < n)
    {
        if (fruits[right] == basket[0] || fruits[right] == basket[1])
        {
            right++;
            ret = max(ret, right - left);
        }
        else if (basket[1] == -1)
        {
            basket[1] = fruits[right];
            right++;
            ret = max(ret, right - left);
        }
        else
        {
            basket[0] = fruits[right];
            basket[1] = fruits[right - 1];
            int tmp = left;
            while (left < right)
            {
                if (fruits[left] != basket[0] && fruits[left] != basket[1])
                {
                    tmp = left;
                }
                ++left;
            }
            left = tmp + 1;
            right++;
            ret = max(ret, right - left);
        }
    }
    return ret;
}
//最长定差子序列
int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    vector<int> dp(n, 1);
    unordered_map<int, int> hash;
    //first is value
    //second is index
    hash[arr[0]] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (hash.count(arr[i] - difference)) dp[i] = dp[hash[arr[i] - difference]] + 1;
        hash[arr[i]] = i;
    }
    return *max_element(dp.begin(), dp.end());
}
int main()
{
    vector<int> v{ 6,-2,0,3,-7,6,-5,-8 };
    cout<< longestSubsequence(v, 2)<<endl;
	return 0;
}