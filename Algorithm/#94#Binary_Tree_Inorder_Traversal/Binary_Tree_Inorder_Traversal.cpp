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
    vector<int> result;

    void dfs(TreeNode *root)
    {
        if(root == NULL)
            return;
        else
        {
            dfs(root->left);
            result.push_back(root->val);
            dfs(root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode *root) 
    {
        dfs(root);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> result = sol.inorderTraversal(NULL);
    for(int i=0;i<result.size();i++)
        cout << result[i] <<endl;
    return 0;
}