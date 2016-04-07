#include <iostream>
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
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL)
            return NULL;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            if(fast == slow)
                break;
             slow=slow->next;
             fast=fast->next->next;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;

        fast = head;
        slow = slow->next;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    ListNode *p = new ListNode(1);
    // p->next = new ListNode(2);
    // p->next->next = new ListNode(3);
    // p->next->next->next = new ListNode(4);
    // p->next->next->next->next = new ListNode(5);
    // p->next->next->next->next->next = new ListNode(6);
    // p->next->next->next->next->next->next = new ListNode(7);
    // p->next->next->next->next->next->next->next = new ListNode(8);
    // p->next->next->next->next->next->next->next->next = new ListNode(9);
    // p->next->next->next->next->next->next->next->next->next  = p->next->next->next;
    Solution sol;
    sol.detectCycle(p);
    return 0;
}