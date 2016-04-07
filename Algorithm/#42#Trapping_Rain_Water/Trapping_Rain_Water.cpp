#include <iostream>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int trap(int A[], int n) 
    {
        int leftMax = 0;
        int left[n]; 
        for(int i=0;i<n;i++)
        {
            left[i] = leftMax;
            if(A[i] > leftMax)
                leftMax = A[i];
        }

        int rightMax = 0;
        int right[n]; 
        for(int i=n-1;i>=0;i--)
        {
            right[i] = rightMax;
            if(A[i] > rightMax)
                rightMax = A[i];
        }

        int result = 0;
        int temp;
        for(int i=0;i<n;i++)
        {
            temp = min(left[i],right[i]);
            if(temp > A[i])
                result += temp-A[i];
        }
        return result;
    }
};

int main()
{
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    cout<<sol.trap(A,sizeof(A)/sizeof(int))<<endl;
    return 0;
}