class Solution 
{
public:
    int numTrees(int n) 
    {
        if(n<=0)
            return 0;
        vector<int> res(n+1);
        res[0] = 1;
        res[1] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                res[i] += res[j]*res[i-j-1];
            }
        }
        return res[n];
    }
};