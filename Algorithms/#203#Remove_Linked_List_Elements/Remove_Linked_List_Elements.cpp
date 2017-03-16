#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *temp = NULL;
        while(head != NULL && head->val == val)
        {
            temp = head;
            head = head->next;
            delete(temp);
        }

        if(head == NULL)
            return NULL;

        ListNode *cur = head->next ,*last = head;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                temp = cur;
                last->next = cur->next;
                cur = cur->next;
                delete temp;
            }
            else
            {
                last = cur;
                cur = cur->next;        
            }
        }
        return head;
    }
};

int main()
{
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(2);
    p->next->next->next = new ListNode(1);

    Solution sol;
    p = sol.removeElements(p,2);

    while(p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    return 0;
}