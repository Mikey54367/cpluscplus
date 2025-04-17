#include<iostream>
#include<vector>
using namespace std;
int findLengthOfLCIS(vector<int>& nums) {
    int cur = 1;
    int ret = 1;
    int prev = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > prev)
        {
            cur++;
            ret = max(ret, cur);
            prev = nums[i];
        }
        else
        {
            prev = nums[i];
            cur = 1;
        }
    }
    return ret;
}
int main()
{
	return 0;
}