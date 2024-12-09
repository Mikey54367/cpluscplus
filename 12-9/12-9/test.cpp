#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//长度最小的子数组
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int ret = n + 1;
    int left = 0; int right = 1;
    int sum = nums[0];
    while (right < n)
    {
        if (sum < target)
        {
            sum += nums[right];
            right++;
        }
        else
        {
            ret = min(ret, right - left);
            sum -= nums[left];
            left++;
        }
    }
    while (left < n)
    {
        if (sum >= target)
        {
            ret = min(ret, right - left);
            sum -= nums[left];
            left++;
        }
        else break;
    }
    return (ret % (n + 1));
}
int main()
{
	return 0;
}