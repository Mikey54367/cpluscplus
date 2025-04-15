#include<iostream>
#include<vector>
using namespace std;
//递增的三元子序列
bool increasingTriplet(vector<int>& nums) {
    int arr[3] = { 0 };
    int k = 0;
    arr[k++] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        int j = 0;
        for (j = 0; j < k; ++j)
        {
            if (nums[i] > arr[j]) continue;
            else break;
        }
        arr[j] = nums[i];
        if (j == k) k++;
        if (k == 3) return true;
    }
    return false;
}
int main()
{
	return 0;
}