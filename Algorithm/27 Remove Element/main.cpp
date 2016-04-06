#include <iostream>
using namespace std;

class Solution
{
public:
    int removeElement(int A[], int n, int elem) 
    {
        if(n == 0)
        {
            return 0;
        }
        int increase = 0;
        for(int i=0;i+increase<n;i++)
        {
            while(i+increase+1 < n && A[i+increase] == elem)
            {
                increase ++;
            }
            A[i] = A[i+increase];
        }
        if(A[n-increase-1] == elem)
        {
            increase++;
        }
        return n-increase;
    }
};

int main()
{
    int A[] = {1,2,3,4,5,6,7};
    Solution sol;
    cout << sol.removeElement(A,7,4) << endl;
    return 0;
}