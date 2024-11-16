#include<iostream>
#include<vector>
using namespace std;
//等差数列划分
int numberOfArithmeticSlices(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n);
	int sum = 0;
	for (int i = 2; i < n; i++)
	{
		dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i- 1] + 1 : 0;
		sum += dp[i];
	}
	return sum;

}
int main()
{
	return 0;
}