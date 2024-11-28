#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<queue>
using namespace std;
//基本计算器2
void calculate(stack<int>& st, int tmp, char ope)
{
    if (ope == '+')
    {
        st.push(tmp);
    }
    else if (ope == '-')
    {
        st.push(-tmp);
    }
    else if (ope == '*')
    {
        int n = st.top();
        tmp = tmp * n;
        st.pop();
        st.push(tmp);
    }
    else if (ope == '/')
    {
        int n = st.top();
        tmp = n / tmp;
        st.pop();
        st.push(tmp);
    }
}
int calculate(string s) {
    int tmp = 0;
    stack<int> st;
    char ope = '+';
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ') continue;
        if (s[i] == '+')
        {
            calculate(st, tmp, ope);
            ope = '+';
            tmp = 0;
        }
        else if (s[i] == '-')
        {
            calculate(st, tmp, ope);
            ope = '-';
            tmp = 0;
        }
        else if (s[i] == '*')
        {
            calculate(st, tmp, ope);
            ope = '*';
            tmp = 0;
        }
        else if (s[i] == '/')
        {
            calculate(st, tmp, ope);
            ope = '/';
            tmp = 0;
        }
        else
        {
            tmp = tmp * 10 + (s[i] - '0');
        }
    }
    calculate(st, tmp, ope);
    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    return sum;
}
//柠檬水找零

bool lemonadeChange(vector<int>& bills) {
    int arr[3] = { 0 };
    for (int i = 0; i < bills.size(); ++i)
    {
        if (bills[i] == 5) arr[0]++;
        else if (bills[i] == 10)
        {
            arr[1]++;
            arr[0]--;
            if (arr[0] < 0)
                return false;
        }
        else
        {
            if (arr[1] > 0)
            {
                arr[1]--;
                arr[0]--;
                if (arr[0] < 0)
                    return false;
            }
            else
            {
                arr[0] -= 3;
                if (arr[0] < 0)
                    return false;
            }
        }
    }
    return true;
}
//分割回文串4
bool checkPartitioning(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (i == j) dp[i][j] = true;
            else if (s[i] == s[j])
            {
                if (j == i + 1) dp[i][j] = true;
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            else dp[i][j] = false;
        }
    }
    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = i; j < n - 1; ++j)
        {
            if (dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1])
                return true;
        }
    }
    return false;
}
//分割回文串2
int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> message(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (i == j) message[i][j] = true;
            else if (s[i] == s[j])
            {
                if (j == i + 1) message[i][j] = true;
                else
                {
                    message[i][j] = message[i + 1][j - 1];
                }
            }
            else message[i][j] = false;
        }
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (message[0][i])
        {
            dp[i] = 0;
            continue;
        }
        for (int j = 1; j <= i; ++j)
        {
            if (message[j][i])
                dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    return dp[n - 1];
}
//将数组减半的最小操作数
int halveArray(vector<int>& nums) {
    priority_queue<double> heap;
    double sum1 = 0;
    for (auto num : nums)
    {
        sum1 += num;
        heap.push(num);
    }
    double sum2 = sum1;
    int count = 0;
    while (2 * sum2 > sum1)
    {
        double n = heap.top();
        heap.pop();
        n /= 2;
        sum2 -= n;
        heap.push(n);
        count++;
    }
    return count;
}
//验证栈序列
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int j = 0;
    for (int i = 0; i < popped.size(); ++i)
    {
        st.push(pushed[i]);
        while (!st.empty() && st.top() == popped[j])
        {
            st.pop();
            ++j;
        }
    }
    return st.empty();
}
int main()
{
    checkPartitioning("bcbddxy");
    return 0;
}