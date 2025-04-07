#include<iostream>
#include<vector>
using namespace std;
//颜色分类
void sortColors(vector<int>& nums) {
    int left = -1;
    int right = nums.size();
    int i = 0;
    while (i < right)
    {
        switch (nums[i])
        {
        case 0:
            swap(nums[i++], nums[++left]);
            break;
        case 1:
            ++i;
            break;
        case 2:
            swap(nums[i], nums[--right]);
        }
    }
}
//快速排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(nullptr));
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }
    void qsort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int randomNumber = rand() % (right - left + 1);
        int key = nums[left + randomNumber];
        int i = left;
        int tmpLeft = left - 1;
        int tmpRight = right + 1;
        while (i < tmpRight)
        {
            if (nums[i] < key)
                swap(nums[++tmpLeft], nums[i++]);
            else if (nums[i] == key)
                i++;
            else
                swap(nums[i], nums[--tmpRight]);
        }
        qsort(nums, left, tmpLeft);
        qsort(nums, tmpRight, right);
    }
};
//数组中第k个最大元素
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(nullptr));
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }
    int findKthLargest(vector<int>& nums, int left, int right, int k)
    {
        int n = nums.size();
        int tmpLeft = left - 1;
        int tmpRight = right + 1;
        int randomNum = rand() % (right - left + 1);
        int key = nums[left + randomNum];
        int i = left;
        while (i < tmpRight)
        {
            if (nums[i] < key)
                swap(nums[i++], nums[++tmpLeft]);
            else if (nums[i] == key)
                i++;
            else
                swap(nums[--tmpRight], nums[i]);
        }
        if (tmpLeft < (n - k) && (n - k) < tmpRight)
            return nums[n - k];
        if (tmpLeft >= (n - k))
            return findKthLargest(nums, left, tmpLeft, k);
        return findKthLargest(nums, tmpRight, right, k);

    }
};
//库存管理3
void inventoryManagement(vector<int>& stock, int l, int r, int cnt);
vector<int> inventoryManagement(vector<int>& stock, int cnt) {
    srand(time(nullptr));
    inventoryManagement(stock, 0, stock.size() - 1, cnt);
    return vector<int>(stock.begin(), stock.begin() + cnt);
}
void inventoryManagement(vector<int>& stock, int l, int r, int cnt)
{
    if (l >= r) return;
    int randomNum = rand() % (r - l + 1);
    int key = stock[l + randomNum];
    int left = l - 1;
    int right = r + 1;
    int i = l;
    while (i < right)
    {
        if (stock[i] < key)
            swap(stock[i++], stock[++left]);
        else if (stock[i] == key)
            ++i;
        else
            swap(stock[--right], stock[i]);
    }
    if (cnt <= left) inventoryManagement(stock, l, left, cnt);
    if ((right - 1) >= cnt && cnt > left) return;
    inventoryManagement(stock, right, r, cnt);
}
//归并排序
class Solution2 {
public:
    vector<int> tmp;
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l;
        int j = mid + 1;
        int k = l;
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }
        while (i <= mid)
        {
            tmp[k++] = nums[i++];
        }
        while (j <= r)
            tmp[k++] = nums[j++];
        for (int i = l; i <= r; ++i)
        {
            nums[i] = tmp[i];
        }
    }
};
int main()
{
    vector<int> v{ 5,2,3,1 };
    Solution2().sortArray(v);
	return 0;
}