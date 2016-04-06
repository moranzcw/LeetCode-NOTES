#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    TreeNode *pre;
    Solution()
    {
        pre = NULL;
    }
 
    void flatten(TreeNode *root)
    {
        if(root==NULL)
            return;
        TreeNode *lastright=root->right;//记录当前节点的右子树
        if(pre)
        {
            pre->left=NULL;
            pre->right=root;
        }
        pre=root;
        flatten(root->left);
        flatten(lastright);
    }
};

void dfs(TreeNode *node)
{
    if(!node) 
        return;
    else
    {
        cout<<node->val<<" ";
        dfs(node->left);
        dfs(node->right);
    }
}

int main()
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(p);
    dfs(p);
    return 0;
}