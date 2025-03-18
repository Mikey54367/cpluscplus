#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//移动0
void moveZeroes(vector<int>& nums) {
    int zero = 0;
    int non_zero = 0;
    int n = nums.size();
    while (non_zero < n)
    {
        if (nums[non_zero] == 0)
        {
            non_zero++;
            continue;
        }
        while (zero < n && nums[zero] != 0)
        {
            zero++;
            if (zero > non_zero) non_zero = zero;
        }
        if (zero >= n) break;
        swap(nums[non_zero], nums[zero]);
    }
}
//复写0
void duplicateZeros(vector<int>& arr) {
    int n = arr.size();
    int cur = 0, dest = 0;
    while (dest < n - 1)
    {
        if (arr[cur] == 0) dest += 2;
        else dest++;
        cur++;
    }
    if (dest == n)
    {
        dest = n - 1;
        cur--;
    }
    else if (arr[cur] == 0)
    {
        dest = n - 1;
        arr[dest--] = arr[cur--];
    }
    while (dest >= 0)
    {
        if (arr[cur] == 0)
        {
            arr[dest--] = 0;
            arr[dest--] = 0;
            cur--;
        }
        else
        {
            arr[dest--] = arr[cur--];
        }
    }
}
//快乐数
int nextHappy(int n)
{
    int ret = 0;
    while (n)
    {
        ret += (n % 10) * (n % 10);
        n /= 10;
    }
    return ret;
}
bool isHappy(int n) {
    int slow = nextHappy(n);
    int fast = nextHappy(slow);
    while (fast != slow)
    {
        slow = nextHappy(slow);
        fast = nextHappy(nextHappy(fast));
    }
    if (fast == 1) return true;
    return false;
}
//盛最多水的容器
int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int ret = 0;
    while (left < right)
    {
        ret = max(ret, (right - left) * min(height[right], height[left]));
        if (height[right] > height[left]) left++;
        else right--;
    }
    return ret;
}
//有效三角形个数
int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = n - 1;
    int ret = 0;
    while (i > 1)
    {
        int left = 0, right = i - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] > nums[i])
            {
                ret += right - left;
                right--;
            }
            else left++;
        }
        --i;
    }
    return ret;
}
//查找总价格为目标值的两个商品
vector<int> twoSum(vector<int>& price, int target) {
    int left = 0, right = price.size() - 1;
    while (left < right)
    {
        if (price[left] + price[right] == target)
            return { price[left],price[right] };
        else if (price[left] + price[right] > target) right--;
        else left++;
    }
    return { 656,6544 };
}
//三数之和
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = n - 1;
    while (i > 1)
    {
        int left = 0, right = i - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] + nums[i] == 0)
            {
                ret.emplace_back(vector<int>{nums[left], nums[right], nums[i]});
                int tmp = nums[right];
                while (left < right && nums[right] == tmp) right--;
            }
            else if (nums[left] + nums[right] + nums[i] > 0)
            {
                int tmp = nums[right];
                while (left < right && nums[right] == tmp) right--;
            }
            else
            {
                int tmp = nums[left];
                while (left < right && nums[left] == tmp) left++;
            }
        }
        int tmp = nums[i];
        while (i > 1 && nums[i] == tmp) --i;

    }
    return ret;
}
int main()
{
    vector<int> v{ 0,0,0,7 };
    triangleNumber(v);
    return 0;

}