#include <iostream>
using namespace std;

class Solution 
{
public:
    void merge(int A[], int m, int B[], int n) 
    {
        int i=0,j=0;
        int k=0;
        int C[m+n+1];
        while(i<m && j<n)
        {
            if(A[i]<B[j]) C[k++]=A[i++];
            else C[k++]=B[j++];
        }
        while(i<m) C[k++]=A[i++];
        while(j<n) C[k++]=B[j++];
        for(i=0;i<k;i++) A[i]=C[i];
    }
};

int main()
{
    int A[10] = {1,3,5,7,9};
    int B[5] = {2,4,6,8,10};
    Solution sol;
    sol.merge(A,5,B,5);
    for(int i =0;i<10;i++)
        cout<<A[i]<<" ";
    cout << endl;
    return 0;
}