#include <iostream>
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
    bool dfs(TreeNode *p, TreeNode *q)
    {
        if( p == NULL && q == NULL)
            return true;
        else if( p == NULL || q == NULL)
            return false;
        else
        {
            if( p->val == q->val)
                return dfs(p->left,q->left) && dfs(p->right,q->right);
        }
        return false;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) 
    {
        return dfs(p,q);
    }
};

int main(int argc, char const *argv[])
{

    TreeNode *p = new TreeNode(5);
    p->left = new TreeNode(1);
    p->right = new TreeNode(10);
    p->left->left = new TreeNode(2);
    p->left->right = new TreeNode(3);
    p->right->left = new TreeNode(8);
    p->right->right = new TreeNode(12);

    TreeNode *q = new TreeNode(5);
    q->left = new TreeNode(1);
    q->right = new TreeNode(10);
    q->left->left = new TreeNode(2);
    q->left->right = new TreeNode(3);
    q->right->left = new TreeNode(8);
    q->right->right = new TreeNode(12);

    Solution sol;
    cout<<sol.isSameTree(p,q)<<endl;
    return 0;
}