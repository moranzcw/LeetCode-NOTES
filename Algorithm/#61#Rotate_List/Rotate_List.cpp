#include <iostream>
#include <vector>
#include <string>
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

int main(int argc, char const *argv[])
{
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = sol.rotateRight(head,10000);
    while(head != NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}