#include<iostream>
#include<vector>
#include<string>
using namespace std;
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
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
//不相交的线
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <=m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
//二叉搜索树中第k小的元素
int kth = 0;
int kthVal = 0;
int kthSmallest(TreeNode* root, int k) {
    if (root == nullptr)
        return -1;
    int left = kthSmallest(root->left, k);
    if (left > -1)
        return left;
    kth++;
    kthVal = root->val;
    if (kth == k)
        return kthVal;
    return kthSmallest(root->right, k);
}
int main()
{
    //longestCommonSubsequence("abc", "def");
    vector<int> v1{ 1,2,4 };
    vector<int> v2{ 1,4,2 };
    maxUncrossedLines(v1, v2);
    return 0;
}