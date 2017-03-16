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
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode *first = head, *second = head;
        ListNode *temp = second;

        for(int i = 0; i < n; i++) 
        {
            first = first -> next;
        }

        while(first) 
        {
            first = first -> next;
            temp = second;
            second = second -> next;
        }
        
        if(second == head) 
        {
            head = head -> next;
        }
        else 
        {
            temp->next = second->next;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode *list = new ListNode(1);
    ListNode *temp = list;
    for(int i=2;i<8;i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    ListNode* result =  sol.removeNthFromEnd(list,2);
    while(result != NULL)
    {
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;
    return 0;
}