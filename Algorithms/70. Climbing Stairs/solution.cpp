class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;

        int sum[n];
        sum[0] = 1;
        sum[1] = 2;
        for(int i=2;i<n;i++)
        {
            sum[i] = sum[i-1]+sum[i-2];
        }
        return sum[n-1];
    }
};