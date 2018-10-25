/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Compare
{
    bool operator()(const ListNode*p, const ListNode* q)const{
        return p->val > q->val;
    }
};

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int length = lists.size();
        ListNode *head = new ListNode(0);
        ListNode *pointer = head;
        priority_queue<ListNode*, vector<ListNode*>, Compare> listQueue;
        
        for (int i=0; i<length; i++)
        {
            if (lists[i])
                listQueue.push(lists[i]);
        }
        
        while (listQueue.size() > 0)
        {
            ListNode* tempNode = listQueue.top();
            listQueue.pop();
            pointer->next = tempNode;
            pointer = pointer->next;
            if (tempNode->next)
                listQueue.push(tempNode->next);
        }
        pointer->next = NULL;
        return head->next;
    }
};

    

