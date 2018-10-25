class Solution 
{
public:
    int maxRotateFunction(vector<int>& A) 
    {
        int n = A.size();
        if(n<=0)
            return 0;
        vector<int> F(n,0);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            F[0] += i*A[i];
            sum += A[i];
        }
        int max = F[0];
        for(int i=1;i<n;i++)
        {
            F[i] = F[i-1] + sum - A[n-i] - (n-1)*A[n-i];
            if(F[i] > max)
                max = F[i];
        }
        return max;
    }
};