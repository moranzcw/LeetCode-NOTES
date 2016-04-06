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
    ListNode *swapPairs(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* result = head->next;

        for(ListNode *N1 = head, *N2 = head->next;
            N1 && N2;)
        {
            N1->next = N2->next;
            N2->next = N1;

            if(N1->next == NULL)
                break;

            N1 = N1->next;
            N2 = N2->next;

            if(N1->next == NULL)
                break;

            N2->next = N1->next;
            N2 = N2->next;
        }
        return result; 
    }
};

int main()
{
    
    ListNode *l1 = new ListNode(1);
    ListNode *temp = l1;
    for(int i=2;i<8;i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    Solution sol;
    
    ListNode *result = sol.swapPairs(l1);
    while(result != 0)
    {
        cout << result->val << " ";
        result = result->next;
    }
}