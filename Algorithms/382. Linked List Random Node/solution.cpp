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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
    {
        this->head = head;
        this->len = 1;
        ListNode* temp = head;
        while(temp->next)
        {
            len++;
            temp = temp->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        int step = rand()%len;
        ListNode* temp = this->head;;
        for(int i=0;i<step;i++)
            temp = temp->next;
        return temp->val;
    }
    int len;
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */