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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL || p == NULL || q == NULL)
            return NULL;
        if(p->val > q->val)
            swap(p,q);
        if( root->val >= p->val && root->val <= q->val )
            return root;
        else if( root->val < p->val && root->val < q->val )
            return lowestCommonAncestor(root->right,p,q);
        else if( root->val > p->val && root->val > q->val )
            return lowestCommonAncestor(root->left,p,q);
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->left->left = new TreeNode(2);
    tree->left->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right = new TreeNode(6);
    Solution sol;
    cout<<sol.lowestCommonAncestor(tree,tree->left->left->left,tree->left->right)->val<<endl;
    return 0;
}