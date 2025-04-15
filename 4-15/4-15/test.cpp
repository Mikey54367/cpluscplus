#include<iostream>
#include<string>
#include<vector>
using namespace std;
//最长递增子序列
int biFind(vector<int>& nums, int left, int right, int target);
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> tmp(n, 1000000);
    int k = 0;
    tmp[k] = nums[0];
    k++;
    for (int i = 1; i < n; ++i)
    {
        int a = nums[i];
        int b = biFind(tmp, 0, k, a);
        if (b == k)
            k++;
        tmp[b] = a;
    }
    return k;
}
int biFind(vector<int>& nums, int left, int right, int target)
{
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
int main()
{
	return 0;
}