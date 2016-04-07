#include <iostream>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    double findKth(int A[], int m, int B[], int n, int k)
    {
        if(m > n)
            return findKth(B,n,A,m,k);
        if(m == 0)
            return B[k-1];
        if(k == 1)
            return min(A[0],B[0]);
        
        int pa = min(m,k/2);
        int pb = k - pa;
        if(A[pa-1] < B[pb-1])
            return findKth(A+pa,m-pa,B,n,k-pa);  
        else if(A[pa-1] > B[pb-1])  
            return findKth(A,m,B+pb,n-pb,k-pb);  
        else  
            return A[pa-1];
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
        int k = m+n;
        if( k & 0x1 )
            return findKth(A,m,B,n,k/2+1);
        else  
            return (findKth(A,m,B,n,k/2)+findKth(A,m,B,n,k/2+1))/2;
    }
};

int main()
{
    Solution sol;
    int A[] = {1,2,3,5,6};
    int B[] = {4};
    cout << sol.findMedianSortedArrays(A,5,B,1) << endl;
    return 0;
}