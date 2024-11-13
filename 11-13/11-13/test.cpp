#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//删除并获得点数
int deleteAndEarn(vector<int>& nums) {
    int min = *min_element(nums.begin(), nums.end());
    int max = *max_element(nums.begin(), nums.end());
    vector<int> arr(max - min + 1);
    for (int i = 0; i < nums.size(); ++i)
    {
        arr[nums[i] - min] += nums[i];
    }
    vector<int> f(max - min + 1);
    vector<int> g(max - min + 1);
    f[0] = arr[0];
    for (int i = 1; i < f.size(); ++i)
    {
        f[i] = g[i - 1] + arr[i];
        g[i] = std::max(g[i - 1], f[i - 1]);
    }
    return std::max(f.back(), g.back());
}
//粉刷房子
int minCost(vector<vector<int>>& costs) {
    vector<vector<int>> dp(costs.size(), vector<int>(3));
    dp[0][0] = costs[0][0]; dp[0][1] = costs[0][1]; dp[0][2] = costs[0][2];
    for (int i = 1; i < costs.size(); ++i)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
    }
    return *min_element(dp[costs.size() - 1].begin(), dp[costs.size() - 1].end());
}
//最小K个数
int Rand(vector<int>& arr, int left, int right)
{
    srand((unsigned int)time(NULL));
    return arr[rand() % (right - left + 1) + left];
}
void qsort(vector<int>& arr, int left, int right, int k)
{
    if (left >= right - 1) return;
    int oldLeft = left, oldRight = right;
    int key = Rand(arr, left + 1, right - 1);
    for (int i = left + 1; i < right;)
    {
        if (arr[i] < key) swap(arr[++left], arr[i++]);
        else if (arr[i] == key) i++;
        else swap(arr[--right], arr[i]);
    }
    if (left - oldLeft > k) qsort(arr, oldLeft, left + 1, k);
    else if (right - 1 - oldLeft >= k) return;
    else qsort(arr, right - 1, oldRight, k + 1 + oldLeft - right);
}
vector<int> smallestK(vector<int>& arr, int k) {
    int left = -1; int right = arr.size();
    qsort(arr, left, right, k);
    if (arr.size() == 0) return vector<int>();
    return vector<int>{&arr[0], & arr[k]};
}
//归并排序
void mergeSort(vector<int>& nums, int left, int right, vector<int>& arr)
{
    if (left >= right-1) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid, arr);
    mergeSort(nums, mid, right, arr);
    int k = left;
    int i = 0, j = 0;
    for (i = left, j = mid; i < mid && j < right;)
    {
        if (nums[i] <= nums[j]) arr[k++] = nums[i++];
        else arr[k++] = nums[j++];
    }
    while (i < mid) arr[k++] = nums[i++];
    while (j < right) arr[k++] = nums[j++];
    memcpy(&nums[left], &arr[left], sizeof(int) * (right - left));
}
vector<int> sortArray(vector<int>& nums) {
    vector<int> arr(nums.size());
    mergeSort(nums, 0, nums.size(), arr);
    return nums;
}

int main()
{
    vector<int> v{ 5,2,3,1 };
    sortArray(v);
	return 0;
}