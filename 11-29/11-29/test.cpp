#include<iostream>
#include<vector>
using namespace std; 
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
//汉诺塔问题
void dfs(vector<int>& A, vector<int>& B, vector<int>& C, int n)
{
    if (n == 1)
    {
        C.emplace_back(A.back());
        A.pop_back();
        return;
    }
    dfs(A, C, B, n - 1);
    C.emplace_back(A.back());
    A.pop_back();
    dfs(B, A, C, n - 1);
}
void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    int n = A.size();
    dfs(A, B, C, n);
}
//合并有序链表
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
//最长回文子序列
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
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
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}
//让字符串成为回文串的最小操作次数
int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (s[i] == s[j])
            {
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
//反转链表
ListNode* reverseList(ListNode* node1, ListNode* node2)
{
    if (node2 == nullptr)
        return node1;
    ListNode* next = node2->next;
    node2->next = node1;
    return reverseList(node2, next);
}
ListNode* reverseList(ListNode* head)
{
    return reverseList(nullptr, head);
}
//两两交换链表中的节点
ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* next = swapPairs(head->next->next);
    ListNode* tmp = head->next;
    head->next = next;
    tmp->next = head;
    return tmp;
}
//pow(x,n)
double myPow(double x, long long n)
{
    if (n == 0) return 1.0;
    if (x == 0.0) return x;
    if (n < 0) return myPow(1 / x, -n);
    double tmp = myPow(x, n / 2);
    if (n % 2 == 1) return tmp * tmp * x;
    return tmp * tmp;
}
double myPow(double x, int n) {
    return myPow(x, (long long)n);
}
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
   
};
//计算bool二叉树的值
bool evaluateTree(TreeNode* root) {
    if (root->left == nullptr && root->val == 0) return false;
    if (root->left == nullptr && root->val == 1) return true;
    if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
    return evaluateTree(root->left) && evaluateTree(root->right);
}
//从根节点到叶节点的数字之和
int sumNumbers(TreeNode* root, int val)
{
    val += root->val;
    if (root->left == nullptr && root->right == nullptr)
        return val;
    if (root->left == nullptr)
        return sumNumbers(root->right, val * 10);
    if (root->right == nullptr)
        return sumNumbers(root->left, val * 10);
    return sumNumbers(root->left, val * 10) + sumNumbers(root->right, val * 10);
}
int sumNumbers(TreeNode* root) {
    return sumNumbers(root, 0);
}
//二叉树剪
TreeNode* pruneTree(TreeNode* root)
{
    if (root == nullptr) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left == nullptr && root->right == nullptr && root->val == 0)
    {
        delete root; // 防⽌内泄漏
        root = nullptr;
    }
    return root;
}
//验证二叉搜索树
bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    if (!isValidBST(root->left)) return false;
    if (!isValidBST(root->right)) return false;
    if (root->left)
    {
        TreeNode* tmp = root->left;
        while (tmp->right) tmp = tmp->right;
        if (root->val <= tmp->val) return false;
    }
    if (root->right)
    {
        TreeNode* tmp = root->right;
        while (tmp->left) tmp = tmp->left;
        if (root->val >= tmp->val) return false;

    }
    return true;
}
int main()
{
    TreeNode* node = new TreeNode(0);
    pruneTree(node);
    return 0;
}