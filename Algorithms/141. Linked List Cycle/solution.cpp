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
    bool hasCycle(ListNode *head) 
    {
          ListNode *fast,*slow;
         if(head==NULL) 
            return false;
         slow=head;
         fast=head->next;
         while(fast!=NULL && fast->next!=NULL)
         {
             if(slow==fast) 
                return true;
             slow=slow->next;
             fast=fast->next->next;
         }
         return false;
    }
};