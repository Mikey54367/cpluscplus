#include<iostream>
#include<vector>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
    int ret = 0;
    int left = 0;
    int right = 0;
    int count = 0;
    while (right < nums.size())
    {
        if (nums[right] == 0) count++;
        right++;
        if (count > k)
        {
            while (nums[left])
            {
                left++;
            }
            left++;
            count--;
        }
        ret = max(ret, right - left);
    }
    return ret;
}
int main()
{
	
}