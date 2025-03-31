#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//子集
vector<vector<int>> ret;
vector<int> path;
void dfs(vector<int>& nums, int i);
vector<vector<int>> subsets(vector<int>& nums)
{
    dfs(nums, 0);
    return ret;
}
void dfs(vector<int>& nums, int i)
{
    if (i == nums.size())
    {
        ret.emplace_back(path);
        return;
    }
    //不选
    dfs(nums, i + 1);
    //选
    path.emplace_back(nums[i]);
    dfs(nums, i + 1);
    path.pop_back();
}
//找出所有子集的异或总和
class Solution1 {
    vector<vector<int>> allSubset;
    vector<int> path;
public:
    int subsetXORSum(vector<int>& nums)
    {
        dfs(nums, 0);
        int ret = 0;
        for (auto& e : allSubset)
        {
            int tmp = 0;
            for (int i = 0; i < e.size(); ++i)
            {
                tmp ^= e[i];
            }
            ret += tmp;
        }
        return ret;
    }
    void dfs(vector<int>& nums, int pos)
    {
        allSubset.emplace_back(path);
        for (int i = pos; i < nums.size(); ++i)
        {
            path.emplace_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};
//全排列2 这一题很妙，一样的就不用选了
class Solution2 {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[9];
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int n)
    {
        if (n == nums.size())
        {
            ret.emplace_back(path);
            return;
        }
        int prev = 11;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == prev) continue;
            else if (!check[i])
            {
                prev = nums[i];
                path.emplace_back(nums[i]);
                check[i] = true;
                dfs(nums, n + 1);
                path.pop_back();
                check[i] = false;
            }
        }
    }
};
//电话号码的字母组合
class Solution {
public:
    vector<string> ret;
    string path;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return ret;
        dfs(digits, 0);
        return ret;
    }
    void dfs(string digits, int index)
    {
        if (index == digits.size())
        {
            ret.emplace_back(path);
            return;
        }
        if (digits[index] == '2')
        {
            path.push_back('a');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('b');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('c');
            dfs(digits, index + 1);
            path.pop_back();
        }
        else if (digits[index] == '3')
        {
            path.push_back('d');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('e');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('f');
            dfs(digits, index + 1);
            path.pop_back();
        }
        else if (digits[index] == '4')
        {
            path.push_back('g');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('h');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('i');
            dfs(digits, index + 1);
            path.pop_back();
        }
        else if (digits[index] == '5')
        {
            path.push_back('j');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('k');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('l');
            dfs(digits, index + 1);
            path.pop_back();
        }
        else if (digits[index] == '6')
        {
            path.push_back('m');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('n');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('o');
            dfs(digits, index + 1);
            path.pop_back();
        }
        else if (digits[index] == '7')
        {
            path.push_back('p');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('q');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('r');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('s');
            dfs(digits, index + 1);
            path.pop_back();
        }
        else if (digits[index] == '8')
        {
            path.push_back('t');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('u');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('v');
            dfs(digits, index + 1);
            path.pop_back();
        }
        else if (digits[index] == '9')
        {
            path.push_back('w');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('x');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('y');
            dfs(digits, index + 1);
            path.pop_back();
            path.push_back('z');
            dfs(digits, index + 1);
            path.pop_back();
        }
    }
};
//括号生成
vector<string> ret1;
string path1;
void dfs(int n1, int n2);
vector<string> generateParenthesis(int n) {
    dfs(n, n);
    return ret1;
}
void dfs(int n1, int n2)
{
    if (n1 == 0 && n2 == 0)
    {
        ret.emplace_back(path);
        return;
    }
    if (n2 > n1)
    {
        path1 += ')';
        dfs(n1, n2 - 1);
        path.pop_back();
    }
    if (n1 > 0)
    {
        path1 += '(';
        dfs(n1 - 1, n2);
        path.pop_back();
    }
}
//组合
class Solution4{
    vector<vector<int>> ret;
    vector<int> path;
    bool check[21];
public:
    vector<vector<int>> combine(int n, int k)
    {
        dfs(n, k, 1);
        return ret;
    }
    void dfs(int n, int k, int index)
    {
        if (k == 0)
        {
            ret.emplace_back(path);
            return;
        }
        for (int i = index; i <= n; ++i)
        {
            if (!check[i])
            {
                check[i] = true;
                path.emplace_back(i);
                dfs(n, k - 1, i + 1);
                path.pop_back();
                check[i] = false;
            }
        }
    }
};
//目标和
class Solution5 {
    int ret = 0;
    int path = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        dfs(nums, target, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int target, int index)
    {
        if (index == nums.size())
        {
            if (path == target)
                ret++;
            return;
        }
        path += nums[index];
        dfs(nums, target, index + 1);
        path -= nums[index];
        path -= nums[index];
        dfs(nums, target, index + 1);
        path += nums[index];
    }
};
int main()
{
    Solution s;
    s.letterCombinations("23");
	return 0;
}