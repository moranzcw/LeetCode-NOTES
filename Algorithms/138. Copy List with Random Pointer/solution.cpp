/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution 
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(head == NULL)
            return NULL;

        map<RandomListNode*, RandomListNode*> mp;
        RandomListNode *newList = new RandomListNode(head->label);
        newList->random = head->random;
        mp.insert(map<RandomListNode*, RandomListNode*>::value_type(head,newList));

        for(RandomListNode *node = head, *temp = newList; node->next != NULL; node = node->next,temp = temp->next)
        {
            temp->next = new RandomListNode(node->next->label);
            temp->next->random = node->next->random;
            mp.insert(map<RandomListNode*, RandomListNode*>::value_type(node->next,temp->next));
        }

        for(RandomListNode *node = newList;node != NULL;node = node->next)
        {
            if(node->random != NULL)
                node->random = mp.find(node->random)->second;
        }

        return newList;
    }
};