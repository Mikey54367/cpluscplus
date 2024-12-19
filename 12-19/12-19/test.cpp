#include<iostream>
#include<vector>
using namespace std;
//将 x 减到 0 的最⼩操作数
int minOperations(vector<int>& nums, int x) {
    //n-中间区间==sum-x的最大值
    int n = nums.size();
    int left = 0;
    int right = 0;
    int ret = 0;
    int sum = 0;
    for (auto e : nums) sum += e;
    int targrt = sum - x;
    if (targrt == 0) return n;
    sum = 0;
    while (right < n)
    {
        sum += nums[right];
        right++;
        if (sum == targrt) ret = max(right - left, ret);
        while (left<right && sum>targrt)
        {
            sum -= nums[left];
            left++;
            if (sum == targrt) ret = max(right - left, ret);
        }
    }
    if (ret == 0) return -1;
    return n - ret;
}

int main()
{
    vector<int> v{ 1,0,1,4,1,4,1,2,3 };
	return 0;
}