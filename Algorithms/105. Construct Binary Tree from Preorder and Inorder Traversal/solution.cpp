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
    vector<int> preorder;
    vector<int> inorder;
    TreeNode *construct(vector<int>::iterator preIte, vector<int>::iterator leftIte, vector<int>::iterator rightIte)
    {
        TreeNode *node;
        if(leftIte == rightIte)
        {
            return NULL;
        }
        else
        {
            node = new TreeNode(*preIte);
            vector<int>::iterator midIte = find(leftIte,rightIte,*preIte);
            if(midIte != inorder.end())
            {
                node->left = construct(preIte+1,leftIte,midIte);
                node->right = construct(preIte+(midIte-leftIte)+1,midIte+1,rightIte);
            }
        }
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
    {
        this->preorder = preorder;
        this->inorder = inorder;
        return construct(preorder.begin(),inorder.begin(),inorder.end());
    }
};