#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
//分割回文串2
int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                if (i == j || i == j - 1)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }
    vector<int> ret(n, INT_MAX);
    ret[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (dp[0][i]) ret[i] = 0;
        else
        {
            for (int j = 1; j <= i; ++j)
            {
                if (dp[j][i])
                    ret[i] = min(ret[i], ret[j - 1] + 1);
            }
        }
    }
    return ret[n - 1];
}
//最长回文子序列
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                if (i == j) dp[i][j] = 1;
                else if (i + 1 == j) dp[i][j] = 2;
                else dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}
//柠檬水找零
bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;
    for (int i = 0; i < bills.size(); ++i)
    {
        if (bills[i] == 5) five++;
        if (bills[i] == 10)
        {
            five--;
            if (five < 0) return false;
            ten++;
        }
        if (bills[i] == 20)
        {
            if (ten > 0)
            {
                ten--;
                five--;
                if (five < 0) return false;
            }
            else
            {
                five -= 3;
                if (five < 0) return false;
            }
        }
    }
    return true;
}
//很妙 建堆优化
int halveArray(vector<int>& nums) {
    priority_queue<double> heap;
    double sum = 0.0;
    for (auto& e : nums)
    {
        heap.push(e);
        sum += e;
    }
    int ret = 0;
    double target = sum / 2.0;
    while (target > 0.0)
    {
        double tmp = heap.top();
        tmp /= 2.0;
        target -= tmp;
        heap.pop();
        ret++;
        heap.push(tmp);
    }
    return ret;
}
//最大数
class Compare
{
public:
    bool operator()(string& s1, string& s2)
    {
        //最高位ASIII大者为大
        return s1 + s2 > s2 + s1;
    }
};
string largestNumber(vector<int>& nums)
{
    vector<string> vstr;
    for (auto& e : nums)
    {
        vstr.emplace_back(to_string(e));
    }
    sort(vstr.begin(), vstr.end(), Compare());
    string ret;
    for (auto& e : vstr)
    {
        ret += e;
    }
    if (ret[0] == '0') return "0";
    return ret;
}
int main()
{
    string s1{ "10" };
    string s2{ "2" };
    cout << stoi(s1 + s2) << endl;
    cout << stoi(s2 + s1) << endl;
	return 0;
}