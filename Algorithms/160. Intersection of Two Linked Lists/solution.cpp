/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA == NULL || headB == NULL)
            return NULL;
        int countA = 0;
        ListNode *TA = headA;
        while(TA->next != NULL)
        {
            TA = TA->next;
            countA++;
        }

        int countB = 0;
        ListNode *TB = headB;
        while(TB->next != NULL)
        {
            TB = TB->next;
            countB++;
        }

        if(TA != TB)
            return NULL;

        int temp;
        if(countA > countB)
        {
            temp = countA - countB;
            while(temp--)
                headA = headA->next;
        }
        else
        {
            temp = countB - countA;
            while(temp--)
                headB = headB->next;
        }

        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};