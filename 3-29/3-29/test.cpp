#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//z字形变换
string convert(string s, int numRows) {
    int n = s.size();
    if (numRows == 1) return s;
    if (numRows == 2)
    {
        string ret;
        for (int j = 0; j < numRows; ++j)
        {
            int i = j;
            while (i < n)
            {
                ret.push_back(s[i]);
                i += 2;
            }
        }
        return ret;
    }
    int tmp0 = 2 * (numRows - 1);
    int tmp1 = tmp0;
    string ret;
    for (int j = 0; j < numRows; ++j)
    {
        int i = j;
        if (i < n)
            ret.push_back(s[i]);
        if (tmp0 == tmp1)
        {
            while (i + tmp0 < n)
            {
                ret.push_back(s[i + tmp0]);
                i += tmp0;
            }
            tmp0 -= 2;
        }
        else if (tmp0 != 0)
        {
            int index = i + tmp0;
            while (index < n)
            {
                ret.push_back(s[index]);
                if (index + (tmp1 - tmp0) < n)
                    ret.push_back(s[index + (tmp1 - tmp0)]);
                index += tmp1;
            }
            tmp0 -= 2;
        }
        else
        {
            while (i + tmp1 < n)
            {
                ret.push_back(s[i + tmp1]);
                i += tmp1;
            }
        }
    }
    return ret;
}
//外观数列
string countAndSay(int n) {
    if (n == 1) return "1";
    string ret{ "11" };
    while (n > 2)
    {
        string tmp = ret;
        string tmp1;
        char prev = tmp[0];
        int cnt = 1;
        for (int i = 1; i < tmp.size(); ++i)
        {
            char c = tmp[i];
            if (c == prev)
            {
                cnt++;
            }
            else
            {
                tmp1.push_back(cnt + '0');
                tmp1.push_back(prev);
                prev = c;
                cnt = 1;
            }
        }
        tmp1.push_back(cnt + '0');
        tmp1.push_back(prev);
        ret = move(tmp1);
        --n;
    }
    return ret;
}
//数青蛙
int minNumberOfFrogs(string croakOfFrogs) {
    int c = 0, r = 0, o = 0, a = 0, k = 0;
    for (int i = 0; i < croakOfFrogs.size(); ++i)
    {
        if (croakOfFrogs[i] == 'c')
        {
            if (k > 0) k--;
            c++;
        }
        if (croakOfFrogs[i] == 'r')
        {
            if (c <= 0) return -1;
            c--;
            r++;
        }
        if (croakOfFrogs[i] == 'o')
        {
            if (r <= 0) return -1;
            r--;
            o++;
        }
        if (croakOfFrogs[i] == 'a')
        {
            if (o <= 0) return -1;
            o--;
            a++;
        }
        if (croakOfFrogs[i] == 'k')
        {
            if (a <= 0) return -1;
            a--;
            k++;
        }
    }
    if (c || r || o || a) return -1;
    return k;
}
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
   
};
int findMax(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
        return root->val;
    if (root->left == nullptr)
    {
        int n = findMax(root->right);
        return max(n, root->val);
    }
    if (root->right == nullptr)
    {
        int n = findMax(root->left);
        return max(root->val, n);
    }
    else
    {
        return max(max(findMax(root->left), findMax(root->right)), root->val);
    }
}
//验证搜索二叉树（中序遍历）
class c1
{
    long long prev = (long long)INT_MIN - 10000;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isValidBST(root->left)) return false;
        if (root->val <= prev) return false;
        prev = root->val;
        return isValidBST(root->right);
    }
};
//二叉搜索树中第k小的元素
class Solution {
public:
    int cnt = 1;
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return -1;
        int n = kthSmallest(root->left, k);
        if (n != -1) return n;
        if (k == cnt) return root->val;
        cnt++;
        return kthSmallest(root->right, k);
    }
};
int main()
{
    TreeNode node1(2);
    TreeNode node2(1);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    countAndSay(4);
    convert("ABC", 2);
	return 0;
}