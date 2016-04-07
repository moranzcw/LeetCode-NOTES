#include <iostream>
#include <algorithm>
#include <vector>
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
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        if (head == NULL)
            return NULL;
            
        ListNode *q = NULL;
        ListNode *p = head;
        for(int i = 0; i < m - 1; i++)
        {
            q = p;
            p = p->next;
        }
        
        ListNode *end = p;
        ListNode *pPre = p;
        p = p->next;
        for(int i = m + 1; i <= n; i++)
        {
            ListNode *pNext = p->next;
            
            p->next = pPre;
            pPre = p;
            p = pNext;
        }
        
        end->next = p;
        if (q)
            q->next = pPre;
        else
            head = pPre;
        
        return head;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next = new ListNode(6);
    Solution sol;
    list = sol.reverseBetween(list,2,3);
    while(list != NULL)
    {
        cout<< list->val<<endl;
        list = list->next;
    }
    return 0;
}