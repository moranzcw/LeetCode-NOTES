class Solution 
{
public:
    int countPrimes(int n) 
    {
        vector<bool> flag(n,true);
        flag[0]=false;
        if(n<2)
            return 0;
        flag[1]=false;
        int count = 0;
        for(int i=2;i<n;i++)
        {
            if(flag[i])
            {
                count ++;
                for(int j=2;j*i<n;j++)
                    flag[j*i] = false;
            }
        }
        return count;
    }
};