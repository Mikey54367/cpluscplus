#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
//让字符串成为回文串的最小插入次数
int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                if (i == j || i + 1 == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    return dp[0][n - 1];
}
//最长公共子序列
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[m][n];
}
//不相交的线
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
//不同的子序列
int numDistinct(string s, string t) {
    int m = s.size();
    int n = t.size();
    if (n > m) return 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % (int)(1e9 + 7);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[m][n];
}
//翻转对
class Solution1{
    int ret = 0;
    vector<int> tmp;
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        tmp.resize(n);
        mergeSort(nums, 0, n - 1);
        return ret;
    }
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int cur1 = left;
        int cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= right)
        {
            if ((long long)nums[cur1] > (long long)2 * nums[cur2])
            {
                ret += right - cur2 + 1;
                cur1++;
            }
            else
                cur2++;
        }
        cur1 = left, cur2 = mid + 1;
        int i = left;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] >= nums[cur2])
                tmp[i++] = nums[cur1++];
            else
                tmp[i++] = nums[cur2++];
        }
        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];
        while (cur2 <= right)
            tmp[i++] = nums[cur2++];
        for (int i = left; i <= right; ++i)
        {
            nums[i] = tmp[i];
        }
    }
};
//字符串相乘
string multiply(string num1, string num2) {
    string ret;
    if (num1 == "0") return "0";
    if (num2 == "0") return "0";
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int m = num1.size();
    int n = num2.size();
    vector<int> tmp(m + n - 1);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int a = (num1[i] - '0') * (num2[j] - '0');
            tmp[i + j] += a;
        }
    }
    int next = 0;
    int i = 0;
    while (i < m + n - 1)
    {
        next += tmp[i++];
        ret += (next % 10 + '0');
        next /= 10;
    }
    if (next) ret += (next + '0');
    reverse(ret.begin(), ret.end());
    return ret;
}
//交易逆序对总数
vector<int> tmp;
int mergeSort(vector<int>& record, int left, int right);
int reversePairs(vector<int>& record) {
    int n = record.size();
    tmp.resize(n);
    return mergeSort(record, 0, n - 1);
}
int mergeSort(vector<int>& record, int left, int right)
{
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int ret = 0;
    ret += mergeSort(record, left, mid);
    ret += mergeSort(record, mid + 1, right);
    int cur1 = left, cur2 = mid + 1;
    int i = left;
    while (cur1 <= mid && cur2 <= right)
    {
        if (record[cur1] > record[cur2])
        {
            ret += right - cur2 + 1;
            tmp[i++] = record[cur1++];
        }
        else
        {
            tmp[i++] = record[cur2++];
        }
    }
    while (cur1 <= mid)
    {
        tmp[i++] = record[cur1++];
    }
    while (cur2 <= right)
    {
        tmp[i++] = record[cur2++];
    }
    for (int j = left; j <= right; ++j)
    {
        record[j] = tmp[j];
    }
    return ret;
}
//计算右侧小于当前元素个数
class Solution {
public:
    vector<int> ret;
    vector<pair<int, int>> tmp;
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ret.resize(n);
        tmp.resize(n);
        vector<pair<int, int>> numsAndIndex;
        for (int i = 0; i < n; ++i)
        {
            numsAndIndex.emplace_back(nums[i], i);
        }
        countSmaller(numsAndIndex, 0, n - 1);
        return ret;
    }
    void countSmaller(vector<pair<int, int>>& numsAndIndex, int left, int right)
    {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        countSmaller(numsAndIndex, left, mid);
        countSmaller(numsAndIndex, mid + 1, right);
        int cur1 = left, cur2 = mid + 1;
        int i = left;
        while (cur1 <= mid && cur2 <= right)
        {
            if (numsAndIndex[cur1].first > numsAndIndex[cur2].first)
            {
                ret[numsAndIndex[cur1].second] += right - cur2 + 1;
                tmp[i++] = numsAndIndex[cur1++];
            }
            else
            {
                tmp[i++] = numsAndIndex[cur2++];
            }
        }
        while (cur1 <= mid)
        {
            tmp[i++] = numsAndIndex[cur1++];
        }
        while (cur2 <= right)
            tmp[i++] = numsAndIndex[cur2++];
        for (int i = left; i <= right; ++i)
        {
            numsAndIndex[i] = move(tmp[i]);
        }
    }
};
//删除字符串中所有相邻重复元素
string removeDuplicates(string s) {
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); ++i)
    {
        if (st.empty())
        {
            st.push(s[i]);
            continue;
        }
        if (st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }
    string ret;
    while (!st.empty())
    {
        ret += st.top();
        st.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
bool backspaceCompare(string s, string t) {
    stack<char> st_s;
    stack<char> st_t;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '#')
        {
            if (!st_s.empty())
                st_s.pop();
        }
        else
        {
            st_s.push(s[i]);
        }
    }
    for (int i = 0; i < t.size(); ++i)
    {
        if (t[i] == '#')
        {
            if (!st_t.empty())
                st_t.pop();
        }
        else
        {
            st_t.push(t[i]);
        }
    }
    return st_s == st_t;
}
//通配符匹配
bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    if (m == 0 && n == 0) return true;
    if (m == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (p[i] != '*') return false;
        }
        return true;
    }
    if (n == 0)
    {
        for (int i = 0; i < m; ++i)
        {
            if (s[i] != '*') return false;
        }
        return true;
    }
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[0][0] = true;
    if (p[0] == '*')
    {
        //dp[0][1]=true;
        for (int i = 1; i <= n; ++i)
        {
            if (p[i - 1] == '*')
                dp[0][i] = true;
            else
                break;
        }
    }
    if (s[0] == '*')
    {
        //dp[1][0]=true;
        for (int i = 1; i <= m; ++i)
        {
            if (s[i - 1] == '*')
                dp[i][0] = true;
            else
                break;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[i - 1] == p[j - 1] || s[i - 1] == '?' || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            if (s[i - 1] == '*')
            {
                for (int k = 0; k <= j; ++k)
                {
                    if (dp[i - 1][k])
                    {
                        dp[i][j] = true;
                        break;
                    }
                    if (k == j)
                        dp[i][j] = false;
                }
            }
            if (p[j - 1] == '*')
            {
                for (int k = 0; k <= i; ++k)
                {
                    if (dp[k][j - 1])
                    {
                        dp[i][j] = true;
                        break;
                    }
                    if (k == i)
                        dp[i][j] = false;
                }
            }
        }
    }
    return dp[m][n];
}
int main()
{
    isMatch("adceb", "*a*b");
    backspaceCompare("xywrrmp", "xywrrmu#p");
    vector<int> v{ 0,2,1};
    Solution().countSmaller(v);
    longestCommonSubsequence("abc", "def");
	return 0;
}