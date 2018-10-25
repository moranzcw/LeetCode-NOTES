class Solution 
{
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        int offset = 0;
        while (m && n)
        {
            if (m == n)
            {
                return m << offset;
            }
            m >>= 1;
            n >>= 1;
            offset++;
        }
        return 0;
    }
};