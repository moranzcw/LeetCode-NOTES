#include <iostream>
#include <vector>
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
    vector<TreeNode *> generateTrees(int n) 
    {
       return createTree(1,n);
    }
    
    vector<TreeNode *> createTree(int start, int end)
    {
        vector<TreeNode *> results;
        if(start>end)
        {
            results.push_back(NULL);
            return results;
        }
        
        for(int k=start;k<=end;k++)
        {
            vector<TreeNode *> left = createTree(start,k-1);
            vector<TreeNode *> right = createTree(k+1,end);
            for(int i=0;i<left.size();i++)
            {
                for(int j=0;j<right.size();j++)
                {
                    TreeNode * root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    results.push_back(root);
                }
            }
        }
        return results;
    }

    void dfs(TreeNode *root)
    {
        if(root == NULL)
            return;
        else
        {
            cout<< root->val << " ";
            dfs(root->left);     
            dfs(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<TreeNode *> result = sol.generateTrees(3);
    for(int i=0;i<result.size();i++)
    {
        sol.dfs(result[i]);
        cout<<endl;
    }
    return 0;
}