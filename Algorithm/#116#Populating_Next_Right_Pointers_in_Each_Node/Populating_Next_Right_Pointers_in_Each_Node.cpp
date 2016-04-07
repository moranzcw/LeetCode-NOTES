#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeLinkNode 
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
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

int main()
{
    TreeLinkNode *p = new TreeLinkNode(1);
    p->left = new TreeLinkNode(2);
    p->right = new TreeLinkNode(3);
    p->left->left = new TreeLinkNode(4);
    p->left->right = new TreeLinkNode(5);
    p->right->left = new TreeLinkNode(6);
    p->right->right = new TreeLinkNode(7);

    Solution sol;
    sol.connect(p);
    return 0;
}