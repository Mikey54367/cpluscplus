#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//最长湍流子数组
int maxTurbulenceSize(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n);
    if (n == 1) return 1;
    if (n == 2)
    {
        if (arr[0] == arr[1]) return 1;
        return 2;
    }
    dp[0] = 1;
    dp[1] =arr[0] == arr[1] ? 1 : 2;
    for (int i = 2; i < n; ++i)
    {
        if ((arr[i - 1] > arr[i - 2] && arr[i - 1] > arr[i]) || (arr[i - 1] < arr[i - 2] && arr[i - 1] < arr[i]))
            dp[i] = dp[i - 1] + 1;
        else
        {
            if (arr[i] == arr[i - 1]) dp[i] = 1;
            else dp[i] = 2;
        };

    }
    return *max_element(dp.begin(), dp.end());
}
//单词拆分
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> hash;
    for (auto& e : wordDict) hash.insert(e);
    int n = s.size();
    vector<bool> dp(n + 1);
    dp[0] = true;
    s = ' ' + s;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (dp[j - 1] && hash.count(s.substr(j, i - j + 1)))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
//交易的逆序对总数
void reversePairs1(vector<int>& arr, int left, int right, int& ret, vector<int>& tmp)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    reversePairs1(arr, left, mid, ret, tmp);
    reversePairs1(arr, mid + 1, right, ret, tmp);
    int i1 = left; int i2 = mid + 1;
    int i = left;
    while (i1 <= mid && i2 <= right)
    {
        if (arr[i1] <= arr[i2])
        {
            tmp[i] = arr[i1];
            i1++;
            i++;
            ret += i2 - mid - 1;
        }
        else
        {
            tmp[i] = arr[i2];
            i++;
            i2++;
        }
    }
    while (i1 <= mid)
    {
        tmp[i++] = arr[i1++];
        ret += i2 - mid - 1;
    }
    while (i2 <= right)
    {
        tmp[i++] = arr[i2++];
    }
    memcpy(&arr[left], &tmp[left], (right - left + 1) * sizeof(int));
}
int reversePairs1(vector<int>& record) {
    int n = record.size();
    vector<int> tmp(n);
    int ret = 0;
    reversePairs1(record, 0, n - 1, ret, tmp);
    return ret;
}
//计算右侧小于当前元素个数
void countSmaller(vector<int>& nums, vector<int>& ret, vector<int>& index, vector<int>& tmp1, vector<int>& tmp2, int left, int right)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    countSmaller(nums, ret, index, tmp1, tmp2, left, mid);
    countSmaller(nums, ret, index, tmp1, tmp2, mid + 1, right);
    int i1 = left, i2 = mid + 1, i = left;
    while (i1 <= mid && i2 <= right)
    {
        if (nums[i1] <= nums[i2])
        {
            tmp1[i] = nums[i2];
            tmp2[i++] = index[i2++];
        }
        else
        {
            ret[index[i1]] += right - i2 + 1;
            tmp1[i] = nums[i1];
            tmp2[i++] = index[i1++];
        }
    }
    while (i1 <= mid)
    {
        tmp1[i] = nums[i1];
        tmp2[i++] = index[i1++];
    }
    while (i2 <= right)
    {
        tmp1[i] = nums[i2];
        tmp2[i++] = index[i2++];
    }
    memcpy(&nums[left], &tmp1[left], sizeof(int) * (right - left + 1));
    memcpy(&index[left], &tmp2[left], sizeof(int) * (right - left + 1));
}
vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> ret(n);
    vector<int> index(n);
    for (int i = 0; i < n; ++i) index[i] = i;
    vector<int> tmp1(n);
    vector<int> tmp2(n);
    countSmaller(nums, ret, index, tmp1, tmp2, 0, n - 1);
    return ret;
}
//翻转对
int reversePairs(vector<int>& nums, int left, int right, vector<int>& tmp)
{
    int ret = 0;
    if (left >= right) return ret;
    int mid = left + (right - left) / 2;
    ret += reversePairs(nums, left, mid, tmp);
    ret += reversePairs(nums, mid + 1, right, tmp);
    int i1 = left, i2 = mid + 1, i = left;
    while (i1 <= mid && i2 <= right)
    {
        if ((long long)nums[i1] > (long long)2 * nums[i2]) i2++;
        else
        {
            ret += i2 - mid - 1;
            i1++;
        }
    }
    if (i2 > right)
    {
        ret += (mid - i1 + 1) * (i2 - mid - 1);
    }
    i1 = left; i2 = mid + 1;
    while (i1 <= mid && i2 <= right)
    {
        if (nums[i1] <= nums[i2])
            tmp[i++] = nums[i1++];
        else
            tmp[i++] = nums[i2++];
    }
    while (i1 <= mid)
        tmp[i++] = nums[i1++];
    while (i2 <= right)
        tmp[i++] = nums[i2++];
    memcpy(&nums[left], &tmp[left], sizeof(int) * (right - left + 1));
    return ret;
}

int reversePairs(vector<int>& nums)
{
    int n = nums.size();
    vector<int> tmp(n);
    return reversePairs(nums, 0, n - 1, tmp);
}
int main()
{
    vector<int> v{ 1,3,2,3,1 };
    reversePairs(v);
	return 0;
}