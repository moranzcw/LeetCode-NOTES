class Solution 
{
public:
    bool canJump(int A[], int n) 
    {
        int max = 0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>max)
                max = A[i];
            if(max == 0 && i != n-1)
                return false;
            max--;
        }
        return true;
    }
};