#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
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
    void dfs(TreeNode *root)
    {
        if(root != NULL)
        {
            dfs(root->left);
            cout<<root->val<<" ";
            dfs(root->right);
        }
        else
            cout<<endl;
    }

    TreeNode* createTree(vector<int> &num,int left, int right)
    {
        if(left > right)
            return NULL;
        int mid = (left+right)/2;
        
        TreeNode *leftNode = createTree(num, left, mid - 1);
        TreeNode *rightNode = createTree(num, mid + 1, right);
        
        TreeNode *node = new TreeNode(num[mid]);
        
        node->left = leftNode;
        node->right = rightNode;

        return node;
    }

    TreeNode *sortedListToBST(ListNode *head) 
    {
        vector<int> num;
        while(head!=NULL)
        {
            num.push_back(head->val);
            head = head->next;
        }
        return createTree(num,0,num.size()-1);
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    TreeNode *result = sol.sortedListToBST(head);
    sol.dfs(result);
}