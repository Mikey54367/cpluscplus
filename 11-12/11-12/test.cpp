#include<iostream>
#include<vector>
using namespace std;
//颜色分类
void sortColors(vector<int>& nums) {
    int left = -1, i = 0, right = nums.size();
    while (i < right)
    {
        if (nums[i] == 0) swap(nums[++left], nums[i++]);
        if (nums[i] == 1) i++;
        if (nums[i] == 2) swap(nums[--right], nums[i]);
    }
}
//按摩师
int massage(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n);
    vector<int> g(n);
    f[0] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        f[i] = g[i - 1] + nums[i];
        g[i] = max(g[i - 1], f[i - 1]);
    }
    return max(f[n - 1], g[n - 1]);
}
//打家劫舍2
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n <= 3) return *max_element(nums.begin(), nums.end());
    vector<int> f1(n - 3);
    vector<int> g1(n - 3);
    f1[0] = nums[2];
    for (int i = 1; i < n - 3; ++i)
    {
        g1[i] = max(f1[i - 1], g1[i - 1]);
        f1[i] = g1[i - 1] + nums[i + 2];
    }
    vector<int> f2(n - 1);
    vector<int> g2(n - 1);
    f2[0] = nums[1];
    for (int i = 1; i < n - 1; ++i)
    {
        g2[i] = max(f2[i - 1], g2[i - 1]);
        f2[i] = g2[i - 1] + nums[i + 1];
    }
    return max(max(f1[n - 4], g1[n - 4]) + nums[0], max(g2[n - 2], f2[n - 2]));
}
//快排
int Rand(vector<int>& nums, int left, int right)
{
    srand((unsigned)time(NULL));
    return nums[left + rand() % (right - left + 1)];
}
void sortArray(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int key = Rand(nums, left, right);
    int left1 = left - 1, right1 = right + 1;
    for (int i = left; i < right1;)
    {
        if (nums[i] < key) swap(nums[++left1], nums[i++]);
        else if (nums[i] == key) i++;
        else swap(nums[i], nums[--right1]);
    }
    sortArray(nums, left, left1);
    sortArray(nums, right1, right);
}
vector<int> sortArray(vector<int>& nums) {
    int left = 0; int right = nums.size() - 1;
    sortArray(nums, left, right);
    return nums;
}
//数组中的第k个最大元素
int findKthLargest(vector<int>& nums, int left, int right, int k)
{
    int key = Rand(nums, left + 1, right - 1);
    int oldLeft = left, oldRight = right;
    for (int i = left + 1; i < right;)
    {
        if (nums[i] < key) swap(nums[i++], nums[++left]);
        else if (nums[i] == key) i++;
        else swap(nums[i], nums[--right]);
    }
    if (oldRight - right >= k) return findKthLargest(nums, right - 1, oldRight, k);
    if (oldRight - left - 1 >= k) return key;
    return findKthLargest(nums, oldLeft, left + 1, k - oldRight + left + 1);
}
int findKthLargest(vector<int>& nums, int k) {
    return findKthLargest(nums, -1, nums.size(), k);
}
int main()
{
    vector<int> v{ 3,2,3,1,2,4,5,5,6 }
    ;
    findKthLargest(v,4);
	return 0;
}