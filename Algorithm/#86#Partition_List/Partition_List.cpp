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
    ListNode *partition(ListNode *head, int x) 
    {
        ListNode *list1 = new ListNode(0);
        ListNode *first = list1;
        ListNode *list2 = new ListNode(0);
        ListNode *second = list2;
        while(head != NULL)
        {
            if(head->val < x)
            {
                first->next = head;
                first = first->next;
            }
            else
            {
                second->next = head;
                second = second->next;
            }
            head = head->next;
        }
        first->next = list2->next;
        second->next = NULL;
        return list1->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(4);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(2);
    list->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next = new ListNode(2);
    Solution sol;
    list = sol.partition(list,3);
    while(list != NULL)
    {
        cout<< list->val<<endl;
        list = list->next;
    }
    return 0;
}