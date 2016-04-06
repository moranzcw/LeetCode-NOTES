#include <iostream>
using namespace std;

/// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution 
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        ListNode *resultList = new ListNode(0);
        ListNode *tempNode = resultList;

        int tempSum = 0;
        int tempVal1;
        int tempVal2;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL)
            {
                tempVal1 = l1->val;
                l1 = l1->next;
            }
            else
                tempVal1 = 0;

            if(l2 != NULL)
            {
                tempVal2 = l2->val;
                l2 = l2->next;
            }
            else
                tempVal2 = 0;

            tempSum = tempVal1 + tempVal2 + carry;
            tempNode->next = new ListNode(tempSum%10);
            carry = tempSum/10;
            tempNode = tempNode->next;
        }

        if(carry == 1)
            tempNode->next = new ListNode(1);

        return resultList->next;
    }
};

int main()
{
    ListNode *a = new ListNode(2);
    a->next = new ListNode(4);
    a->next->next =  new ListNode(3);
    ListNode *b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(4);

    Solution sol;
    ListNode *result = sol.addTwoNumbers(a,b);

    while(result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
}