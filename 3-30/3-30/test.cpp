#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
//二叉树的所有路径
vector<string> ret;
void dfs(TreeNode* root, string path);
vector<string> binaryTreePaths(TreeNode* root)
{
    string path;
    dfs(root, path);
    return ret;
}
void dfs(TreeNode* root, string path)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        path += to_string(root->val);
        ret.emplace_back(path);
    }
    else if (root->left == nullptr)
    {
        path += to_string(root->val);
        path += "->";
        dfs(root->right, path);
    }
    else if (root->right == nullptr)
    {
        path += to_string(root->val);
        path += "->";
        dfs(root->left, path);
    }
    else
    {
        path += to_string(root->val);
        path += "->";
        dfs(root->left, path);
        dfs(root->right, path);
    }
}
vector<vector<int>> ret1;
vector<int> path;
vector<bool> check = vector<bool>(10, false);//默认全是false
void dfs(vector<int>& nums);
vector<vector<int>> permute(vector<int>& nums)
{

    dfs(nums);
    return ret1;
}
//全排列
void dfs(vector<int>& nums)
{
    int i = 0;
    for (i = 0; i < nums.size(); ++i)
    {
        if (!check[i])
        {
            path.emplace_back(nums[i]);
            check[i] = true;
            if (path.size() == nums.size())
            {
                ret1.emplace_back(path);
            }
            else
                dfs(nums);
            check[i] = false;
            path.pop_back();
        }
    }
}
int main()
{
    vector<int> v{ 1,2,3 };
    permute(v);
	return 0;
}