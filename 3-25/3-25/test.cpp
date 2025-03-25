#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//点名
int takeAttendance(vector<int>& records) {
    int left = 0;
    int right = records.size() - 1;
    if (records[right] == right) return right + 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (records[mid] == mid) left = mid + 1;
        else right = mid;
    }
    return left;
}
//前缀和
int main1() {
    int n = 0, q = 0;
    cin >> n >> q;
    vector<long long> v(n + 1);
    int index = 1;
    while (n--)
    {
        int tmp = 0;
        cin >> tmp;
        v[index] = v[index - 1] + tmp;
        ++index;
    }
    while (q--)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << endl;
    }
    return 0;
}
//二维前缀和
int main2() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> arr(n, vector<long long>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i - 1][j - 1];
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}
//寻找数组中心下标
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> SumOfLeft(n);
    vector<int> SumOfRight(n);
    SumOfLeft[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        SumOfLeft[i] = SumOfLeft[i - 1] + nums[i - 1];
    }
    SumOfRight[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        SumOfRight[i] = SumOfRight[i + 1] + nums[i + 1];
    }
    for (int i = 0; i < n; ++i)
    {
        if (SumOfLeft[i] == SumOfRight[i]) return i;
    }
    return -1;
}
//除自身以外数组的乘积
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> productOfLeft(n);
    vector<int> productOfRight(n);
    productOfLeft[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        productOfLeft[i] = productOfLeft[i - 1] * nums[i - 1];
    }
    productOfRight[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        productOfRight[i] = productOfRight[i + 1] * nums[i + 1];
    }
    vector<int> ret(n);
    for (int i = 0; i < n; ++i)
    {
        ret[i] = productOfLeft[i] * productOfRight[i];
    }
    return ret;
}
int main()
{
    return 0;
}