/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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