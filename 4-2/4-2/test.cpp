#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
//最长回文字串
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    //i表示起始位置
    //j表示末位置
    int len = 0;
    int left = 0;
    int right = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                if (i == j || i + 1 == j)
                    dp[i][j] = true;
                else if (dp[i + 1][j - 1])
                    dp[i][j] = true;
            }
            if (dp[i][j] && (j - i + 1) > len)
            {
                len = j - i + 1;
                left = i;
            }
        }
    }
    return s.substr(left, len);
}
//分割回文串4
bool checkPartitioning(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                if (i == j || i + 1 == j)
                    dp[i][j] = true;
                else if (dp[i + 1][j - 1])
                    dp[i][j] = true;
            }
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
//N皇后
class Solution {
    bool check[9];
    unordered_set<int> hashOfSum;
    unordered_set<int> hashOfDif;
    vector<vector<string>> ret;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n, string(n, '.'));
        dfs(n, 0, path);
        return ret;
    }
    void dfs(int n, int index, vector<string>& path)
    {
        if (index == n)
        {
            ret.emplace_back(path);
            return;
        }
        for (int j = 0; j < n; ++j)
        {
            if (!check[j] && !hashOfSum.count(index + j) && !hashOfDif.count(index - j))
            {
                check[j] = true;
                hashOfDif.insert(index - j);
                hashOfSum.insert(index + j);
                path[index][j] = 'Q';
                dfs(n, index + 1, path);
                path[index][j] = '.';
                check[j] = false;
                hashOfDif.erase(index - j);
                hashOfSum.erase(index + j);
            }
        }
    }
};
//有效的数独
bool isValidSudoku(vector<vector<char>>& board) {
    //先一行一行查
    for (int i = 0; i < 9; ++i)
    {
        bool check[10] = { false };
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.') continue;
            if (!check[board[i][j] - '0'])
                check[board[i][j] - '0'] = true;
            else
                return false;
        }
    }
    //再一列一列查
    for (int i = 0; i < 9; ++i)
    {
        bool check[10] = { false };
        for (int j = 0; j < 9; ++j)
        {
            if (board[j][i] == '.') continue;
            if (!check[board[j][i] - '0'])
                check[board[j][i] - '0'] = true;
            else
                return false;
        }
    }
    int index = 0;
    while (index < 8)
    {
        bool check[10] = { false };
        bool check1[10] = { false };
        bool check2[10] = { false };
        for (int i = index; i < index + 3; i++)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == '.') continue;
                if (!check[board[i][j] - '0'])
                    check[board[i][j] - '0'] = true;
                else
                    return false;
            }
            for (int j = 3; j < 6; ++j)
            {
                if (board[i][j] == '.') continue;
                if (!check1[board[i][j] - '0'])
                    check1[board[i][j] - '0'] = true;
                else
                    return false;
            }
            for (int j = 6; j < 9; ++j)
            {
                if (board[i][j] == '.') continue;
                if (!check2[board[i][j] - '0'])
                    check2[board[i][j] - '0'] = true;
                else
                    return false;
            }
        }

        index += 3;
    }
    return true;
    //最后一个一个九宫格查

}
int main()
{
    std::vector<std::vector<char>> sudokuBoard = {
        {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
        {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
        {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
        {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
        {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
        {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
        {'.', '.', '4', '.', '.', '.', '.', '.', '.'}
    };
    isValidSudoku(sudokuBoard);
	return 0;
}