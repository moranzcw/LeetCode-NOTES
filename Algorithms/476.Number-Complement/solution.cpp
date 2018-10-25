class Solution 
{
public:
    int findComplement(int num) 
    {
        int result = ~num;
        int count = 0;
        while(num>0)
        {
            num>>=1;
            count++;
        }
        return result ^ (INT_MAX<<count);
    }
};