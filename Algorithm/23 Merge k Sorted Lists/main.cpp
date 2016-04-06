#include <iostream>
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        ListNode *temp = new ListNode(0);
        ListNode *result = temp;
        while( l1 && l2 )
        {
            if( l1->val < l2->val )
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1) 
            temp->next = l1;
        if(l2)
            temp->next = l2;
        return result->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if(lists.empty())
            return NULL;
        int curSize = lists.size();
        while(curSize > 1) 
        {
            int halfSize = (1 + curSize) / 2;

            for(int i = 0 ; i < halfSize && i + halfSize < curSize; ++i) 
            {
                ListNode *first = lists[i];
                ListNode *second = lists[i + halfSize];
                ListNode *result = mergeTwoLists(first,second);
                lists[i] = result;
            }
            curSize = halfSize;
        }
        return lists[0];
    }
};

int main()
{
    Solution sol;

    ListNode *l1 = new ListNode(1);
    ListNode *temp = l1;
    for(int i=2;i<8;i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    ListNode *l2 = new ListNode(1);
    temp = l2;
    for(int i=2;i<4;i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    ListNode *l3 = new ListNode(1);
    temp = l3;
    for(int i=2;i<9;i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    vector<ListNode *> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    ListNode *result = sol.mergeKLists(lists);
    
    while(result != 0)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}