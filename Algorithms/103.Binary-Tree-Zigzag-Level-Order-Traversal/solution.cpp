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
   vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
   {
    vector<vector<int> >result;
    if (!root)
        return result;
    vector<int>vec;
    queue<TreeNode*>q1;
    TreeNode *temp = root;
    enum Dir{L,R};
    Dir dir = L;
    q1.push(root);
    
    while (!q1.empty())
    {
        queue<TreeNode *>q2;
        while (!q1.empty())
        {
            temp = q1.front();
            q1.pop();
            if (temp->left)
                q2.push(temp->left);
            if (temp->right)
                q2.push(temp->right);
            vec.push_back(temp->val);
        }
        if (dir == R)
        {
            reverse(vec.begin(), vec.end());
            dir = L;
        }
        else
            dir = R;
        result.push_back(vec);
        vec.clear();
        q1 = q2;
    }
    return result;
    }
};