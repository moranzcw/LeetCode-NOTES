#include <iostream>
#include <stack>
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
    bool dfs(TreeNode *left,TreeNode *right)
    {
        if(!left && !right) 
            return true;
        if((left && !right) || (!left && right) || (left->val!=right->val)) 
            return false;
        return dfs(left->left,right->right) && dfs(left->right,right->left);
    }

    bool isSymmetric(TreeNode *root) 
    {
        if(root==NULL || (!root->left && !root->right)) 
            return true;
        return dfs(root->left,root->right);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->left = new TreeNode(2);
    p->right->right = new TreeNode(3);

    Solution sol;
    cout<<sol.isSymmetric(p)<<endl;
    return 0;
}