#include<iostream>
#include<vector>
#include<string>

using namespace std;
//最优除法

string optimalDivision(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return to_string(nums[0]);
    if (n == 2)
        return to_string(nums[0]) + '/' + to_string(nums[1]);
    string ret;
    ret += to_string(nums[0]);
    ret += '/';
    ret += '(';
    for (int i = 1; i < n; ++i)
    {
        ret += to_string(nums[i]);
        if (i != n - 1)
            ret += '/';
    }
    ret += ')';
    return ret;
}
//跳跃游戏2
int jump(vector<int>& nums) {
    int i = 0;
    int ret = 0;
    int n = nums.size();
    nums[n - 1] = 11111;
    if (n == 1) return 0;
    while (i < n-1)
    {
        int k = nums[i];
        int Max = 0;
        int JOfMax = i + 1;
        for (int j = i + 1; j <= i + k && j < n; ++j)
        {
            if (j - i + nums[j] > Max)
            {
                JOfMax = j;
                Max = j - i + nums[j];
            }
        }
        i = JOfMax;
        ret++;
    }
    return ret;
}
int main()
{
    vector<int> v{2, 3, 1, 1, 4};
    jump(v);
	return 0;
}