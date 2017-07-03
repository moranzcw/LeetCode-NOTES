# 29. Divide Two Integers

## 描述
计算两个整数相除，而不使用乘法，除法和mod运算符。

如果溢出，返回MAX_INT。

## 解析
为防止溢出问题，可以放置到long long int型变里运算。
用一个变量记录最终结果的正负性，然后取除数和被除数的绝对值，在正数中运算。
用一个临时除数，使初始值等于除数。使用二分法思想，临时除数不断左移1位（乘以2），逼近被除数，直到超过被除数一半，这时记录下临时除数变大的倍数，并累计进结果中。然后用被除数减去除数，得到的值作为新的被除数。循环这一步，直到被除数比除数小。
结果加上正负符号，完成计算。

- 时间复杂度：O( (log(n))² )  
- 空间复杂度：O(1)
- 语言：C++

```C++
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
```

