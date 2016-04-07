#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int> > levelOrder(TreeNode *root) 
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
        return result;
    }
};

int main()
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);
    p->right->left = new TreeNode(6);
    p->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int> > result = sol.levelOrder(p);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}