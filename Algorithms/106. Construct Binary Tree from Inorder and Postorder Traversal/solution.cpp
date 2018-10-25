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
    vector<int> inorder;
    vector<int> postorder;
    TreeNode *construct(vector<int>::iterator postIte, vector<int>::iterator leftIte, vector<int>::iterator rightIte)
    {
        TreeNode *node;
        if(leftIte == rightIte)
        {
            return NULL;
        }
        else
        {
            node = new TreeNode(*postIte);
            vector<int>::iterator midIte = find(leftIte,rightIte,*postIte);
            if(midIte != inorder.end())
            {
                node->left = construct(postIte-(rightIte-midIte),leftIte,midIte);
                node->right = construct(postIte-1,midIte+1,rightIte);
            }
        }
        return node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        this->inorder = inorder;
        this->postorder = postorder;
        return construct(postorder.end()-1,inorder.begin(),inorder.end());
    }
};