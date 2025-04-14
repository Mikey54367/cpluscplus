#include<iostream>
#include<vector>
using namespace std;
//°Ú¶¯ÐòÁÐ Ì°ÐÄ
int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() == 1) return 1;
    vector<int> tmp;
    tmp.emplace_back(nums[0]);
    int prev = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == prev) continue;
        prev = nums[i];
        tmp.emplace_back(prev);
    }
    if (tmp.size() == 1) return 1;
    int ret = 2;
    for (int i = 1; i < tmp.size() - 1; ++i)
    {
        if ((tmp[i] - tmp[i - 1]) * (tmp[i + 1] - tmp[i]) < 0)
            ret++;
    }
    return ret;
}
int main()
{
    vector<int> v{ 3,3,3,2,5 };
    wiggleMaxLength(v);
    return 0;
}