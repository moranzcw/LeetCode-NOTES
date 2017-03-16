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
    TreeNode *node1;
    TreeNode *node2;
    TreeNode *pre;

    void recoverTree(TreeNode *root) 
    {
        node1 = node2 = pre = NULL;
        findout(root);
        swap(node1->val, node2->val);
        return;
    }
    
    void findout(TreeNode *root)
    {
        if (root->left != NULL) 
            findout(root->left);
        
        if (pre != NULL)
        {
            if (pre->val > root->val)
            {
                if (node1 == NULL) 
                    node1 = pre, node2 = root;
                else 
                    node2 = root;
            }
        }
        
        pre = root;
        if (root->right != NULL) 
            findout(root->right);
    }
};

void dfs(TreeNode *root)
{
    if(root == NULL)
        return;
    else
    {
        dfs(root->left);
        cout<<root->val;
        dfs(root->right);
    }
}

int main(int argc, char const *argv[])
{
    TreeNode *tree = new TreeNode(5);
    tree->left = new TreeNode(1);
    tree->right = new TreeNode(10);
    tree->left->left = new TreeNode(2);
    tree->left->right = new TreeNode(3);
    tree->right->left = new TreeNode(8);
    tree->right->right = new TreeNode(12);
    Solution sol;
    sol.recoverTree(tree);
    dfs(tree);
    return 0;
}