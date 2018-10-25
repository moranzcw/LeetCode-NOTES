class Solution 
{
public:
    int maxProduct(int A[], int n) 
    {
        if(n==0) 
            return 0;
        if(n==1) 
            return A[0];
        int curMax = A[0];
        int curMin = A[0];
        int ans = A[0];
        for(int i=1;i<n;i++)
        {
            int temp = curMin *A[i];
            curMin = min(A[i], min(temp, curMax*A[i]));
            curMax = max(A[i], max(temp, curMax*A[i]));
            ans = max(ans, curMax);
        }
        return ans;
    }
};