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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode Result(0);
        ListNode *p = head;
        while (p) 
        {
            ListNode *q = p->next;
            p->next = Result.next;
            Result.next = p;
            p = q;
        }
        return Result.next;
    }
};