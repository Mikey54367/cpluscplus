#include<iostream>
#include<vector>
using namespace std;
//位1的个数
int hammingWeight(int n) {
    int ret = 0;
    for (int i = 0; i < 32; ++i)
    {
        if ((n >> i) & 1) ret++;
    }
    return ret;
}
//比特位计数
vector<int> countBits(int n) {
    vector<int> ret(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        ret[i] = hammingWeight(i);
    }
    return ret;
}
//汉明距离
int hammingDistance(int x, int y) {
    int ret = 0;
    for (int i = 0; i < 32; ++i)
    {
        if (((x >> i) & 1) != ((y >> i) & 1))
            ret++;
    }
    return ret;
}
//只出现一次的数字1
int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i)
        ret ^= nums[i];
    return ret;
}
//只出现一次的数字3
vector<int> singleNumber3(vector<int>& nums) {
    int x = 0;
    for (int i = 0; i < nums.size(); ++i)
        x ^= nums[i];
    int i = 0;
    for (; i < 32; ++i)
        if (((x >> i) & 1)) break;
    int ret1 = 0;
    int ret2 = 0;
    for (int j = 0; j < nums.size(); ++j)
    {
        if ((nums[j] >> i) & 1) ret1 ^= nums[j];
        else ret2 ^= nums[j];
    }
    return{ ret1,ret2 };
}
//判断字符是否唯一
bool isUnique(string astr) {
    if (astr.size() > 26)
        return false;
    int x = 0;
    for (int i = 0; i < astr.size(); ++i)
    {
        if ((x >> (astr[i] - 'a')) & 1) return false;
        x |= 1 << (astr[i] - 'a');
    }
    return true;
}
//丢失的数字
int missingNumber(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i)
        ret ^= nums[i] ^ i;
    ret ^= nums.size();
    return ret;
}
//丢失的数字2
vector<int> missingTwo(vector<int>& nums) {
    int x = 0;
    for (int i = 0; i < nums.size(); ++i) x ^= nums[i];
    for (int i = 1; i <= nums.size() + 1; ++i) x ^= i;
    int i = 0;
    for (; i < 32; ++i)
        if ((x >> i) & 1) break;
    int ret1 = 0, ret2 = 0;
    for (int j = 0; j < nums.size(); ++j)
    {
        if (nums[j] & (1 << i)) ret1 ^= nums[j];
        else ret2 ^= nums[j];
    }
    for (int j = 1; j <= nums.size() + 1; ++j)
    {
        if (j & (1 << i)) ret1 ^= j;
        else ret2 ^= j;
    }
    return { ret1,ret2 };
}
//两整数之和
int getSum(int a, int b) {
    int ret = 0;

    while (b)
    {
        int x = a ^ b;
        int y = (a & b) << 1;
        a = x;
        b = y;
    }
    return a;
}
//只出现一次的数字2
int singleNumber2(vector<int>& nums) {
    int ret = 0;
    int x = 0;
    for (int i = 0; i < 32; ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if ((nums[j] >> i) & 1) x++;
        }
        x %= 3;
        ret |= (x << i);
        x = 0;
    }
    return ret;
}
#include<algorithm>
//珠宝的最大价值
int jewelleryValue(vector<vector<int>>& frame) {
    int m = frame.size();
    int n = frame[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
        }
    }
    return dp[m][n];
}
//下降路径最小和
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 101;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = *min_element(&dp[i - 1][j - 1], &(dp[i - 1][min(j + 1, n)]) + 1) + matrix[i - 1][j - 1];
    return *min_element(&dp[n][1], &(dp[n][n]) + 1);
}
int main()
{
    vector<int> vv{-1,2,-3,4,5,6,-100};
    int x = *(min(&vv[0], &vv[6] + 1));
    cout << x << endl;
    vector<vector<int>> v{ {100,100}, {100,100} };
    minFallingPathSum(v);
	return 0;
}