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
    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
        vector<vector<int> > result;
        vector<int> temp;
        queue<TreeNode *> q;

        int count = 1;
        int nextCount = 0;

        if(root == NULL)
            return result;

        q.push(root);
        while(!q.empty())
        {
            temp.push_back(q.front()->val);
            count--;

            if(q.front()->left)
            {
                q.push(q.front()->left);
                nextCount++;
            }
            if(q.front()->right)
            {
                q.push(q.front()->right);
                nextCount++;
            }
            q.pop();

            if(count == 0)
            {
                result.push_back(temp);
                temp.resize(0);
                count = nextCount;
                nextCount = 0;
            }
        }

        for(int i=0,j=result.size()-1;i<j;i++,j--)
            swap(result[i],result[j]);
        return result;
    }
};