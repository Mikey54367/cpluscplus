#include<iostream>
#include<vector>
#include <numeric>
#include<algorithm>
using namespace std;
//跳跃游戏
bool canJump(vector<int>& nums) {
    int cur = 0;
    int dest = nums.size() - 1;
    nums[dest] = 11111;
    while (cur < dest)
    {
        int gap = nums[cur];
        if (gap == 0) return false;
        int Max = 0;
        int iOfMax = 0;
        for (int i = cur + 1; i <= cur + gap && i <= dest; ++i)
        {
            if (i - cur + nums[i] > Max)
            {
                Max = i - cur + nums[i];
                iOfMax = i;
            }
        }
        cur = iOfMax;
    }
    return true;
}
//加油站
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
        return -1;
    int n = gas.size();
    vector<int> v(n);
    int k = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        v[i] = k + gas[i] - cost[i];
        k = v[i];
    }
    int ret = -1;
    int Max = -1;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] > Max)
        {
            ret = i;
            Max = v[i];
        }
    }
    return ret;
}
//单调递增的数字
int monotoneIncreasingDigits(int n) {
    if (n == 0)
        return 0;
    vector<int> v;
    while (n)
    {
        v.emplace_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    int ret = 0;
    int flag = 1;
    while (true)
    {
        for (int i = 0; i < v.size() - 1;)
        {
            if (v[i] <= v[i + 1])
            {
                ++i;
            }
            else
            {
                flag = 0;
                v[i] = v[i] - 1;
                for (int j = i + 1; j < v.size(); ++j)
                {
                    v[j] = 9;
                }
            }
        }
        if (flag == 0)
        {
            flag = 1;
            continue;
        }
        else
            break;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        ret = ret * 10 + v[i];
    }
    return ret;
}
int main()
{
    vector<int> v1{ 1,2,3,4,5 };
    vector<int> v2{ 3,4,5,1,2 };
    //canJump(v);
    canCompleteCircuit(v1, v2);
	return 0;
}