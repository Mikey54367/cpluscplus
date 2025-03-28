#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
//两两交换链表中的节点
ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* Next = head->next;
    head->next = swapPairs(Next->next);
    Next->next = head;
    return Next;
}
//Pow(x,n)
double myPow(double x, int n)
{
    return pow(x, (long long)n);
}
double pow(double x, long long n)
{
    if (n < 0)
        return pow(1 / x, -n);
    if (n == 0) return 1.0;
    double tmp = pow(x, n / 2);
    if (n % 2 == 0)
        return tmp * tmp;
    else return tmp * tmp * x;
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
    if (root->val == 1) return true;
    if (root->val == 0) return false;
    if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
    else return evaluateTree(root->left) && evaluateTree(root->right);

}
int sumNumbers(TreeNode* root, int n);

//求根节点到叶节点数字之和
int sumNumbers(TreeNode* root) {
    return sumNumbers(root, 0);
}
int sumNumbers(TreeNode* root, int n)
{
    if (root->left == nullptr && root->right == nullptr) return n * 10 + root->val;
    if (root->left == nullptr) return sumNumbers(root->right, n * 10 + root->val);
    if (root->right == nullptr) return sumNumbers(root->left, n * 10 + root->val);
    else return sumNumbers(root->left, n * 10 + root->val) + sumNumbers(root->right, n * 10 + root->val);
}
//二叉树剪枝
TreeNode* pruneTree(TreeNode* root) {
    if (root == nullptr) return root;
    if (root->val == 1)
    {
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
    else
    {
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left || root->right) return root;
        else return nullptr;
    }
}
int main()
{
    myPow(1.0, -1);
	return 0;
}