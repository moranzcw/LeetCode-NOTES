#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        int increase = 0;
        for(int i=0;i+increase<n;i++)
        {
            A[i]=A[i+increase];
            while(i+increase+1<n && A[i+increase+1]==A[i])
            {
                increase++;
            }
        }
        return n-increase;
    }
};

int main()
{
    int A[] = {1,2,2,2,5,6,7};
    Solution sol;
    cout << sol.removeDuplicates(A,7) << endl;
    return 0;
}