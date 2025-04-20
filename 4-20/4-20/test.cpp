#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//k次取反后最大化的数组和
int largestSumAfterKNegations(vector<int>& nums, int k) {
    int mini = INT_MAX;
    int cnt = 0;
    for (auto e : nums)
    {
        if (abs(e) < mini) mini = abs(e);
    }
    sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] < 0 && k>0)
        {
            k--;
            ret += -nums[i];
        }
        else if (k > 0)
        {
            //nums[i]>=0
            ret += nums[i];
        }
        else if (nums[i] < 0)
        {
            ret += nums[i];
        }
        else
        {
            ret += nums[i];
        }
    }
    if (k % 2)
        ret -= 2 * abs(mini);
    return ret;
}
int main()
{
    vector<int> v{ -2,5,0,-2,2 };
    cout<<largestSumAfterKNegations(v,3)<<endl;
    return 0;
}