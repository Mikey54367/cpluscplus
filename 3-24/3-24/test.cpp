#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��������λ��
int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    if (nums[left] == target) return left;
    if (nums[left] < target) return left + 1;
    return left;
}
//x��ƽ����
int mySqrt(int x) {
    int left = 0;
    long long right = x;
    while (left < right)
    {
        long long mid = left + (right - left + 1) / 2;
        if ((long long)mid * mid > (long long)x) right = mid - 1;
        else left = mid;
    }
    return left;
}
//ɽ������ķⶥ����
int peakIndexInMountainArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;
        if (arr[mid] > arr[mid - 1]) left = mid;
        else right = mid - 1;
    }
    return left;
}
//Ѱ�ҷ�ֵ
int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (mid == 0)
        {
            //
            if (nums[mid] > nums[mid + 1]) return mid;
            left = mid + 1;
            continue;
        }
        if (mid == nums.size() - 1)
        {
            //
            if (nums[mid] > nums[mid - 1]) return mid;
            right = mid - 1;
            continue;
        }
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid] < nums[mid - 1]) right = mid - 1;
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
//Ѱ�����������е���Сֵ
int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= nums[0]) left = mid + 1;
        else right = mid;
    }
    if (nums[left] > nums[0]) return nums[0];
    return nums[left];
}
int main()
{
	return 0;
}