/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        if(root == NULL || root->left == NULL)
            return;
        TreeLinkNode *p = root;
        while(p != NULL)
        {
            p->left->next = p->right;
            if(p->next)
                p->right->next = p->next->left;
            p = p->next;
        }
        connect(root->left);
    }
};