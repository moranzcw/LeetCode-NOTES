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
    ListNode *rotateRight(ListNode *head, int k) 
    {
        if(k == 0 || head == NULL)
            return head;

        int length = 0;
        for(ListNode *temp = head;temp != NULL;temp = temp->next)
            length++;

        ListNode* left = head, *right = head;
        k %= length;
        while(k--)
            right = right->next;
        

        while(right->next != NULL)
        {
            right = right->next;
            left = left->next;
        }

        right->next = head;
        ListNode *result = left->next;
        left->next = NULL;

        return result;
    }
};