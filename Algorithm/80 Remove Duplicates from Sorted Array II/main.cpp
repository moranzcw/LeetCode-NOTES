#include <iostream>
using namespace std;

class Solution 
{
public:
    int removeDuplicates(int A[], int n) 
    {
        if(n <= 0)
            return 0;
        int firstIndex = 0, secondIndex = 0;
        int curVal = A[0] , curCount = 0;
        for(int i=0;i<n;i++)
        {
            if(A[i] == curVal)
            {
                if(curCount<2)
                {
                    A[firstIndex] = curVal;
                    firstIndex++;
                }
                curCount++;
            }
            else
            {
                curVal = A[i];
                curCount = 1;
                A[firstIndex] = curVal;
                firstIndex++;
            }
        }
        return firstIndex;
    }
};

int main(int argc, char const *argv[])
{
    int A[] = {1,1,1,2,2,3};
    Solution sol;
    int l =sol.removeDuplicates(A,6);
    cout<< l <<endl;
    for(int i=0;i<l;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}