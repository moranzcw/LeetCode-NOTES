#include <iostream>
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
    ListNode *deleteDuplicates(ListNode *head) 
    {
        if(head == NULL)
            return head;

        ListNode *last = head;
        ListNode *temp = head->next;
        while(temp != NULL)
        {
            if(temp->val == last->val)
            {
                last->next = temp->next;
            }
            else
            {
                last = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *temp = l1;
    temp->next = new ListNode(1);
    temp = temp->next;
    temp->next = new ListNode(2);
    temp = temp->next;
    temp->next = new ListNode(3);
    temp = temp->next;
    temp->next = new ListNode(3);
    temp = temp->next;

    Solution sol;
    sol.deleteDuplicates(l1);
    while(l1!=NULL)
    {
        cout<<l1->val<<" ";
        l1 = l1->next;
    }
    return 0;
}