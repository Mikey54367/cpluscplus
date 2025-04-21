#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//”≈ ∆œ¥≈∆
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    vector<int> index(n);
    for (int i = 0; i < n; ++i)
    {
        index[i] = i;
    }
    sort(index.begin(), index.end(), [&nums2](int i, int j) {
        return nums2[i] < nums2[j];
        });
    sort(nums1.begin(), nums1.end());
    vector<int> ret(n, -1);
    vector<int> tmp;
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (nums1[i] > nums2[index[j]])
        {
            ret[index[j]] = nums1[i];
            j++;
        }
        else
        {
            tmp.emplace_back(nums1[i]);
        }
    }
    j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ret[i] == -1)
            ret[i] = tmp[j++];
    }
    return ret;
}
int main()
{

    return 0;
}