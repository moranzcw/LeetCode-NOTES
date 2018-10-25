class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        if(!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend > 0) ^ (divisor > 0))? -1:1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long result = 0;
        long long tempDivisor;
        int base;
        while(dvd >= dvs)
        {
            tempDivisor = dvs;
            base = 1;
            while( (dvd>>1) >= tempDivisor )
            {
                tempDivisor <<= 1;
                base <<= 1;
            }
            dvd -= tempDivisor;
            result += base;
        }
        return sign>0? result:-result;
    }
};